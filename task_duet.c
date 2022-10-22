#include "task_duet.h"
#include <stdbool.h>


TaskHandle_t Task_Duet_Handle = NULL;

/**
 * Initializes duet pins
 *
 * P2.3: Input Pin on Bank J4
 * P4.6: Output Pin on Bank J1
 */
void initialize_pins() {
    P2->DIR &= ~BIT3;
    P4->DIR |= BIT6;
}

/**
 * Detects if input pin is asserted
 */
bool detect_pin() {
    return (P2->IN & BIT3) == 8;
}


/**
 * Send message to queue if input pin is high
 * Initializes pins at startup
 */
void Task_duet(void *pvParameters) {
    initialize_pins();
    P4->OUT &= ~BIT6;

    // Stores information about action for queue
    MESSAGE_t msg;
    msg.action = CLICK;

    while(1)
    {
        // If pos edge, send message to queue
        if (detect_pin()) {
            // Send thing into queue
            xQueueSendToBack(Queue_LCD_Driver, &msg, portMAX_DELAY);
            while(detect_pin()) {
                taskYIELD();
            }
        }
        taskYIELD();
    }
}
