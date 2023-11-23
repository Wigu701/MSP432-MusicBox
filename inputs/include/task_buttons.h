#ifndef TASK_BUTTONS__
#define TASK_BUTTONS__

#include "msp.h"
#include <stdint.h>
#include <stdio.h>

/* RTOS header files */
#include <FreeRTOS.h>
#include <task.h>
#include <task_buzzer.h>
#include "enums.h"

extern TaskHandle_t Task_Buttons_Handle;

/**
 * Detects if either button is pressed. If yes, sends message to queue
 */
void Task_buttons(void *pvParameters);

#endif /* TASK_BUTTONS__ */
