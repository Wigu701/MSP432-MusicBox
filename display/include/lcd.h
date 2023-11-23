// Based on code by Joe Krachey

#ifndef __LCD_H__
#define __LCD_H__

#include "msp.h"
#include <stdbool.h>
#include <string.h>
#include <display/include/screen_characters.h>

/* RTOS header files */
#include <FreeRTOS.h>
#include <task.h>
#include <semphr.h>

// RTOS Globals
extern SemaphoreHandle_t Sem_LCD;
extern TaskHandle_t Task_Title_Handle;
extern TaskHandle_t Task_Author_Handle;


// Title and Author String Pointers
extern volatile char* titleString;
extern volatile char* authorString;


// Music Printout Constants
#define TOP_THIRD_COORD 22          // Where to center top row content
#define MID_THIRD_COORD 66          // Where to center middle row content
#define BOT_THIRD_COORD 110         // Where to center bottom row content
#define CENTER_THIRD_COORD 65       // Where to center text horizontally
#define DISPLAY_TEXT_COLOR 0xFFFF   // Foreground color for text
#define DISPLAY_BACK_COLOR 0x0000   // Background color for text
#define MIN_TEXT_LENGTH 120         // Width of text sections on LCD in pixels
#define INTER_CHAR_GAP  1           // Number of pixels between displayed characters
#define SCROLL_INTERVAL 2           // Period of text display scroll updates divided by 50ms
#define SCROLL_DELAY    10          // Additional period of delay of text scroll at start and end divided by 50ms
#define SCROLL_STEP     5           // How many pixels to shift on each scroll step

// Setup for LCD display
extern void Crystalfontz128x128_Init(void);


// Task managing display of title on top third of screen
extern void Task_title(void *pvParameters);


// Task managing display of author on middle third of screen
extern void Task_author(void *pvParameters);


// Draws progress bar on bottom third of screen
// If reset true, draws a bar with 0 progress
// If reset false, increments the bar by amount specified
extern void lcd_draw_progress(uint8_t reset, uint8_t increment);


#endif /* _LCD_H_ */
