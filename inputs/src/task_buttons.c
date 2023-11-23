#include "task_buttons.h"
#include <stdbool.h>

TaskHandle_t Task_Buttons_Handle = NULL;

/**
 * Initializes both buttons on launchpad
 *
 * P5.1: Button1
 * P3.5: Button2
 */
void initialize_buttons() {
    P5->DIR &= ~BIT1;
    P3->DIR &= ~BIT5;
}

/**
 * Detects if button1 (top button) is currently pressed
 */
bool detect_button1() {
    return (P5->IN & BIT1) == 0;
}

/**
 * Detects if button2 (lower button) is currently pressed
 */
bool detect_button2() {
    return (P3->IN & BIT5) == 0;
}

/**
 * Debounce both switches and send message to queue if either one is pressed
 */
void Task_buttons(void *pvParameters) {
    initialize_buttons();

    // Declare a uint8_t variables that will be used to de-bounce buttons
    uint8_t debounce_state_button1 = 0x00;
    uint8_t debounce_state_button2 = 0x00;

    // Stores information about action for queue
    MESSAGE_t msg;
    msg.action = CLICK;

    while(1)
    {
        // Shift the de-bounce variable to the left
        debounce_state_button1 = debounce_state_button1 << 1;
        debounce_state_button2 = debounce_state_button2 << 1;

        // If a button is pressed, set LSB of its associated debounce var
        if (detect_button1()) {
            debounce_state_button1 |= BIT0;
        }
        if (detect_button2()) {
            debounce_state_button2 |= BIT0;
        }

        // If the de-bounce variable is equal to 0x7F, notify via queue message
        if (debounce_state_button1 == 0x7F || debounce_state_button2 == 0x7F) {
            // Send thing into queue
            // xQueueSendToBack(Queue_LCD_Driver, &msg, portMAX_DELAY);
        }
        // Delay for 10mS using vTaskDelay
        vTaskDelay(pdMS_TO_TICKS(10));
    }
}
