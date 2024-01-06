#ifndef __BUZZER_H__
#define __BUZZER_H__

#include "msp.h"
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

/* RTOS header files */
#include <FreeRTOS.h>
#include <task.h>
#include <queue.h>

#include <display/include/lcd.h>
#include <inputs/include/duet.h>
#include <outputs/include/music_enums.h>
#include <outputs/include/songs.h>

#define SWITCHING_INTERVAL 7
#define TRACK_OFFSET 8


extern QueueHandle_t Queue_Sound;
extern volatile bool masterPlayer;

/**
 * Initializes buzzer
 */
void initialize_buzzer(void);

/**
 * Plays ping noise indicating new action
 */
void Task_playSong(void *pvParameters);


#endif /* __BUZZER_H__ */
