#include <stdbool.h>
#include <task_buzzer.h>

QueueHandle_t Queue_Sound;
extern volatile int totalSongs = 4;

#define Q 8
#define E 4
#define DQ 12
#define H 16
#define S 2
#define T 5

#define C5 523
#define D5 587
#define E5 659
#define Gb5 740
#define G5 784
#define Ab5 831
#define A5 880
#define Bb5 932
#define B5 988
#define C6 1047
#define Db6 1109
#define D6 1175
#define E6 1319
#define F6 1397
#define Fs6 1480
#define G6 1568
#define A6 1760
#define C7 2093
#define D7 2349
#define E7 2637

// Mario Death
uint16_t Death_Notes[13] = {13, C6, 0, G5, 0, E5, A5, B5, A5, Ab5, Bb5, Ab5, G5};
uint8_t Death_Times[13] = {110, E, E, E, E, Q, T, T, T, Q, Q, Q, 3*Q};

// Here Comes the Sun
uint16_t HCTS_Notes[33] = {33, Db6, A5, B5, Db6, A5, Db6, B5, A5, Gb5, A5, B5, A5, Gb5, Ab5, Gb5, Ab5, A5, B5, 0, Db6, A5, B5, Db6, A5, Db6, B5, A5, Gb5, Db6, B5, A5, Ab5};
uint8_t HCTS_Times[33] = {110, E, E, E, Q, DQ, E, Q, Q, Q, Q, Q, Q, E, E, E, E, Q, DQ, Q, E, E, E, Q, DQ, E, Q, Q, Q, Q, Q, Q, H};

// Bach Fugue in G Minor
uint16_t FGM_Notes[51] = {51, G5, D6, Bb5, A5, G5, Bb5, A5, G5, Gb5, A5, D5, G5, D5, A5, D5, Bb5, A5, G5, A5, D5, G5, D5, G5, A5, D5, A5, Bb5, A5, G5, A5, D5, D6, C6, Bb5, A5, G5, Bb5, A5, G5, Gb5, A5, G5, D5, G5, A5, Bb5, C6, D6, E6, D6};
uint8_t FGM_Times[51] = {100, Q, Q, DQ, E, E, E, E, E, E, E, Q, E, E, E, E, E, S, S, E, E, E, S, S, E, S, S, E, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, DQ};

// BrodyQuest
uint16_t BQ_Notes[171] = {171, C6, C6, C6, A5, G5, C6, E6, F6, Fs6, G6, C6, C6, C6, A5, G5, C6, E6, F6, Fs6, G6, A6, A6, A6, G6, E6, F6, F6, G6, A6, C7, C6, C6, C6, A5, G5, C6, // Chorus
                         G6, A6, C7, D7, E7, C7, G6, 0, G6, A6, G6, F6, E6, 0, F6, E6, D6, C6, 0, C6, D6, E6, D6, C6, A5, C6, E6, 0, F6, E6, D6, D6, E6, C6, A5, G5, E5, D5, C5, D5, E5, 0, // Bridge
                         G5, A5, C6, C6, D6, F6, E6, D6, C6, G6, E6, A6, G6, C7, A6, C7, D7, E7, 0, E7, D7, C7, D7, E7, C7, A6, G6, A6, C7, E6, G6, E6, D6, C6, C6, D6, E6, D6, C6, 0,
                         E5, E5, D5, E5, E6, A6, G6, G6, A6, G6, E6, D6, E6, D6, C6, C6, 0, C6, B5, C6, 0, C6, A5, G5, C5, A5, G5, E5, A5, G5, E5, G5, A5, C6, D6, C6, A5, E5, G5, A5, G5, E5, G5, A5, G5, E5, 0, D5, C5, D5, E5};
uint8_t BQ_Times[171] = {200, Q, Q, Q, E, E, DQ, Q, E, E, E, Q, Q, Q, E, E, DQ, Q, E, E, E, Q, Q, Q, E, E, DQ, Q, E, E, E, Q, Q, Q, E, E, E,
                         E, E, Q, Q, Q, Q, 2*Q, Q, E, E, E, E, E, E, Q, Q, Q, DQ + S, S, E, E, E, E, Q, Q, Q, Q, E, DQ, E, Q, E, Q, DQ, E, DQ, E, Q, Q, E, Q, S, Q, E, Q, E, E, Q, Q, E, Q, Q, Q, Q, Q, Q, E, E, E, E + S, S,
                         Q, E, E, E, Q, Q, E, Q, Q, Q, Q, E, Q, Q, Q, Q, E, Q, E, Q, E, Q, Q, Q, S, S, DQ, E, Q, E, E, Q, Q, Q, E, Q, Q + S, S, Q, Q, Q, E, E, E, E, E, E, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, H, E, 2*Q, Q, E, E, E, Q};

uint16_t* songNotes[] = {Death_Notes, HCTS_Notes, FGM_Notes, BQ_Notes};
uint8_t* songTimes[] = {Death_Times, HCTS_Times, FGM_Times, BQ_Times};

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
    uint16_t* notes = songNotes[songNum];
    uint8_t* times = songTimes[songNum];
    size_t length = notes[0];
    TickType_t noteInterval = 60000 / (times[0] << 3);

    int i;
    for (i = 1; i < length; i++) {
        if (notes[i] == 0) {
            turn_off();
            vTaskDelay(pdMS_TO_TICKS(times[i] * noteInterval));
        } else {
            play_note(24000000 / notes[i]);
            vTaskDelay(pdMS_TO_TICKS(times[i] * noteInterval));
        }
    }
    turn_off();
}

/**
 * Task plays sound based on boolean given in queue
 * true = ping, false = death jingle
 */
void Task_playSound(void *pvParameters) {
    initialize_buzzer();
    int songSel;

    while (1) {
        xQueueReceive(Queue_Sound, &songSel, portMAX_DELAY);

        if (songSel < totalSongs) {
            playSong(songSel);
        }
    }
}
