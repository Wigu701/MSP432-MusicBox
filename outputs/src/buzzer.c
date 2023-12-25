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
void play_note(uint32_t note_period_ticks) {
    // Turn off timer
    TIMER_A0->CTL = 0;

    // Set TimerA Period
    TIMER_A0->CCR[0] = note_period_ticks - 1;

    // 50% duty cycle
    TIMER_A0->CCR[4] = (note_period_ticks / 2) - 1;

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

void playSong(int songNum) {
//    uint16_t* notes = songNotes[songNum];
//    uint8_t* times = songTimes[songNum];
//    size_t length = notes[0];
//    TickType_t noteInterval = 20000 / (times[0] << 3);
//    set_pin(0);
//    int i;
//    for (i = 1; i < length; i++) {
//        if (notes[i] == 0) {
//            turn_off();
//            vTaskDelay(pdMS_TO_TICKS(times[i] * noteInterval));
//        } else {
//            play_note(SystemCoreClock / notes[i]);
//            vTaskDelay(pdMS_TO_TICKS(times[i] * noteInterval));
//        }
//    }
//    turn_off();
}

void Task_playSong(void *pvParameters) {
    int i;
    char curTrack;
    uint16_t lastNote;
    uint16_t curTrackIndexes[MAX_TRACKS];
    uint8_t trackNoteDurations[MAX_TRACKS];
    initialize_buzzer();
    char songSel;

    lcd_draw_progress(1, 0);

    while (1) {
        // Wait for prompt to play song. change type to char
        // If in range and no song playing, start playing song
        // If multi track, switch between each at some interval
        // If not multi track, have delays be that of single track instead
        // While waiting for each note/interval, check if new command in queue for stop/play other song
        // Will have stop be -1, play other song just be new number
        // issue progress bar updates periodically

        // Else print error message

        // Wait for buzzer prompt from UI
        // negative value indicates stop playing
        // positive value in range will play that song
        // other values will do nothing
        xQueueReceive(Queue_Sound, &songSel, portMAX_DELAY);

songInterrupt:
        if (songSel < 0 || songSel >= TOTAL_SONGS) continue;
        Song_Data* curSong = songs + songSel;
        set_pin(1);

        uint32_t totalSongLength = 0;
        for (i = 0; i < curSong->length[0]; i++) {
            totalSongLength += curSong->durations[0][i];
        }
        uint32_t progressUpdateInterval = totalSongLength / 100;

        curTrack = 0;
        memset(curTrackIndexes, 0, MAX_TRACKS * sizeof(uint16_t));
        TickType_t noteInterval = 2500 / curSong->tempo;
        for (i = 0; i < totalSongLength; i++) {
            if (trackNoteDurations[curTrack] >= curSong->durations[curTrack][curTrackIndexes[curTrack]]) {
                trackNoteDurations[curTrack] -= curSong->durations[curTrack][curTrackIndexes[curTrack]];
                curTrackIndexes[curTrack] += 1;
            }
            curNote = curSong->notes[curTrack][curTrackIndexes[curTrack]];
            if (curNote != lastNote) {
                if (curNote == 0) {
                    turn_off();
                } else {
                    play_note(SystemCoreClock / notes[i]);
                }
            }

            trackNoteDurations[curTrack] += curSong->tracks;
            curTrack = (curTrack + 1) % curSong->tracks;
            lastNote = curNote;

            // Check if any new commands while note playing. If yes, stop and process
            if (xQueueReceive(Queue_Sound, &songSel, pdMS_TO_TICKS(1)) == pdTRUE) {
                turn_off();
                set_pin(0);
                goto songInterrupt;
            }
        }

        turn_off();
        set_pin(0);
    }
}
