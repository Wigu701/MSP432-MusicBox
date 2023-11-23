#include <inputs/include/adc.h>


// RTOS Handles
TaskHandle_t Task_ADC_Handle = NULL;
TaskHandle_t Task_pollADC_Handle = NULL;


// Global variable to transfer ADC results to task
uint16_t adcReadings[2];


// Voltage triggers for each ADC peripheral
#define VOLTTRIGGER_JOY_UP ((int)((2.50)/(3.3/4096)))
#define VOLTTRIGGER_JOY_DOWN ((int)((0.85)/(3.3/4096)))


/**
 * Initializes joystick on launchpad
 */
void initialize_joystick(void) {
    // Configure the X direction as an analog input pin.
    P6->SEL0 |= BIT0;
    P6->SEL1 |= BIT0;

    // Configure the Y direction as an analog input pin.
    P4->SEL0 |= BIT4;
    P4->SEL1 |= BIT4;
}


/**
 * Configures ADC to read joystick and accelerometer
 */
void initialize_ADC(void) {
    initialize_joystick();

    // Configure to sample 16-times in pulsed sample mode
    ADC14->CTL0 = ADC14_CTL0_SHP | ADC14_CTL0_SHT01;

    // Sequence of channels
    ADC14->CTL0 |= ADC14_CTL0_CONSEQ_1;

    // Configure ADC to return 12-bit values
    ADC14->CTL1 = ADC14_CTL1_RES_2;

    // Associate the X direction joystick signal with MEM[0]
    ADC14->MCTL[0] = ADC14_MCTLN_INCH_15;

    // Associate the Y direction joystick signal with MEM[1]
    ADC14->MCTL[1] = ADC14_MCTLN_INCH_9;

    // Indicate this is end of the sequence
    ADC14->MCTL[1] |= ADC14_MCTLN_EOS;

    // Configure it to generate interrupt after MEM[4] is written to
    ADC14->IER0 = ADC14_IER0_IE1;

    // Enable interrupts, make sure priority is lower than RTOS scheduler
    NVIC_EnableIRQ(ADC14_IRQn);
    NVIC_SetPriority(ADC14_IRQn, 2);

    // Turn ADC ON
    ADC14->CTL0 |= ADC14_CTL0_ON;
}


/**
 * Polls ADC every 10ms
 */
void Task_pollADC(void *pvParameters) {
    initialize_ADC();

    while (1) {
        // Sample ADC
        ADC14->CTL0 |= ADC14_CTL0_ENC | ADC14_CTL0_SC;
        vTaskDelay(pdMS_TO_TICKS(10));
    }
}


/**
 * Handles logic for ADC data
 */
void Task_ADC_Logic(void *pvParameters) {
    // These variables ensure joystick and accelerometer returned to neutral position
    // before another reading is taken to avoid user permanently holding these inputs
    // or sticky sensors from ruining the game
    bool joyDeviated = false;

    // Variables to store information about input to be sent to queue
    MESSAGE_t msg;
    DIRECTION dir;

    while (1) {
        // Wait for new ADC reading
        ulTaskNotifyTake(pdTRUE, portMAX_DELAY);

        // Joystick movement detection
        if (!joyDeviated) {
            if (adcReadings[0] > VOLTTRIGGER_JOY_UP) {
                joyDeviated = true;
                dir = LEFT;
            } else if (adcReadings[0] < VOLTTRIGGER_JOY_DOWN) {
                joyDeviated = true;
                dir = RIGHT;
            } else if (adcReadings[1] > VOLTTRIGGER_JOY_UP) {
                joyDeviated = true;
                dir = UP;
            } else if (adcReadings[1] < VOLTTRIGGER_JOY_DOWN) {
                joyDeviated = true;
                dir = DOWN;
            }
        } else {
            if (adcReadings[0] < VOLTTRIGGER_JOY_UP && adcReadings[0] > VOLTTRIGGER_JOY_DOWN && adcReadings[1] < VOLTTRIGGER_JOY_UP && adcReadings[1] > VOLTTRIGGER_JOY_DOWN) {
                joyDeviated = false;
                msg.action = FLICK;
                msg.direction = dir;
                xQueueSendToBack(Queue_MusicPlayer_Driver, &msg, portMAX_DELAY);
            }
        }
    }
}


/**
 * Task Handler activating when an ADC conversion finished, stores values
 * and notifies Task_ADC_Logic to run for data evaluation
 */
void ADC14_IRQHandler(void) {
    BaseType_t xHigherPriorityTaskWoken;

    // Copy readings
    adcReadings[0] = ADC14->MEM[0]; // Joystick x
    adcReadings[1] = ADC14->MEM[1]; // Joystick y

    // Notify task
    vTaskNotifyGiveFromISR(
        Task_ADC_Handle,
        &xHigherPriorityTaskWoken
    );

    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}
