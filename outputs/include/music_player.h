#ifndef __MUSIC_PLAYER_H__
#define __MUSIC_PLAYER_H__


#include <string.h>

/* RTOS header files */
#include <FreeRTOS.h>
#include <inputs/include/input_enums.h>
#include <task.h>
#include <queue.h>

#include <display/include/lcd.h>
#include <inputs/include/input_enums.h>
#include <outputs/include/buzzer.h>
#include <outputs/include/songs.h>


extern QueueHandle_t Queue_MusicPlayer_Driver;

void Task_musicPlayer(void *pvParameters);


#endif // __MUSIC_PLAYER_H__
