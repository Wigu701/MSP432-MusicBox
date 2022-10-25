/*
 * task_lcd_driver.c
 *
 *  Created on: Apr 25, 2022
 *      Author: pnowa
 */

#include "task_lcd_driver.h"



QueueHandle_t Queue_LCD_Driver;

volatile int player_score = 0;

// Driver task that facilitates communication between LCD functions and ACTION hardware
void Task_LCD_Driver(void* pvParameters){
    // Some struct thing
    MESSAGE_t msgReceived;
    int soundSel;

    while (true) {
        xSemaphoreTake(Sem_LCD, portMAX_DELAY);
        refresh_screen();
        xSemaphoreGive(Sem_LCD);
        while (playing) {
            vTaskDelay(pdMS_TO_TICKS(5));
        }

        // Wait for first input back
        xQueueReset(Queue_LCD_Driver);
        xQueueReceive(Queue_LCD_Driver, &msgReceived, portMAX_DELAY);

        if (msgReceived.action == CLICK || msgReceived.action == IO) {
            soundSel = player_score;
            if (msgReceived.action == CLICK) {
                set_pin(1);
            }
            xQueueSendToBack(Queue_Sound, &soundSel, portMAX_DELAY);
        } else {
            if (msgReceived.direction == UP) {
                player_score = (player_score + 1) % totalSongs;
            } else {
                player_score = (--player_score < 0) ? totalSongs - 1 : player_score % totalSongs;
            }
        }
    }
}
