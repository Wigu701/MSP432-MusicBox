#include "task_duet.h"
#include <stdbool.h>


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
    msg.action = IO;

    while(1)
    {
        if (detect_pin()) {
            // Send thing into queue
            xQueueSendToBack(Queue_LCD_Driver, &msg, portMAX_DELAY);
        }
        vTaskDelay(pdMS_TO_TICKS(1));
    }
}

