#include <task_buzzer.h>

QueueHandle_t Queue_Sound;
const extern int totalSongs = 9;
volatile bool playing;

#define W 96
#define DH 72
#define H 48
#define DQ 36
#define Q 24
#define DE 18
#define T 16
#define E 12
#define ET 8
#define S 6

#define Bb4 466
#define B4 494
#define C5 523
#define Db5 554
#define D5 587
#define Eb5 622
#define E5 659
#define F5 698
#define Gb5 740
#define G5 784
#define Ab5 831
#define A5 880
#define Bb5 932
#define B5 988
#define C6 1047
#define Db6 1109
#define D6 1175
#define Eb6 1245
#define E6 1319
#define F6 1397
#define Gb6 1480
#define G6 1568
#define Ab6 1662
#define A6 1760
#define Bb6 1865
#define C7 2093
#define Db7 2218
#define D7 2349
#define Eb7 2490
#define E7 2637

// Song Format
// Notes[Size] = {ArrayLength, Notes, Notes, Notes ....}
// Times[Size] = {Tempo, Note, Note, Note ....}

// Mario Death
uint16_t Death_Notes[13] = {13, C6, 0, G5, 0, E5, A5, B5, A5, Ab5, Bb5, Ab5, G5};
uint8_t Death_Times[13] = {110, E, E, E, E, Q, T, T, T, Q, Q, Q, 3*Q};

// Here Comes the Sun
uint16_t HCTS_Notes[33] = {33, Db6, A5, B5, Db6, A5, Db6, B5, A5, Gb5, A5, B5, A5, Gb5, Ab5, Gb5, Ab5, A5, B5, 0, Db6, A5, B5, Db6, A5, Db6, B5, A5, Gb5, Db6, B5, A5, Ab5};
uint8_t HCTS_Times[33] = {110, E, E, E, Q, DQ, E, Q, Q, Q, Q, Q, Q, E, E, E, E, Q, DQ, Q, E, E, E, Q, DQ, E, Q, Q, Q, Q, Q, Q, H};

// Bach Fugue in G Minor
uint16_t FGM_Notes[140] = {140, G5, D6, Bb5, A5, G5, Bb5, A5, G5, Gb5, A5, D5, G5, D5, A5, D5, Bb5, A5, G5, A5, D5, G5, D5, G5, A5, D5, A5, Bb5, A5, G5, A5, D5, D6, C6, Bb5, A5, G5, Bb5, A5, G5, Gb5, A5, G5, D5, G5, A5, Bb5, C6, D6, E6,
                          F6, E6, D6, F6, E6, D6, Db6, E6, D6, 0, A5, 0, D6, 0, E6, 0, F6, G6, F6, G6, G6, A6, G6, F6, G6, A6, G6, A6, Bb6, A6, G6, F6, E6, F6, A6, G6, A6, Db6, A6, D6, A6, D6, A6, G6, A6, Db6, A6, G6, A6, F6, D6, Db6, D6, G6, D6, Db6, D6, A6, D6, Db6, D6, G6, D6, Db6, D6,
                          A5, F6, G6, E6, F5, A5, D6, F6, Eb6, A6, 0, Eb6, D6, G6, 0, D6, C6, Bb5, C6, D6, C6, D6, E6, Gb6, G6};
uint8_t FGM_Times[140] = {200, H, H, 24, Q, Q, Q, Q, Q, Q, Q, H, Q, Q, Q, Q, Q, E, E, Q, Q, Q, E, E, Q, E, E, Q, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E,
                         E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, S, S, Q, S, S, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E,
                         Q, Q, Q, Q, Q, Q, Q, Q, Q, Q, Q, Q, Q, Q, Q, Q, E, E, E, E, E, E, E, E, H};

uint16_t FGM2_Notes[73] = {73, 0, 0, G5, D6, Bb5, A5, G5, Bb5, A5, G5, Gb5, A5, D5, G5, D5, A5, D5, Bb5, A5, G5, A5, D5, G5, D5, G5, A5, D5, A5, Bb5, A5, G5, A5, D5, D6, C6, Bb5, A5, G5, Bb5, A5, G5, Gb5, A5, G5, D5, G5, A5, Bb5, C6, D6, E6,
                           F6, E6, F6, G6, F5, E6, D6, F6, E6, D6, E6, F6, E6, D6, C6, E6, D6, C6, B5, G5, C6};
