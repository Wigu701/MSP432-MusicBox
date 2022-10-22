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
    // Set directions
    P2->DIR &= ~BIT3;
    P4->DIR |= BIT6;

    // Enable interrupts for input pin
    P2->IE |= BIT3;
    P2->IES &= ~BIT3; // Rising edge
}

/**
 * Detects if input pin is asserted
 */
bool detect_pin() {
    return (P2->IN & BIT3) == 8;
}

void set_pin(char on) {
    if (on) {
        P4->OUT |= BIT6;
    } else {
        P4->OUT &= ~BIT6;
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

/**
 * Interrupt handler for input gpio
 */
void PORT2_IRQHandler (void) {
    BaseType_t xHigherPriorityTaskWoken;

    // Notify task
    vTaskNotifyGiveFromISR(
        Task_Duet_Handle,
        &xHigherPriorityTaskWoken
    );

    // Clear interrupt
    P2->IFG &= ~BIT3;

    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}

