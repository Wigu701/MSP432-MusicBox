/*
 * Copyright (c) 2016-2019, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *  ======== main_freertos.c ========
 */
#include "main.h"

SemaphoreHandle_t Sem_LCD;


/*
 *  ======== main ========
 */
int main(void)
{
    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;     // stop watchdog timer

    Crystalfontz128x128_Init();

    Queue_Sound = xQueueCreate(2, sizeof(int));
    Queue_LCD_Driver = xQueueCreate(1, sizeof(MESSAGE_t));

    // Semaphore to make sure that tasks are not trying to draw to the LCD
    // concurrently
    Sem_LCD = xSemaphoreCreateBinary();
    xSemaphoreGive(Sem_LCD);

    xTaskCreate
    (   Task_buttons,
        "Button detect",
        configMINIMAL_STACK_SIZE,
        NULL,
        1,
        &Task_Buttons_Handle
    );


    xTaskCreate
    (   Task_pollTimer,
        "Poll peripherals",
        configMINIMAL_STACK_SIZE,
        NULL,
        1,
        &Task_TimerPoll_Handle
    );

    xTaskCreate
    (   Task_ADC_Logic,
        "Timer2 Tasks",
        configMINIMAL_STACK_SIZE,
        NULL,
        2,
        &Task_ADC_Handle
    );

    xTaskCreate
    (   Task_playSound,
        "Play Sound",
        configMINIMAL_STACK_SIZE,
        NULL,
        1,
        NULL
    );

    xTaskCreate
    (   Task_LCD_Driver,
        "LCD Driver", // Processes inputs and outputs
        configMINIMAL_STACK_SIZE,
        NULL,
        1,
        NULL
    );

    /* Start the FreeRTOS scheduler */
    vTaskStartScheduler();

    while(1){};
}

//*****************************************************************************
//
//! \brief Application defined malloc failed hook
//!
//! \param  none
//!
//! \return none
//!
//*****************************************************************************
void vApplicationMallocFailedHook()
{
    /* Handle Memory Allocation Errors */
    while(1)
    {
    }
}

//*****************************************************************************
//
//! \brief Application defined stack overflow hook
//!
//! \param  none
//!
//! \return none
//!
//*****************************************************************************
void vApplicationStackOverflowHook(TaskHandle_t pxTask, char *pcTaskName)
{
    //Handle FreeRTOS Stack Overflow
    while(1)
    {
    }
}