uint8_t FGM2_Times[73] = {200, 160, 160, H, H, 24, Q, Q, Q, Q, Q, Q, Q, H, Q, Q, Q, Q, Q, E, E, Q, Q, Q, E, E, Q, E, E, Q, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E,
                          E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, Q, Q, Q, Q, H};

// BrodyQuest
uint16_t BQ_Notes[171] = {171, C6, C6, C6, A5, G5, C6, E6, F6, Gb6, G6, C6, C6, C6, A5, G5, C6, E6, F6, Gb6, G6, A6, A6, A6, G6, E6, F6, F6, G6, A6, C7, C6, C6, C6, A5, G5, C6, // Chorus
                         G6, A6, C7, D7, E7, C7, G6, 0, G6, A6, G6, F6, E6, 0, F6, E6, D6, C6, 0, C6, D6, E6, D6, C6, A5, C6, E6, 0, F6, E6, D6, D6, E6, C6, A5, G5, E5, D5, C5, D5, E5, 0, // Bridge
                         G5, A5, C6, C6, D6, F6, E6, D6, C6, G6, E6, A6, G6, C7, A6, C7, D7, E7, 0, E7, D7, C7, D7, E7, C7, A6, G6, A6, C7, E6, G6, E6, D6, C6, C6, D6, E6, D6, C6, 0,
                         E5, E5, D5, E5, E6, A6, G6, G6, A6, G6, E6, D6, E6, D6, C6, C6, 0, C6, B5, C6, 0, C6, A5, G5, C5, A5, G5, E5, A5, G5, E5, G5, A5, C6, D6, C6, A5, E5, G5, A5, G5, E5, G5, A5, G5, E5, 0, D5, C5, D5, E5};
uint8_t BQ_Times[171] = {200, Q, Q, Q, E, E, DQ, Q, E, E, E, Q, Q, Q, E, E, DQ, Q, E, E, E, Q, Q, Q, E, E, DQ, Q, E, E, E, Q, Q, Q, E, E, E,
                         E, E, Q, Q, Q, Q, 2*Q, Q, E, E, E, E, E, E, Q, Q, Q, DQ + S, S, E, E, E, E, Q, Q, Q, Q, E, DQ, E, Q, E, Q, DQ, E, DQ, E, Q, Q, E, Q, S, Q, E, Q, E, E, Q, Q, E, Q, Q, Q, Q, Q, Q, E, E, E, E + S, S,
                         Q, E, E, E, Q, Q, E, Q, Q, Q, Q, E, Q, Q, Q, Q, E, Q, E, Q, E, Q, Q, Q, S, S, DQ, E, Q, E, E, Q, Q, Q, E, Q, Q + S, S, Q, Q, Q, E, E, E, E, E, E, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, H, E, 2*Q, Q, E, E, E, Q};

// LoZ Theme
uint16_t LoZ_Notes[83] = {83, Bb5, Bb5, Bb5, Bb5, Bb5, Bb5, Ab5, Bb5, Bb5, Bb5, Bb5, Bb5, Bb5, Ab5, Bb5, Bb5, Bb5, Bb5, Bb5, Bb5, F5, F5, F5, F5, F5, F5, F5, F5, F5, F5,
                          Bb5, F5, Bb5, Bb5, C6, D6, Eb6, F6, 0, F6, F6, Gb6, Ab6, Bb6, 0, Bb6, Bb6, Ab6, Gb6, Ab6, Gb6, F6, 0, F6, Eb6, Eb6, F6, Gb6, F6, Eb6, Db6, Db6, Eb6, F6, Eb6, Db6,
                          C6, C6, D6, E6, G6, F6, F5, F5, F5, F5, F5, F5, F5, F5, F5, F5};
