// Based on code by Joe Krachey

#include <display/include/lcd.h>


// Initialize globals for title and author tasks
volatile char* titleString = "Can you call this a hotel? I didn't receive a mint on my pillow";
volatile char* authorString = "Toby Fox";
volatile int trackNum = 0;

// RTOS objects
TaskHandle_t Task_Title_Handle = NULL;
TaskHandle_t Task_Author_Handle = NULL;
TaskHandle_t Task_Track_Handle = NULL;
SemaphoreHandle_t Sem_LCD;


// LCD Screen Pins
#define LCD_SCK_PORT   P1
#define LCD_SCK_PIN    BIT5

#define LCD_MOSI_PORT  P1
#define LCD_MOSI_PIN   BIT6

#define LCD_CS_PORT    P5
#define LCD_CS_PIN     BIT0

#define LCD_RST_PORT   P5
#define LCD_RST_PIN    BIT7

#define LCD_DC_PORT    P3
#define LCD_DC_PIN     BIT7


// LCD Screen Dimensions
#define LCD_VERTICAL_MAX                   132
#define LCD_HORIZONTAL_MAX                 132

#define LCD_ORIENTATION_UP    0
#define LCD_ORIENTATION_LEFT  1
#define LCD_ORIENTATION_DOWN  2
#define LCD_ORIENTATION_RIGHT 3

// ST7735 LCD controller Command Set
#define CM_NOP             0x00
#define CM_SWRESET         0x01
#define CM_RDDID           0x04
#define CM_RDDST           0x09
#define CM_SLPIN           0x10
#define CM_SLPOUT          0x11
#define CM_PTLON           0x12
#define CM_NORON           0x13
#define CM_INVOFF          0x20
#define CM_INVON           0x21
#define CM_GAMSET          0x26
#define CM_DISPOFF         0x28
#define CM_DISPON          0x29
#define CM_CASET           0x2A
#define CM_RASET           0x2B
#define CM_RAMWR           0x2C
#define CM_RGBSET          0x2d
#define CM_RAMRD           0x2E
#define CM_PTLAR           0x30
#define CM_MADCTL          0x36
#define CM_COLMOD          0x3A
#define CM_SETPWCTR        0xB1
#define CM_SETDISPL        0xB2
#define CM_FRMCTR3         0xB3
#define CM_SETCYC          0xB4
#define CM_SETBGP          0xb5
#define CM_SETVCOM         0xB6
#define CM_SETSTBA         0xC0
#define CM_SETID           0xC3
#define CM_GETHID          0xd0
#define CM_SETGAMMA        0xE0
#define CM_MADCTL_MY       0x80
#define CM_MADCTL_MX       0x40
#define CM_MADCTL_MV       0x20
#define CM_MADCTL_ML       0x10
#define CM_MADCTL_BGR      0x08
#define CM_MADCTL_MH       0x04

// R 5-bit  G 6-bit   B 5-bit
#define LCD_COLOR_WHITE         0xFFFF
#define LCD_COLOR_BLACK         0x0000
#define LCD_COLOR_RED           0xF800
#define LCD_COLOR_GREEN         0x07E0
#define LCD_COLOR_GREEN2        0xB723
#define LCD_COLOR_BLUE          0x001F
#define LCD_COLOR_BLUE2         0x051D
#define LCD_COLOR_YELLOW        0xFFE0
#define LCD_COLOR_ORANGE        0xFBE4
#define LCD_COLOR_CYAN          0x07FF
#define LCD_COLOR_MAGENTA       0xA254
#define LCD_COLOR_GRAY          0x7BEF
#define LCD_COLOR_BROWN         0xBBCA


#define HAL_LCD_delay(x)      __delay_cycles(x * 48)



/* ****************************************************************************
 * Used to configure the 5 pins that control the LCD interface on the MKII.
 *
 * CLK and MOSI will be configured as their Primary Module Function
 *
 * CS, C/D, and RST will be configured at output pins
 ******************************************************************************/
