#include <inputs/include/button.h>


// RTOS Handle
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

    // Variables tracking if buttons were reset
    uint8_t reset_button1 = 1;
    uint8_t reset_button2 = 1;

    // Stores information about action for queue
    MESSAGE_t msg1 = {
       .action = CLICK,
       .direction = UP
    };

    MESSAGE_t msg2 = {
       .action = CLICK,
       .direction = DOWN
    };

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

        // If the de-bounce variable is equal to 0x7F and button has been reset since last
        // occurrence, send event to input queue
        if (debounce_state_button1 == 0x7F && reset_button1) {
            reset_button1 = 0;
            xQueueSendToBack(Queue_MusicPlayer_Driver, &msg1, portMAX_DELAY);
        }

        if (debounce_state_button2 == 0x7F && reset_button2) {
            reset_button2 = 0;
            xQueueSendToBack(Queue_MusicPlayer_Driver, &msg2, portMAX_DELAY);
        }

        if (debounce_state_button1 == 0) {
            reset_button1 = 1;
        }

        if (debounce_state_button1 == 2) {
            reset_button2 = 1;
        }

        // Polling delay
        vTaskDelay(pdMS_TO_TICKS(10));
    }
}
