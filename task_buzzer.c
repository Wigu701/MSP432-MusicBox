#include <stdbool.h>
#include <task_buzzer.h>

QueueHandle_t Queue_Sound;
extern volatile int totalSongs = 3;

#define Q 300
#define E 150
#define DQ 450
#define H 600
#define S 75
#define T 200

#define C5 523
#define D5 587
#define E5 659
#define G5 784
#define Ab5 831
#define A5 880
#define Bb5 932
#define B5 988
#define C6 1047
#define D6 1175
#define E6 1319
#define F6 1397
#define Fs6 1480
#define G6 1568
#define A6 1760
#define C7 2093
#define D7 2349
#define E7 2637

uint16_t Death_Notes[13] = {C6, 0, G5, 0, E5, A5, B5, A5, Ab5, Bb5, Ab5, G5};
uint16_t Death_Time[13] = {E, E, E, E, Q, T, T, T, Q, Q, Q, 3*Q};

uint8_t Fun_VLengths[6] = {19, 23, 20, 21, 20, 31};
uint16_t Fun_Chorus1[10] = {C6, C6, C6, A5, G5, C6, E6, F6, Fs6, G6};
uint16_t Fun_Chorus2[10] = {A6, A6, A6, G6, E6, F6, F6, G6, A6, C7};
uint16_t Fun_CTime[10] = {Q, Q, Q, E, E, DQ, Q, E, E, E};

uint16_t Fun_Verse1[19] = {G6, A6, C7, D7, E7, C7, G6, 0, G6, A6, G6, F6, E6, 0, F6, E6, D6, C6, 0};
uint16_t Fun_VTime1[19] = {E, E, Q, Q, Q, Q, 2*Q, Q, E, E, E, E, E, E, Q, Q, Q, DQ + S, S};
uint16_t Fun_Verse2[23] = {C6, D6, E6, D6, C6, A5, C6, E6, 0, F6, E6, D6, D6, E6, C6, A5, G5, E5, D5, C5, D5, E5, 0};
uint16_t Fun_VTime2[23] = {E, E, E, E, Q, Q, Q, Q, E, DQ, E, Q, E, Q, DQ, E, DQ, E, Q, Q, E, Q, S};
uint16_t Fun_Verse3[20] = {G5, A5, C6, C6, D6, F6, E6, D6, C6, G6, E6, A6, G6, C7, A6, C7, D7, E7, 0};
uint16_t Fun_VTime3[20] = {Q, E, Q, E, E, Q, Q, E, Q, Q, Q, Q, Q, Q, E, E, E, E + S, S};
uint16_t Fun_Verse4[21] = {E7, D7, C7, D7, E7, C7, A6, G6, A6, C7, E6, G6, E6, D6, C6, C6, D6, E6, D6, C6, 0};
uint16_t Fun_VTime4[21] = {Q, E, E, E, Q, Q, E, Q, Q, Q, Q, E, Q, Q, Q, Q, E, Q, E, Q, E};
uint16_t Fun_Verse5[20] = {E5, E5, D5, E5, E6, A6, G6, G6, A6, G6, E6, D6, E6, D6, C6, C6, 0, C6, B5, C6};
uint16_t Fun_VTime5[20] = {Q, Q, Q, S, S, DQ, E, Q, E, E, Q, Q, Q, E, Q, Q + S, S, Q, Q, Q};
uint16_t Fun_Verse6[31] = {0, C6, A5, G5, C5, A5, G5, E5, A5, G5, E5, G5, A5, C6, D6, C6, A5, E5, G5, A5, G5, E5, G5, A5, G5, E5, 0, D5, C5, D5, E5};
uint16_t Fun_VTime6[31] = {E, E, E, E, E, E, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, H, E, 2*Q, Q, E, E, E, Q};


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

/**
 * Plays ping noise indicating new action
 */
void playPing(void) {
    play_note(12000);
    vTaskDelay(pdMS_TO_TICKS(100));
    turn_off();
}

/**
 * Plays death jingle
 */
void playDeath(void) {
    int i = 0;

    for (i = 0; i < 12; i++) {
        if (Death_Notes[i] == 0) {
            turn_off();
            vTaskDelay(pdMS_TO_TICKS(Death_Time[i] * 2));
        } else {
            play_note(24000000 / Death_Notes[i]);
            vTaskDelay(pdMS_TO_TICKS(Death_Time[i] * 2));
        }
    }
    turn_off();
}

