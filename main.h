/*
 * main.h
 *
 *  Created on: Apr 29, 2022
 *      Author: pnowa
 */

#ifndef MAIN_H_
#define MAIN_H_

#include "msp.h"
#include "msp432p401r.h"
#include <stdint.h>
#include <stdio.h>
#include "task_lcd_driver.h"
#include "enums.h"
#include "task_lcd_draw.h"
#include "lcd.h"

/* RTOS header files */
#include <FreeRTOS.h>
#include <task.h>
#include <semphr.h>

/* Tasks */
#include <task_buttons.h>
#include <task_buzzer.h>
#include <task_timer_polling.h>
#include <task_duet.h>


extern SemaphoreHandle_t Sem_LCD;



#endif /* MAIN_H_ */
