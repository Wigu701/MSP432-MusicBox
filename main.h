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
#include "enums.h"

/* RTOS header files */
#include <FreeRTOS.h>
#include <task.h>
#include <semphr.h>

/* Tasks */
#include <display/include/lcd.h>
#include <task_buttons.h>
#include <task_buzzer.h>
#include <task_timer_polling.h>
#include <task_duet.h>



#endif /* MAIN_H_ */
