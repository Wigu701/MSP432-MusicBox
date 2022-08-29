#include <task_timer_polling.h>

TaskHandle_t Task_TimerPoll_Handle = NULL;

/**
 * Polls ADC every 10ms
 */
void Task_pollTimer(void *pvParameters) {
    initialize_ADC();

    while (1) {
        // Sample ADC
        ADC14->CTL0 |= ADC14_CTL0_ENC | ADC14_CTL0_SC;
        vTaskDelay(pdMS_TO_TICKS(10));
    }
}
