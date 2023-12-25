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


#include "main.h"


int main(void)
{
    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;     // stop watchdog timer

    // Initialize LCD
    initCharacters();
    Crystalfontz128x128_Init();

    // RTOS queues
    Queue_MusicPlayer_Driver = xQueueCreate(2, sizeof(MESSAGE_t));
    Queue_Sound = xQueueCreate(2, sizeof(char));

    xTaskCreate
    (   Task_title,
        "Draw song title on lcd",
        configMINIMAL_STACK_SIZE,
        NULL,
        3,
        &Task_Title_Handle
    );

    xTaskCreate
    (   Task_author,
        "Draw song author on lcd",
        configMINIMAL_STACK_SIZE,
        NULL,
        3,
        &Task_Author_Handle
    );

    xTaskCreate
    (   Task_buttons,
        "Buttons detect",
        configMINIMAL_STACK_SIZE,
        NULL,
        1,
        &Task_Buttons_Handle
    );

    xTaskCreate
    (   Task_pollADC,
        "Trigger ADC reading",
        configMINIMAL_STACK_SIZE,
        NULL,
        1,
        &Task_pollADC_Handle
    );

    xTaskCreate
    (   Task_ADC_Logic,
        "Handle ADC reading",
        configMINIMAL_STACK_SIZE,
        NULL,
        3,
        &Task_ADC_Handle
    );

    xTaskCreate
    (   Task_duet,
        "Duet signals",
        configMINIMAL_STACK_SIZE,
        NULL,
        2,
        &Task_Duet_Handle
    );

    __enable_irq();

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