void HAL_LCD_PortInit(void)
{
    // ADD CODE 
    
    // LCD_SCK
    LCD_SCK_PORT->SEL0 |= LCD_SCK_PIN;
    LCD_SCK_PORT->SEL1 &= ~LCD_SCK_PIN;

    // LCD_MOSI
    LCD_MOSI_PORT->SEL0 |= LCD_MOSI_PIN;
    LCD_MOSI_PORT->SEL1 &= ~LCD_MOSI_PIN;

    // LCD_CS
    LCD_CS_PORT->DIR |= LCD_CS_PIN;

    // LCD_RST
    LCD_RST_PORT->DIR |= LCD_RST_PIN;

    // LCD_RS
    LCD_DC_PORT->DIR |= LCD_DC_PIN;
}

/* ****************************************************************************
 * Used to configure the eUSCIB Interface as a 3-Wire SPI Interface
 *
 ******************************************************************************/
void HAL_LCD_SpiInit(void)
{
    EUSCI_B0->CTLW0 =  EUSCI_B_CTLW0_SWRST;            // Put eUSCI state machine in reset

    // ADD CODE to define the behavior of the eUSCI_B0 as a SPI interface
    EUSCI_B0->CTLW0 = EUSCI_B_CTLW0_CKPH |    // Phase 1
            EUSCI_B_CTLW0_MSB |               // MSB First
            EUSCI_B_CTLW0_MST |               // SPI Master
            EUSCI_B_CTLW0_MODE_0 |            // 3 Pin SPI
            EUSCI_B_CTLW0_SYNC |              // Synchronous mode
            EUSCI_B_CTLW0_SSEL__SMCLK |       // Use SMCLK
            //EUSCI_B_CTLW0_STEM |              // Digital output
            EUSCI_B_CTLW0_SWRST;              // eUSCI state machine in reset

    // ADD CODE to set the SPI Clock to 12MHz.
    //
    // Divide clock speed by 2 (24MHz/2) = 12 MHz
    //fBitClock = fBRCLK/(UCBRx+1).
    EUSCI_B0->BRW = 1;

    EUSCI_B0->CTLW0 &= ~EUSCI_B_CTLW0_SWRST;// Initialize USCI state machine

    // set the chip select low
    // The chip select will be held low forever!  There is only 1 device (LCD) 
    // connected to the SPI device, so we will leave it activated all the time.
    LCD_CS_PORT->OUT &= ~LCD_CS_PIN;

    // Set the DC pin high (put it in data mode)
    LCD_DC_PORT->OUT |= LCD_DC_PIN;

}

//*****************************************************************************
//
// Writes a command to the CFAF128128B-0145T.  This function implements the basic SPI
// interface to the LCD display.
//
//*****************************************************************************
void HAL_LCD_writeCommand(uint8_t command)
{
    // Set to command mode -- DC PIN Set to 0
    LCD_DC_PORT->OUT &= ~LCD_DC_PIN;

    // Busy wait while the data is being transmitted. Check the STATW register and see if it is busy
    while(EUSCI_B0->STATW & BIT0){
        __no_operation();
    }

    // Transmit data
    EUSCI_B0->TXBUF = command;

    // Busy wait while the data is being transmitted. Check the STATW register and see if it is busy 
    while(EUSCI_B0->STATW & BIT0){
        __no_operation();
    }

    // Set back to data mode, set the DC pin high
    LCD_DC_PORT->OUT |= LCD_DC_PIN;
}


//*****************************************************************************
//
// Writes an 8 bit data to the CFAF128128B-0145T. This function implements the basic SPI
// interface to the LCD display.
//
//*****************************************************************************
void HAL_LCD_writeData(uint8_t data)
{
    // Busy wait while the data is being transmitted. Check the STATW register and see if it is busy
    while(EUSCI_B0->STATW & BIT0){
        __no_operation();
    }

    // Transmit data
    EUSCI_B0->TXBUF = data;

    // Busy wait while the data is being transmitted. Check the STATW register and see if it is busy
    while(EUSCI_B0->STATW & BIT0){
        __no_operation();
    }
}

//*****************************************************************************
//
// Macro to write 16 bits of data to the CFAF128128B-0145T.  This function implements the basic SPI
// interface to the LCD display.
//
//*****************************************************************************
void HAL_LCD_writeData_16(uint16_t data)
{
    HAL_LCD_writeData(data >> 8);    // 8 MSBs first
    HAL_LCD_writeData(data & 0xFF);  // then 8 LSBs
}

