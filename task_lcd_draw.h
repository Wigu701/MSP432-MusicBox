/*
 * task_lcd_draw.h
 *
 *  Created on: Apr 26, 2022
 *      Author: pnowa
 */

#ifndef TASK_LCD_DRAW_H_
#define TASK_LCD_DRAW_H_

#include "task_lcd_driver.h"
#include "bop_it_images.h"
#include "enums.h"


/* RTOS header files */
#include <FreeRTOS.h>
#include <task.h>
#include <queue.h>


///////////////////////////////////////////////////
// HELPER FUNCTIONS FOR LCD SCREEN
/////////////////////////////////////////////////


/* Clears the screen
 * After the ACTION pop up animation has completed (slide, flash, etc), we can clear the screen
 * It's fine if we draw over the timer bar because it needs to be reset for the next action anyway.
 * We just have to redraw the score and any accumulated strikes
 */
void refresh_screen();

void draw_score(int score);

#endif /* TASK_LCD_DRAW_H_ */
