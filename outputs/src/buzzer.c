#include <outputs/include/buzzer.h>


QueueHandle_t Queue_Sound;

/**
 * Initializes buzzer
 *
 * Configures buzzer and TimerA to generate tones
 * To play sound, call tasks
 */
void initialize_buzzer(void) {
    // Set as output
    P2->DIR |= BIT7;
    // Set mode to give TIMER_A control
    P2->SEL0 |= BIT7;
    P2->SEL1 &= ~BIT7;
}

/**
 * Sets clock and starts playing tone of specified period
 *
 * Ticks = 24000000 / freq
 */
void play_note(uint32_t note_frequency) {
    // PWM output strength corrections based on buzzer acoustic properties
    float attenuatingFactor = 0.2;
    if (note_frequency > 2300) {
        attenuatingFactor = 0.1;
    } else if (note_frequency == Bb6) {
        attenuatingFactor = 0.5;
    } else if (note_frequency == Gb6) {
        attenuatingFactor = 0.04;
    }


    uint32_t note_period_ticks = SystemCoreClock / note_frequency;

    // Turn off timer
    TIMER_A0->CTL = 0;

    // Set TimerA Period
    TIMER_A0->CCR[0] = note_period_ticks - 1;

    // Duty cycle with attenuation modifier
    TIMER_A0->CCR[4] = ((float)note_period_ticks * attenuatingFactor) - 1;

    // Reset/Set mode
    TIMER_A0->CCTL[4] = TIMER_A_CCTLN_OUTMOD_7;

    // Use master clock as timer
    TIMER_A0->CTL = TIMER_A_CTL_SSEL__SMCLK;

    // Clear any residual count and turn on timer in up mode
    TIMER_A0->CTL |= TIMER_A_CTL_MC__UP | TIMER_A_CTL_CLR;
}

/**
 * Turns off buzzer
 */
void turn_off(void) {
    // Turn off timer
    TIMER_A0->CTL &= ~TIMER_A_CTL_MC_MASK;
}


void Task_playSong(void *pvParameters) {
    int i, songSel, trackSel;
    char curTrack;
    uint16_t lastNote, curNote;
    uint16_t curTrackIndexes[MAX_TRACKS];
    uint16_t trackNoteDurations[MAX_TRACKS];
    uint32_t totalSongLength, progressUpdateInterval, curProgress;

    initialize_buzzer();
    lcd_draw_progress(1, 0);

    while (1) {
        // Wait for buzzer prompt from UI
        // negative value indicates stop playing
        // positive value in range will play that song
        // other values will do nothing
        xQueueReceive(Queue_Sound, &songSel, portMAX_DELAY);

songInterrupt:
        // Extract track to play and which song from command
        trackSel = songSel >> TRACK_OFFSET;
        songSel = songSel & 0xFF;

        // If song is valid, load it from storage and trigger duet device if present to also start setup
        if (songSel < 0 || songSel >= TOTAL_SONGS) continue;
        Song_Data curSong = songs[songSel];
        set_pin(1);
        lcd_draw_progress(1, 0);

        // Find the length of the song for playing and updating progress bar
        TickType_t noteInterval = 2500 / curSong.tempo; // Quarter note is 24 units, adjustment for tempo is 1000(ms) / 60 (since tempo in bpm) / 24 (quarter note) = 2500
        totalSongLength = 0;
        for (i = 0; i < curSong.length[0]; i++) {
            totalSongLength += curSong.durations[0][i];
        }
        totalSongLength *= noteInterval;
        progressUpdateInterval = totalSongLength / 100;

        // Reset tracking variables for playing
        curProgress = 0;
        // If trackSel is equal to total number of tracks, rotate. Else will play only that track
        curTrack = (trackSel > curSong.tracks) ? 0 : trackSel - 1;
        memset(curTrackIndexes, 0, MAX_TRACKS * sizeof(uint16_t));
        memset(trackNoteDurations, 0, MAX_TRACKS * sizeof(uint16_t));

        // Loop plays through song at 1ms update intervals, rotating through tracks
        for (i = 0; i < totalSongLength; i += SWITCHING_INTERVAL) {

            // For current note on track, see how long it should be played
            uint32_t curNoteLength = curSong.durations[curTrack][curTrackIndexes[curTrack]] * noteInterval;

            // If it has been played for proper duration, move to next note
            if (trackNoteDurations[curTrack] >= curNoteLength) {
                turn_off();
                lastNote = 0;
                trackNoteDurations[curTrack] -= curNoteLength;
                curTrackIndexes[curTrack] += 1;
            }

            // If next note differs from last one, update PWM output
            curNote = curSong.notes[curTrack][curTrackIndexes[curTrack]];
            if (curNote != lastNote) {
                if (curNote == 0) {
                    turn_off();
                } else {
                    play_note(curNote);
                }
            }

            // Update song progress for track and progress bar
            curProgress += SWITCHING_INTERVAL;
            if (curProgress >= progressUpdateInterval) {
                lcd_draw_progress(0, 1);
                curProgress -= progressUpdateInterval;
            }


            // Move to next track for next loop if rotate mode
            if (trackSel > curSong.tracks) {
                curTrack = (curTrack + 1) % curSong.tracks;
                trackNoteDurations[curTrack] += curSong.tracks * SWITCHING_INTERVAL;
            } else {
                trackNoteDurations[curTrack] += SWITCHING_INTERVAL;
            }
            lastNote = curNote;

            // Let note play. If new command comes in, stop and run next
            if (xQueueReceive(Queue_Sound, &songSel, pdMS_TO_TICKS(SWITCHING_INTERVAL)) == pdTRUE) {
                turn_off();
                set_pin(0);
                goto songInterrupt;
            }
        }

        turn_off();
        set_pin(0);
    }
}