//*****************************************************************************
// Code adapted from TI LCD driver library
//*****************************************************************************
void Crystalfontz128x128_SetDrawFrame(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1)
{
    // Write the CM_CASET command followed by the 4 bytes of data
    // used to set the Column start and end rows.
    HAL_LCD_writeCommand(CM_CASET);
    // We can only send 8 bits at a time
    HAL_LCD_writeData_16(x0);
    HAL_LCD_writeData_16(x1);

    // Write the CM_RASET command followed by the 4 bytes of data
    // used to set the Row start and end rows.
    HAL_LCD_writeCommand(CM_RASET);
    // We can only send 8 bits at a time
    HAL_LCD_writeData_16(y0);
    HAL_LCD_writeData_16(y1);
}


//*****************************************************************************
// Code adapted from TI LCD driver library
//
//! Initializes the display driver.
//!
//! This function initializes the ST7735 display controller on the panel,
//! preparing it to display data.
//!
//! \return None.
//
//*****************************************************************************
void Crystalfontz128x128_Init(void)
{
    int i;
    int j;
    uint8_t upper8  = 0x00;
    uint8_t lower8  = 0x00;

    HAL_LCD_PortInit();
    HAL_LCD_SpiInit();


    LCD_RST_PORT->OUT &= ~LCD_RST_PIN;
    HAL_LCD_delay(50);

    LCD_RST_PORT->OUT |= LCD_RST_PIN;
    HAL_LCD_delay(120);

    HAL_LCD_writeCommand(CM_SLPOUT);
    HAL_LCD_delay(200);

    HAL_LCD_writeCommand(CM_GAMSET);
    HAL_LCD_writeData(0x04);

    HAL_LCD_writeCommand(CM_SETPWCTR);
    HAL_LCD_writeData(0x0A);
    HAL_LCD_writeData(0x14);

    HAL_LCD_writeCommand(CM_SETSTBA);
    HAL_LCD_writeData(0x0A);
    HAL_LCD_writeData(0x00);

    HAL_LCD_writeCommand(CM_COLMOD);
    HAL_LCD_writeData(0x05);
    HAL_LCD_delay(10);

    HAL_LCD_writeCommand(CM_MADCTL);
    HAL_LCD_writeData(CM_MADCTL_MX | CM_MADCTL_MY | CM_MADCTL_BGR);

    HAL_LCD_writeCommand(CM_NORON);


    Crystalfontz128x128_SetDrawFrame(0, 0, LCD_HORIZONTAL_MAX, LCD_VERTICAL_MAX);
    HAL_LCD_writeCommand(CM_RAMWR);

    for (i = 0; i < LCD_VERTICAL_MAX; i++)
    {

        for(j=0; j < LCD_HORIZONTAL_MAX; j++)
        {
            HAL_LCD_writeData(upper8);
            HAL_LCD_writeData(lower8);
        }
    }



    HAL_LCD_delay(10);

    HAL_LCD_writeCommand(CM_DISPON);

    HAL_LCD_writeCommand(CM_MADCTL);
    HAL_LCD_writeData(CM_MADCTL_MX | CM_MADCTL_MY | CM_MADCTL_BGR);


    // Semaphore to make sure that tasks are not trying to draw to the LCD
    // concurrently
    Sem_LCD = xSemaphoreCreateBinary();
    xSemaphoreGive(Sem_LCD);
}


