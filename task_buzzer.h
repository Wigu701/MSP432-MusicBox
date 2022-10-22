#ifndef _BUZZER__
#define _BUZZER__

#include "msp.h"
#include <stdint.h>
#include <stdio.h>

/* RTOS header files */
#include <FreeRTOS.h>
#include <task.h>
#include <queue.h>

extern QueueHandle_t Queue_Sound;
const extern int totalSongs;

/**
 * Initializes buzzer
 */
void initialize_buzzer(void);

/**
 * Plays ping noise indicating new action
 */
void Task_playSound(void *pvParameters);


#endif /* _BUZZER__ */
