/*
 * task_lcd_driver.h
 *
 *  Created on: Apr 26, 2022
 *      Author: pnowa
 */

#ifndef TASK_LCD_DRIVER_H_
#define TASK_LCD_DRIVER_H_

#include <stdbool.h>
#include "task_buzzer.h"

/* RTOS header files */
#include <FreeRTOS.h>
#include <task.h>
#include <queue.h>
#include "task_lcd_draw.h"
#include "enums.h"
#include "task_buzzer.h"
#include "main.h" // For LCD Semaphore
#include "task_duet.h"

extern QueueHandle_t Queue_LCD_Driver;

extern volatile int player_score;

// Driver task that facilitates communication between LCD functions and ACTION hardware
void Task_LCD_Driver(void* pvParameters);



#endif /* TASK_LCD_DRIVER_H_ */