/*******************************************************************************
* Function Name: lcd_draw_rectangle
********************************************************************************
* Summary: draws a filled rectangle centered at the coordinates set by x, y
* Returns:
*  Nothing
*******************************************************************************/
void lcd_draw_rectangle(
  uint16_t x,
  uint16_t y,
  uint16_t width_pixels,
  uint16_t height_pixels,
  uint16_t fColor
)
{
    int i,j,x0,x1,y0,y1;

    // Set the left Col to be the center point minus half the width
    x0 = x - (width_pixels/2);

    // Set the Right Col to be the center point plus half the width
    x1 = x + (width_pixels/2);

    // Account for a width that is an even number
    if( (width_pixels & 0x01) == 0x00)
    {
        x1--;
    }

    // Set the upper Row to be the center point minus half the height
    y0 = y  - (height_pixels/2);

    // Set the upper Row to be the center point minus half the height
    y1 = y  + (height_pixels/2) ;

    // Account for a height that is an  number
    if( (height_pixels & 0x01) == 0x00)
    {
        y1--;
    }

    xSemaphoreTake(Sem_LCD, portMAX_DELAY);
    // Set the boundary of the image to draw
    Crystalfontz128x128_SetDrawFrame(x0, y0, x1, y1);

    // Inform the LCD we are going to send image data
    HAL_LCD_writeCommand(CM_RAMWR);

    // Write out the image data
    for(i = 0; i < height_pixels; i++)
    {
        for(j=0; j < width_pixels; j++)
        {
            HAL_LCD_writeData(fColor >> 8);
            HAL_LCD_writeData(fColor);
        }
    }

    xSemaphoreGive(Sem_LCD);
}


void lcd_draw_text(
  uint16_t x,
  uint16_t y,
  uint8_t* bitmap,
  uint16_t offset,
  uint16_t fColor,
  uint16_t bColor
)
{
  int i,j;
  int x0, x1, y0, y1;

  // Get left and right bounds of image
  x0 = x - (MIN_TEXT_LENGTH/2);
  x1 = x + (MIN_TEXT_LENGTH/2);
  if( (MIN_TEXT_LENGTH & 0x01) == 0x00)
  {
    x1--;
  }

  // Get upper and lower bounds of image
  y0 = y  - (CHARACTER_LIBRARY_HEIGHT/2);
  y1 = y  + (CHARACTER_LIBRARY_HEIGHT/2) ;
  if( (CHARACTER_LIBRARY_HEIGHT & 0x01) == 0x00)
  {
    y1--;
  }

  xSemaphoreTake(Sem_LCD, portMAX_DELAY);

  // Tell LCD screen we are writing and where
  Crystalfontz128x128_SetDrawFrame(x0, y0, x1, y1);
  HAL_LCD_writeCommand(CM_RAMWR);


  for (i = 0; i < CHARACTER_LIBRARY_HEIGHT; i++) {
      for (j = offset; j < offset + MIN_TEXT_LENGTH; j++) {

          if (bitmap[(i / 8) + (3 * j)] & (0x1 << (7 - (i % 8)))) {
              HAL_LCD_writeData(fColor >> 8);
              HAL_LCD_writeData(fColor);

          } else {
              HAL_LCD_writeData(bColor >> 8);
              HAL_LCD_writeData(bColor);
          }
      }
  }

  xSemaphoreGive(Sem_LCD);
}


// Builds a bitmap for the string in text
// Will allocate minimize size memory needed and set bitmap to point at it
// Bitmap encodes string top down, left to right
//
// ex. If the text to encode is AB
// First 21 bits encode first column (leftmost part of A), next 21 the second column, and so
// on until last 21 encode last column (rightmost part of B)
uint16_t buildStringBitmap(char* text, uint8_t** bitmap) {
    int i = 0;
    int width = 0;

    // Find total horizontal width of string in pixels
    for (i = 0; i < strlen(text); i++) {
        width += CHARACTER_LIBRARY[text[i] - CHARACTER_LIBRARY_OFFSET].width + INTER_CHAR_GAP;
    }

    // Allocate memory for block. Character heights are all 21, round up to 3 bytes per column
    // Minimum size will be 300 (100 pixels wide) for proper alignment on display
    int memorySize = width < MIN_TEXT_LENGTH ? MIN_TEXT_LENGTH : width;
    if (*bitmap != NULL) {
        vPortFree(*bitmap);
        *bitmap = NULL;
    }
    while (*bitmap == NULL) {
        *bitmap = pvPortMalloc(memorySize * 3);
        memset(*bitmap, 0, memorySize * 3);
    }


    // Set values in array. Will be done in vertical slices (top down), left to right
    i = 0;
    width = 0;
    while (i < strlen(text)) {
        memcpy(*bitmap + (3 * width), CHARACTER_LIBRARY[text[i] - CHARACTER_LIBRARY_OFFSET].bitmap, 3 * CHARACTER_LIBRARY[text[i] - CHARACTER_LIBRARY_OFFSET].width);
        width += CHARACTER_LIBRARY[text[i] - CHARACTER_LIBRARY_OFFSET].width + INTER_CHAR_GAP;
        i += 1;

    }

    return width;
}


