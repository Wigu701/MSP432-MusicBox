/*
 * main.h
 *
 *  Created on: Apr 29, 2022
 *      Author: pnowa
 */

#ifndef __MAIN_H__
#define __MAIN_H__

#include "msp.h"
#include "msp432p401r.h"
#include <stdint.h>

/* RTOS header files */
#include <FreeRTOS.h>
#include <task.h>
#include <semphr.h>

/* Tasks */
#include <display/include/lcd.h>
#include <inputs/include/adc.h>
#include <inputs/include/button.h>
#include <inputs/include/duet.h>
#include <music_player.h>


#endif /* __MAIN_H__ */
