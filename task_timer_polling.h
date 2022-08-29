
#ifndef _TIMER_POLL__
#define _TIMER_POLL_

#include "msp.h"
#include <stdint.h>
#include <stdio.h>
#include <task_adc.h>

/* RTOS header files */
#include <FreeRTOS.h>
#include <task.h>

extern TaskHandle_t Task_TimerPoll_Handle;

/**
 * Polls every peripheral every 10ms
 */
void Task_pollTimer(void *pvParameters);

#endif /* _TIMER_POLL__ */
