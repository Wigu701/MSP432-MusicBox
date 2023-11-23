Display Drivers Tasks

This document describes the design and implemention of the LCD display code.

LCD Drivers
The MSP432P401R launchpad features an Crystalfontz 128x128 LCD display controlled 
by a ST7735 connected to the CPU via SPI. Usage is as follows:

Call Crystalfontz128x128_Init before using any draw functions
- Set up SPI pins (HAL_LCD_PortInit)
- Set up SPI controller (HAL_LCD_SpiInit)
- Reset LCD screen and set up default configuration

lcd_draw_rectangle will draw to specified region on screen
- x: Horizontal pixel to center rectangle on
- y: Vertical pixel to center rectangle on
- width_pixels: Width of rectangle to draw
- height_pixels: Height of rectangle to draw
- fColor: Color of rectangle to draw

lcd_draw_text will draw text on screen according to specified bitmap
- Text is expected to be 24 pixels or below in height. Will draw offset to offset + MIN_TEXT_LENGTH
many pixel columns of text
- Bitmap should encode the pixels top to bottom, right to left (one vertical line at 
a time, left to right)
- x: Horizontal pixel to center rectangle on
- y: Vertical pixel to center rectangle on
- bitmap: Bitmap of text to draw
- offset: Which vertical pixel in bitmap to start at
- fColor: Color for 1's in bitmap
- bColor: Color for 0's in bitmap


Application Code
sceen_characters files contain bitmap encodings for most ASCII characters, organized as needed for lcd_draw_text.
Prior to displaying any text, buildStringBitmap helper function is used to build a single bitmap using the 
ASCII components, with spacing between each character specified by INTER_CHAR_GAP. The tasks for title and 
author then simply check if the respective text pointers have changed. If yes, they will generate a bitmap
and display it on the screen. If the text has not changed and the current value is longer than the available
screen width, the tasks will increment an offset to scroll the text. See the header file for tuning macros, and
simply modify the global variables titleString and authorString to dynamically change what is displayed.
- Note: Due to memory restrictions, there is an estimated 2500 pixel width limit on total displayed text (title + author)

The progress bar function is completely independent from the tasks and has two operating modes. If reset is on,
then the current bar will be wiped and the context bracket will be redrawn as empty. If reset is off, the function
will increment the bar by the specified number of pixels, capping at 100. 