void playChorus(void) {
    int i = 0;
    int j = 0;

    for (j = 0; j < 2; j++) {
        for (i = 0; i < 10; i++) {
            if (Fun_Chorus1[i] == 0) {
                turn_off();
                vTaskDelay(pdMS_TO_TICKS(Fun_CTime[i]));
            } else {
                play_note(24000000 / Fun_Chorus1[i]);
                vTaskDelay(pdMS_TO_TICKS(Fun_CTime[i]));
            }
        }
    }

    for (i = 0; i < 10; i++) {
        if (Fun_Chorus2[i] == 0) {
            turn_off();
            vTaskDelay(pdMS_TO_TICKS(Fun_CTime[i]));
        } else {
            play_note(24000000 / Fun_Chorus2[i]);
            vTaskDelay(pdMS_TO_TICKS(Fun_CTime[i]));
        }
    }

    for (i = 0; i < 5; i++) {
        if (Fun_Chorus1[i] == 0) {
            turn_off();
            vTaskDelay(pdMS_TO_TICKS(Fun_CTime[i]));
        } else {
            play_note(24000000 / Fun_Chorus1[i]);
            vTaskDelay(pdMS_TO_TICKS(Fun_CTime[i]));
        }
    }

    play_note(24000000 / Fun_Chorus1[5]);
    vTaskDelay(pdMS_TO_TICKS(Fun_CTime[5] - E));
}

void playVerses() {
    int i = 0;

    for (i = 0; i < Fun_VLengths[0]; i++) {
        if (Fun_Verse1[i] == 0) {
            turn_off();
            vTaskDelay(pdMS_TO_TICKS(Fun_VTime1[i]));
        } else {
            play_note(24000000 / Fun_Verse1[i]);
            vTaskDelay(pdMS_TO_TICKS(Fun_VTime1[i]));
        }
    }

    for (i = 0; i < Fun_VLengths[1]; i++) {
        if (Fun_Verse2[i] == 0) {
            turn_off();
            vTaskDelay(pdMS_TO_TICKS(Fun_VTime2[i]));
        } else {
            play_note(24000000 / Fun_Verse2[i]);
            vTaskDelay(pdMS_TO_TICKS(Fun_VTime2[i]));
        }
    }

    for (i = 0; i < Fun_VLengths[2]; i++) {
        if (Fun_Verse3[i] == 0) {
            turn_off();
            vTaskDelay(pdMS_TO_TICKS(Fun_VTime3[i]));
        } else {
            play_note(24000000 / Fun_Verse3[i]);
            vTaskDelay(pdMS_TO_TICKS(Fun_VTime3[i]));
        }
    }

    for (i = 0; i < Fun_VLengths[3]; i++) {
        if (Fun_Verse4[i] == 0) {
            turn_off();
            vTaskDelay(pdMS_TO_TICKS(Fun_VTime4[i]));
        } else {
            play_note(24000000 / Fun_Verse4[i]);
            vTaskDelay(pdMS_TO_TICKS(Fun_VTime4[i]));
        }
    }

    for (i = 0; i < Fun_VLengths[4]; i++) {
        if (Fun_Verse5[i] == 0) {
            turn_off();
            vTaskDelay(pdMS_TO_TICKS(Fun_VTime5[i]));
        } else {
            play_note(24000000 / Fun_Verse5[i]);
            vTaskDelay(pdMS_TO_TICKS(Fun_VTime5[i]));
        }
    }

    for (i = 0; i < Fun_VLengths[5]; i++) {
        if (Fun_Verse6[i] == 0) {
            turn_off();
            vTaskDelay(pdMS_TO_TICKS(Fun_VTime6[i]));
        } else {
            play_note(24000000 / Fun_Verse6[i]);
            vTaskDelay(pdMS_TO_TICKS(Fun_VTime6[i]));
        }
    }
}

void playFun(void) {
    playChorus();
    playVerses();

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

        switch (songSel) {
            case 0:
                playFun();
                break;
            case 1:
                playDeath();
                break;
            case 2:
                playPing();
                break;
            default:
                break;
        }
    }
}