uint8_t LoZ_Times[83] = {130, H+DE, S, ET, ET, ET, 2*ET, ET, Q+DE, S, ET, ET, ET, 2*ET, ET, Q+DE, S, ET, ET, ET, E, S, S, E, S, S, E, S, S, E, E,
                          Q, DQ, E, S, S, S, S, H, E, E, ET, ET, ET, H, E, E, ET, ET, ET, DE, S, DQ, E, Q, E, S, S, H, E, E, E, S, S, H, E, E,
                          E, S, S, H, Q, E, S, S, E, S, S, E, S, S, E, E};

uint16_t LoZ2_Notes[85] = {85, Bb5, Bb5, Bb5, Bb5, Bb5, Bb5, Bb5, Bb5, Ab5, Ab5, Ab5, Ab5, Ab5, Ab5, Ab5, Ab5, Gb5, Gb5, Gb5, Gb5, Gb5, Gb5, Gb5, Gb5, F5, F5, F5, G5, A5,
                           Bb5, Bb5, Bb5, Ab5, Bb5, Bb5, Ab5, Ab5, Ab5, Gb5, Ab5, Ab5, Gb5, Gb5, Gb5, E5, Gb5, Gb5, Db6, Db6, Db6, B5, Db6, Db6,
                           B5, B5, B5, Bb5, B5, B5, B5, B5, Bb5, Bb5, Bb5, Ab5, Bb5, Bb5, Bb5, Bb5, C6, C6, C6, C6, C6, C6, C6, C6, F5, F5, F5, F5, F5, G5, A5};
uint8_t LoZ2_Times[85] = {130, Q, ET, ET, ET, Q, ET, ET, ET, Q, ET, ET, ET, Q, ET, ET, ET, Q, ET, ET, ET, Q, ET, ET, ET, Q, Q, Q, E, E, Q, ET, ET, ET, Q, Q, Q, ET, ET, ET, Q, Q,
                          Q, ET, ET, ET, Q, Q, Q, ET, ET, ET, Q, Q, Q, ET, ET, ET, Q, ET, ET, ET, Q, ET, ET, ET, Q, ET, ET, ET, Q, ET, ET, ET, Q, ET, ET, ET, Q, ET, ET, ET, Q, E, E};

uint16_t Mega_Notes[209] = {209, D5, D5, D6, A5, 0, Ab5, 0, G5, 0, F5, D5, F5, G5, C5, C5, D6, A5, 0, Ab5, 0, G5, 0, F5, D5, F5, G5,
                           B4, B4, D6, A5, 0, Ab5, 0, G5, 0, F5, D5, F5, G5, Bb4, Bb4, D6, A5, 0, Ab5, 0, G5, 0, F5, D5, F5, G5,
                           D5, D5, D6, A5, 0, Ab5, 0, G5, 0, F5, D5, F5, G5, C5, C5, D6, A5, 0, Ab5, 0, G5, 0, F5, D5, F5, G5,
                           B4, B4, D6, A5, 0, Ab5, 0, G5, 0, F5, D5, F5, G5, Bb4, Bb4, D6, A5, 0, Ab5, 0, G5, 0, F5, D5, F5, G5,
                           D6, D6, D7, A6, 0, Ab6, 0, G6, 0, F6, D6, F6, G6, C6, C6, D7, A6, 0, Ab6, 0, G6, 0, F6, D6, F6, G6,
                           B5, B5, D7, A6, 0, Ab6, 0, G6, 0, F6, D6, F6, G6, Bb5, Bb5, D7, A6, 0, Ab6, 0, G6, 0, F6, D6, F6, G6,
                           D6, D6, D7, A6, 0, Ab6, 0, G6, 0, F6, D6, F6, G6, C6, C6, D7, A6, 0, Ab6, 0, G6, 0, F6, D6, F6, G6,
                           B5, B5, D7, A6, 0, Ab6, 0, G6, 0, F6, D6, F6, G6, Bb5, Bb5, D7, A6, 0, Ab6, 0, G6, 0, F6, D6, F6, G6};

