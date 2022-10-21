#include "task_duet.h"
#include <stdbool.h>


TaskHandle_t Task_Duet_Handle = NULL;

/**
 * Initializes duet pins
 *
 * P3.7: Input Pin on Bank J4
 * P4.6: Output Pin on Bank J1
 */
void initialize_pins() {
    P3->DIR &= ~BIT7;
    P4->DIR |= BIT6;
}

/**
 * Detects if input pin is asserted
 */
bool detect_pin() {
    return (P3->IN & BIT7) == 1;
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
                vTaskDelay(pdMS_TO_TICKS(5));
            }
        }
    }
}
