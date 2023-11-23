#ifndef __MUSIC_PLAYER_H__
#define __MUSIC_PLAYER_H__


/* RTOS header files */
#include <FreeRTOS.h>
#include <task.h>
#include <queue.h>

#include <inputs/include/enums.h>

extern QueueHandle_t Queue_MusicPlayer_Driver;


#endif // __MUSIC_PLAYER_H__
