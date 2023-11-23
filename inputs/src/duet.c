#include <inputs/include/duet.h>


TaskHandle_t Task_Duet_Handle = NULL;


/**
 * Initializes duet pins
 *
 * P1.0: Input Pin on Bank J4
 * P2.0: Output Pin on Bank J1
 */
void initialize_pins() {
    // Set directions, select GPIO
    P1->DIR &= ~BIT0;
    P2->DIR |= BIT0;
    P1->SEL0 &= ~BIT0;
    P1->SEL1 &= ~BIT0;
    P2->SEL0 &= ~BIT0;
    P2->SEL1 &= ~BIT0;

    // Pull down resistor for input
    //P6->OUT &= ~BIT5;
    //P6->REN |= BIT5;
}


/**
 * Detects if input pin is asserted
 */
bool detect_pin() {
    return P1->IN & BIT0;
}


/**
 * Sets output pin to value
 */
void set_pin(char on) {
    if (on) {
        P2->OUT |= BIT0;
    } else {
        P2->OUT &= ~BIT0;
    }
}


/**
 * Send message to queue if input pin is high
 * Initializes pins at startup
 */
void Task_duet(void *pvParameters) {
    initialize_pins();
    set_pin(0);

    // Stores information about action for queue
    MESSAGE_t msg;
    msg.action = DUET;

    // Track old reading to send update on change
    uint8_t old = detect_pin();

    while(1)
    {
        if (detect_pin() && !old) {
            old = 1;
            msg.direction = UP;
            xQueueSendToBack(Queue_MusicPlayer_Driver, &msg, portMAX_DELAY);

        } else if (!detect_pin() && old) {
            old = 0;
            msg.direction = DOWN;
            xQueueSendToBack(Queue_MusicPlayer_Driver, &msg, portMAX_DELAY);

        }

        vTaskDelay(pdMS_TO_TICKS(1));
    }
}