uint8_t Mega_Times[209] = {120, S, S, E, E, S, S, S, S, S, E, S, S, S, S, S, E, E, S, S, S, S, S, E, S, S, S,
                          S, S, E, E, S, S, S, S, S, E, S, S, S, S, S, E, E, S, S, S, S, S, E, S, S, S,
                          S, S, E, E, S, S, S, S, S, E, S, S, S, S, S, E, E, S, S, S, S, S, E, S, S, S,
                          S, S, E, E, S, S, S, S, S, E, S, S, S, S, S, E, E, S, S, S, S, S, E, S, S, S,
                          S, S, E, E, S, S, S, S, S, E, S, S, S, S, S, E, E, S, S, S, S, S, E, S, S, S,
                          S, S, E, E, S, S, S, S, S, E, S, S, S, S, S, E, E, S, S, S, S, S, E, S, S, S,
                          S, S, E, E, S, S, S, S, S, E, S, S, S, S, S, E, E, S, S, S, S, S, E, S, S, S,
                          S, S, E, E, S, S, S, S, S, E, S, S, S, S, S, E, E, S, S, S, S, S, E, S, S, S};

uint16_t Mega2_Notes[161] = {161, 0, 0, 0, 0,
                             D5, D5, D5, D5, 0, D5, 0, D5, 0, D5, D5, D5, D5, C5, C5, C5, C5, 0, C5, 0, C5, 0, C5, C5, C5, C5,
                             B4, B4, B4, B4, 0, B4, 0, B4, 0, B4, B4, B4, B4, Bb4, Bb4, Bb4, Bb4, 0, C5, 0, C5, 0, C5, C5, C5, C5,
                             D5, D5, D5, D5, 0, D5, 0, D5, 0, D5, D5, D5, D5, C5, C5, C5, C5, 0, C5, 0, C5, 0, C5, C5, C5, C5,
                             B4, B4, B4, B4, 0, B4, 0, B4, 0, B4, B4, B4, B4, Bb4, Bb4, Bb4, Bb4, 0, C5, 0, C5, 0, C5, C5, C5, C5,
                             D5, D5, D5, D5, 0, D5, 0, D5, 0, D5, D5, D5, D5, C5, C5, C5, C5, 0, C5, 0, C5, 0, C5, C5, C5, C5,
                             B4, B4, B4, B4, 0, B4, 0, B4, 0, B4, B4, B4, B4, Bb4, Bb4, Bb4, Bb4, 0, C5, 0, C5, 0, C5, C5, C5, C5};

uint8_t Mega2_Times[161] = {120, W, W, W, W,
                            E, E, S, S, S, S, S, S, S, S, S, S, E, E, E, S, S, S, S, S, S, S, S, S, S, E,
                            E, E, S, S, S, S, S, S, S, S, S, S, E, E, E, S, S, S, S, S, S, S, S, S, S, E,
                            E, E, S, S, S, S, S, S, S, S, S, S, E, E, E, S, S, S, S, S, S, S, S, S, S, E,
                            E, E, S, S, S, S, S, S, S, S, S, S, E, E, E, S, S, S, S, S, S, S, S, S, S, E,
                            E, E, S, S, S, S, S, S, S, S, S, S, E, E, E, S, S, S, S, S, S, S, S, S, S, E,
                            E, E, S, S, S, S, S, S, S, S, S, S, E, E, E, S, S, S, S, S, S, S, S, S, S, E};


uint16_t* songNotes[] = {Death_Notes, HCTS_Notes, FGM_Notes, FGM2_Notes, BQ_Notes, LoZ_Notes, LoZ2_Notes, Mega_Notes, Mega2_Notes};
uint8_t* songTimes[] = {Death_Times, HCTS_Times, FGM_Times, FGM2_Times, BQ_Times, LoZ_Times, LoZ2_Times, Mega_Times, Mega2_Times};


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
    TickType_t noteInterval = 20000 / (times[0] << 3);
    set_pin(0);
    int i;
    for (i = 1; i < length; i++) {
        if (notes[i] == 0) {
            turn_off();
            vTaskDelay(pdMS_TO_TICKS(times[i] * noteInterval));
        } else {
            play_note(SystemCoreClock / notes[i]);
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
            playing = true;
            playSong(songSel);
            playing = false;
        }

    }
}
