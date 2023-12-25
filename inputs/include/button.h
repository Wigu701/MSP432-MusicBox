#ifndef __BUTTON_H__
#define __BUTTON_H__

#include "msp.h"
#include <stdint.h>
#include <stdbool.h>

/* RTOS header files */
#include <FreeRTOS.h>
#include <task.h>

#include <inputs/include/input_enums.h>
#include <outputs/include/music_player.h>

extern TaskHandle_t Task_Buttons_Handle;

/**
 * Detects if either button is pressed. If yes, sends message to queue
 */
void Task_buttons(void *pvParameters);

#endif /* __BUTTON_H__ */
