#ifndef TASK_DUET__
#define TASK_DUET__

#include "msp.h"
#include <stdint.h>
#include <stdio.h>

/* RTOS header files */
#include <FreeRTOS.h>
#include <task.h>
#include <task_buzzer.h>
#include "task_lcd_driver.h"
#include "enums.h"

extern TaskHandle_t Task_Duet_Handle;

/**
 * Sets output pin
 */
void set_pin(char on);

/**
 * Detects if either button is pressed. If yes, sends message to queue
 */
void Task_duet(void *pvParameters);

#endif /* TASK_DUET__ */
