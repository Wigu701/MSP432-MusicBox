#ifndef _ADC__
#define _ADC__

#include "msp.h"
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

/* RTOS header files */
#include <FreeRTOS.h>
#include <task.h>
#include <queue.h>

extern TaskHandle_t Task_ADC_Handle;

/**
 * Configures ADC to read joystick and accelerometer
 */
void initialize_ADC(void);

/**
 * Contains code to run when ADC interrupt occurs
 */
void Task_ADC_Logic(void *pvParameters);

/**
 * Interrupt handler for ADC which messages readings to queue when done
 */
void ADC14_IRQHandler(void);

#endif /* _ADC__ */
