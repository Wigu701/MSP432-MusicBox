/*
 * task_lcd_draw.c
 *
 *  Created on: Apr 25, 2022
 *      Author: pnowa
 */

#include <time.h>          // These two are needed for random color generation
#include <stdlib.h>

#include "task_lcd_draw.h"
#include "lcd.h"
#include "enums.h"


TaskHandle_t Task_LCD_Draw_Handle = NULL;

/*   REFERENCE
 *
typedef struct {
    LED_LOCATION led_location;
    LED_COLOR color;
}LED_MSG_t;
*/



///////////////////////////////////////////////////
// HELPER FUNCTIONS FOR LCD SCREEN
/////////////////////////////////////////////////

/* Clears the screen
 * After the ACTION pop up animation has completed (slide, flash, etc), we can clear the screen
 * It's fine if we draw over the timer bar because it needs to be reset for the next action anyway.
 * We just have to redraw the score and any accumulated strikes
 */
void refresh_screen(){
    // Blank the screen
    lcd_draw_rectangle(64, 64, 128, 128, LCD_COLOR_WHITE);

    // Re-display the current score
    draw_score(player_score);
}

void draw_score(int score){
    // Draw ten's place
    switch(score / 10){
        case 0:
            lcd_draw_image(57, 64, zeroWidthPixels, zeroHeightPixels, zeroBitmap, LCD_COLOR_BLACK, LCD_COLOR_WHITE);
            break;
        case 1:
            lcd_draw_image(57, 64, oneWidthPixels, oneHeightPixels, oneBitmap, LCD_COLOR_BLACK, LCD_COLOR_WHITE);
            break;
        case 2:
            lcd_draw_image(57, 64, twoWidthPixels, twoHeightPixels, twoBitmap, LCD_COLOR_BLACK, LCD_COLOR_WHITE);
            break;
        case 3:
            lcd_draw_image(57, 64, threeWidthPixels, threeHeightPixels, threeBitmap, LCD_COLOR_BLACK, LCD_COLOR_WHITE);
            break;
        case 4:
            lcd_draw_image(57, 64, fourWidthPixels, fourHeightPixels, fourBitmap, LCD_COLOR_BLACK, LCD_COLOR_WHITE);
            break;
        case 5:
            lcd_draw_image(57, 64, fiveWidthPixels, fiveHeightPixels, fiveBitmap, LCD_COLOR_BLACK, LCD_COLOR_WHITE);
            break;
        case 6:
            lcd_draw_image(57, 64, sixWidthPixels, sixHeightPixels, sixBitmap, LCD_COLOR_BLACK, LCD_COLOR_WHITE);
            break;
        case 7:
            lcd_draw_image(57, 64, sevenWidthPixels, sevenHeightPixels, sevenBitmap, LCD_COLOR_BLACK, LCD_COLOR_WHITE);
            break;
        case 8:
            lcd_draw_image(57, 64, eightWidthPixels, eightHeightPixels, eightBitmap, LCD_COLOR_BLACK, LCD_COLOR_WHITE);
            break;
        case 9:
            lcd_draw_image(57, 64, nineWidthPixels, nineHeightPixels, nineBitmap, LCD_COLOR_BLACK, LCD_COLOR_WHITE);
            break;
        default:
            break;
    }

    // Draw one's place
    switch(score % 10){
        case 0:
            lcd_draw_image(74, 64, zeroWidthPixels, zeroHeightPixels, zeroBitmap, LCD_COLOR_BLACK, LCD_COLOR_WHITE);
            break;
        case 1:
            lcd_draw_image(74, 64, oneWidthPixels, oneHeightPixels, oneBitmap, LCD_COLOR_BLACK, LCD_COLOR_WHITE);
            break;
        case 2:
            lcd_draw_image(74, 64, twoWidthPixels, twoHeightPixels, twoBitmap, LCD_COLOR_BLACK, LCD_COLOR_WHITE);
            break;
        case 3:
            lcd_draw_image(74, 64, threeWidthPixels, threeHeightPixels, threeBitmap, LCD_COLOR_BLACK, LCD_COLOR_WHITE);
            break;
        case 4:
            lcd_draw_image(74, 64, fourWidthPixels, fourHeightPixels, fourBitmap, LCD_COLOR_BLACK, LCD_COLOR_WHITE);
            break;
        case 5:
            lcd_draw_image(74, 64, fiveWidthPixels, fiveHeightPixels, fiveBitmap, LCD_COLOR_BLACK, LCD_COLOR_WHITE);
            break;
        case 6:
            lcd_draw_image(74, 64, sixWidthPixels, sixHeightPixels, sixBitmap, LCD_COLOR_BLACK, LCD_COLOR_WHITE);
            break;
        case 7:
            lcd_draw_image(74, 64, sevenWidthPixels, sevenHeightPixels, sevenBitmap, LCD_COLOR_BLACK, LCD_COLOR_WHITE);
            break;
        case 8:
            lcd_draw_image(74, 64, eightWidthPixels, eightHeightPixels, eightBitmap, LCD_COLOR_BLACK, LCD_COLOR_WHITE);
            break;
        case 9:
            lcd_draw_image(74, 64, nineWidthPixels, nineHeightPixels, nineBitmap, LCD_COLOR_BLACK, LCD_COLOR_WHITE);
            break;
        default:
            break;
    }
}
