#ifndef __ADC_H__
#define __ADC_H__

#include "msp.h"
#include <stdint.h>
#include <stdbool.h>

/* RTOS header files */
#include <FreeRTOS.h>
#include <task.h>
#include <queue.h>

#include <inputs/include/enums.h>
#include <music_player.h>

extern TaskHandle_t Task_ADC_Handle;
extern TaskHandle_t Task_pollADC_Handle;

/**
 * Polls ADC every 10ms
 */
void Task_pollADC(void *pvParameters);

/**
 * Contains code to run when ADC interrupt occurs
 */
void Task_ADC_Logic(void *pvParameters);

/**
 * Interrupt handler for ADC which messages readings to queue when done
 */
void ADC14_IRQHandler(void);

#endif /* __ADC_H__ */