// Draws on top third of screen
void Task_title(void *pvParameters)
{
    char* curTitle = NULL;
    uint8_t* titleBitmap = NULL;
    uint16_t titleWidth = 0;
    uint16_t horOffset = 0;
    int scrollDelay = -SCROLL_DELAY;

    while (true) {
        // If no title, wait for 100ms before checking again
        if (titleString == NULL) {
            // Clear current title if present
            lcd_draw_rectangle(CENTER_THIRD_COORD, TITLE_HORIZ_COORD, 132, 21, DISPLAY_BACK_COLOR);
            vTaskDelay(pdMS_TO_TICKS(100));
            continue;

        // Title has changed, update screen
        } else if (curTitle == NULL || strcmp((char*)titleString, curTitle) != 0) {
            // Build new title bitmap
            curTitle = (char*)titleString;
            titleWidth = buildStringBitmap(curTitle, &titleBitmap);
            horOffset = 0;

            // Draw update
            lcd_draw_text(CENTER_THIRD_COORD, TITLE_HORIZ_COORD, titleBitmap, horOffset,
                           DISPLAY_TEXT_COLOR, DISPLAY_BACK_COLOR);

        // Title still the same, scroll if title is too long to display
        } else {
            if (titleWidth > MIN_TEXT_LENGTH) {
                scrollDelay += 1;
                // Increment if delay met
                if (scrollDelay >= SCROLL_INTERVAL) {
                    horOffset += SCROLL_STEP;


                    // Reached end and got to delay, restart
                    if (horOffset >= titleWidth - MIN_TEXT_LENGTH + SCROLL_STEP) {
                        horOffset = 0;
                        scrollDelay = -SCROLL_DELAY;

                    // If end reached, double delay before reset
                    } else if (horOffset >= titleWidth - MIN_TEXT_LENGTH) {
                        // Cap offset in case of overshoot
                        horOffset = titleWidth - MIN_TEXT_LENGTH;
                        scrollDelay = -SCROLL_DELAY;

                    } else {
                        scrollDelay = 0;
                    }

                    // Draw update
                    lcd_draw_text(CENTER_THIRD_COORD, TITLE_HORIZ_COORD, titleBitmap, horOffset,
                                   DISPLAY_TEXT_COLOR, DISPLAY_BACK_COLOR);
                }
            }
        }

        vTaskDelay(pdMS_TO_TICKS(50));
    }
}


// Draws on middle third of screen
void Task_author(void *pvParameters)
{
    char* curAuthor = NULL;
    uint8_t* authorBitmap = NULL;
    uint16_t authorWidth = 0;
    uint16_t horOffset = 0;
    int scrollDelay = -SCROLL_DELAY;

    while (true) {
        // If no author, wait for 100ms before checking again
        if (authorString == NULL) {
            // Clear current author if present
            lcd_draw_rectangle(CENTER_THIRD_COORD, AUTHOR_HORIZ_COORD, 132, 21, DISPLAY_BACK_COLOR);
            vTaskDelay(pdMS_TO_TICKS(100));
            continue;

        // Author has changed, update screen
        } else if (curAuthor == NULL || strcmp((char*)authorString, curAuthor) != 0) {
            // Build new author bitmap
            curAuthor = (char*)authorString;
            authorWidth = buildStringBitmap(curAuthor, &authorBitmap);
            horOffset = 0;

            // Draw update
            lcd_draw_text(CENTER_THIRD_COORD, AUTHOR_HORIZ_COORD, authorBitmap, horOffset,
                           DISPLAY_TEXT_COLOR, DISPLAY_BACK_COLOR);

        // Author still the same, scroll if author is too long to display
        } else {
            if (authorWidth > MIN_TEXT_LENGTH) {
                scrollDelay += 1;
                // Increment if delay met
                if (scrollDelay >= SCROLL_INTERVAL) {
                    horOffset += SCROLL_STEP;

                    // Reached end and got to delay, restart
                    if (horOffset >= authorWidth - MIN_TEXT_LENGTH + SCROLL_STEP) {
                        horOffset = 0;
                        scrollDelay = -SCROLL_DELAY;

                    // If end reached, double delay before reset
                    } else if (horOffset >= authorWidth - MIN_TEXT_LENGTH) {
                        // Cap offset in case of overshoot
                        horOffset = authorWidth - MIN_TEXT_LENGTH;
                        scrollDelay = -SCROLL_DELAY;

                    } else {
                        scrollDelay = 0;
                    }

                    // Draw update
                    lcd_draw_text(CENTER_THIRD_COORD, AUTHOR_HORIZ_COORD, authorBitmap, horOffset,
                                   DISPLAY_TEXT_COLOR, DISPLAY_BACK_COLOR);
                }
            }
        }

        vTaskDelay(pdMS_TO_TICKS(50));
    }
}

