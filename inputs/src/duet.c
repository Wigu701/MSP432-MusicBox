#include <inputs/include/duet.h>


TaskHandle_t Task_Duet_Handle = NULL;


/**
 * Initializes duet pins
 *
 * P1.0: Input Pin on Bank J4
 * P2.0: Output Pin on Bank J1
 */
void initialize_pins() {
    // Configure input pin on P1.0
    P1->DIR &= ~BIT0;
    P1->SEL0 &= ~BIT0;
    P1->SEL1 &= ~BIT0;

    // Pulldown resistor
    P1->REN |= BIT0;
    P1->OUT &= ~BIT0;

    // Rising edge interrupt
    P1->IES &= ~BIT0;
    P1->IE |= BIT0;

    // Turn on interrupt handler
    NVIC_EnableIRQ(PORT1_IRQn);
    NVIC_SetPriority(PORT1_IRQn, 2);


    // Configure output on P2.0
    P2->DIR |= BIT0;
    P2->SEL0 &= ~BIT0;
    P2->SEL1 &= ~BIT0;
}


/**
 * Sets output pin to value
 */
void set_pin(char on) {
    if (on) {
        P2->OUT |= BIT0;
    } else {
        P2->OUT &= ~BIT0;
    }
}


/**
 * Send message to queue on input pin rising edge
 * Initializes pins at startup
 */
void Task_duet(void *pvParameters) {
    initialize_pins();
    // Set output pin to low
    P2->OUT &= ~BIT0;

    // Stores information about action for queue
    MESSAGE_t msg;
    msg.action = DUET;

    while(1)
    {
        msg.direction = UP;
        while (P1->IN &= BIT0 == 0) vTaskDelay(pdMS_TO_TICKS(1));
        xQueueSendToBack(Queue_MusicPlayer_Driver, &msg, portMAX_DELAY);

        // Wait for interrupt on falling edge
        msg.direction = DOWN;
        ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
        xQueueSendToBack(Queue_MusicPlayer_Driver, &msg, portMAX_DELAY);
    }
}


/**
 * Interrupt handler for input P1.0
 */
void PORT1_IRQHandler(void) {
    // If from P1.0, queue task which will trigger duet play
    if (P1->IFG &= 0x1) {
        vTaskNotifyGiveFromISR(
            Task_Duet_Handle,
            &xHigherPriorityTaskWoken
        );
        portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
    }

    // Clear interrupt
    P1->IFG &= 0;
}

