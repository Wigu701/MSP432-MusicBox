#ifndef TASK_DUET__
#define TASK_DUET__

#include "msp.h"
#include <stdbool.h>
#include <stdint.h>

/* RTOS header files */
#include <FreeRTOS.h>
#include <task.h>

#include <inputs/include/input_enums.h>
#include <outputs/include/music_player.h>

extern TaskHandle_t Task_Duet_Handle;

void set_pin(char on);

/**
 * Detects if either button is pressed. If yes, sends message to queue
 */
void Task_duet(void *pvParameters);


#endif /* TASK_DUET__ */