extern void Task_track(void *pvParameters) {
    // Characters in index 7 will be used for display
    char trackString[] = "Track:  ";
    int oldNum = -1;

    uint8_t* textBitmap = NULL;

    while (1) {
        vTaskDelay(pdMS_TO_TICKS(50));
        if (trackNum == oldNum) continue;

        trackString[7] = trackNum + '0';
        oldNum = trackNum;
        buildStringBitmap(trackString, &textBitmap);
        lcd_draw_text(CENTER_THIRD_COORD, TRACK_HORIZ_COORD, textBitmap, 0,
                       DISPLAY_TEXT_COLOR, DISPLAY_BACK_COLOR);
    }
}


// Draws on bottom third of screen
void lcd_draw_progress(uint8_t reset, uint8_t increment)
{
    // Tracks current progress of bar
    static int progress = 0;
    int i = 0;


    if (reset) {
        // Clear current bar
        lcd_draw_rectangle(CENTER_THIRD_COORD, PBAR_HORIZ_COORD, 110, 12, DISPLAY_BACK_COLOR);

        xSemaphoreTake(Sem_LCD, portMAX_DELAY);
        // Draw vertical start and end boundaries
        Crystalfontz128x128_SetDrawFrame(10, PBAR_HORIZ_COORD + 2, 12, PBAR_HORIZ_COORD + 6);
        HAL_LCD_writeCommand(CM_RAMWR);
        for (i = 0; i < 21; i++)  HAL_LCD_writeData_16(DISPLAY_TEXT_COLOR);

        Crystalfontz128x128_SetDrawFrame(119, PBAR_HORIZ_COORD + 2, 121, PBAR_HORIZ_COORD + 6);
        HAL_LCD_writeCommand(CM_RAMWR);
        for (i = 0; i < 21; i++)  HAL_LCD_writeData_16(DISPLAY_TEXT_COLOR);

        // Draw horizontal line
        Crystalfontz128x128_SetDrawFrame(13, PBAR_HORIZ_COORD + 5, 118, PBAR_HORIZ_COORD + 6);
        HAL_LCD_writeCommand(CM_RAMWR);
        for (i = 0; i < 212; i++)  HAL_LCD_writeData_16(DISPLAY_TEXT_COLOR);

        progress = 0;

        xSemaphoreGive(Sem_LCD);
        return;
    }

    // Determine what pixels need to be changed
    // Bar ranges from x pixels [16, 115] and is 11 pixels tall
    int leftBound = progress + 16;
    progress += increment;
    if (progress > 100) progress = 100;
    int rightBound = (progress - 1) + 16;
    int totalPixels = 11 * (rightBound - leftBound + 1);

    xSemaphoreTake(Sem_LCD, portMAX_DELAY);

    // Change all to blue
    Crystalfontz128x128_SetDrawFrame(leftBound, PBAR_HORIZ_COORD - 6, rightBound, PBAR_HORIZ_COORD + 4);
    HAL_LCD_writeCommand(CM_RAMWR);
    for (i = 0; i < totalPixels; i++)  HAL_LCD_writeData_16(LCD_COLOR_BLUE2);

    xSemaphoreGive(Sem_LCD);
    return;
}
