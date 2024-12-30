/**
 * @file main.c
 * @brief Main program for gas and temperature monitoring system with UART communication and LED indicators.
 *
 * This program initializes the necessary peripherals and handles input from UART and a push button.
 * It monitors smoke and temperature levels and communicates the values over UART.
 */

#include <main.h>

/**
 * @brief Structure to store temperature and smoke values.
 */
struct {
    unsigned int TemperatureValue; /**< Measured temperature value. */
    unsigned int SmokeValue;       /**< Measured smoke value. */
} situation;

/*** Global Variables ***/
uint32_t SecTick = 0; /**< System tick counter for 1-second intervals. */
uint8_t SecondsCounterLED = 0; /**< Counter for LED blinking intervals. */
uint8_t SecondsCounterCheckStatus = 0; /**< Counter for status checking intervals. */
uint16_t i = 0; /**< General-purpose counter. */
uint8_t pushButtonState = 0; /**< State of the push button (pressed/released). */
uint8_t AddresssValid = 0; /**< Indicates if a valid address is received over UART. */
uint32_t PushButtonCounter = 0; /**< Counter for button presses. */
uint8_t LEDState = 0; /**< Current state of the LED (ON/OFF). */

unsigned short *frame; /**< Pointer for UART frame transmission. */
volatile char tx_busy; /**< UART transmission status. */

/**
 * @brief Main function.
 */
void main() {
    char Data = 0; /**< Variable to store received UART data. */

    // Peripheral Initialization
    S_RCC_Init();
    S_GPIO_Init();
    InterruptInit();
    UART_Init(9600); // Initialize UART with 9600 baud rate
    PLT0Init();
    PLT1Init();
    LED = 0; // Turn off LED initially

    while (1) {
        SmokeState Sm;

        // Push Button Handling
        if (PRESSED_PUSHBUTTON) {
            // Placeholder for button press logic
        } else {
            if ((pushButtonState == 1) && (PushButtonCounter > PERRESS)) {
                GCC_DELAY(10000);
                PLTAInit();
            }
        }

        GCC_CLRWDT(); // Clear watchdog timer

        // UART Data Handling
        Data = UART_ReceiveNonBlocking();
        GCC_CLRWDT(); // Clear watchdog timer again

        if (Data != 0) {
            UART_Transmit(Data); // Echo received data

            if ((Data == ADDRESS) || (Data == PUBLIC_ADDRESS)) {
                AddresssValid = 1;
            }

            // Addressed Commands
            if ((AddresssValid) && (Data == 'O')) {
                GCC_DELAY(10000);
                PLTAInit();
                UART_Transmit('O');
                info();
                AddresssValid = 0;
            }

            if ((AddresssValid) && (Data == 'C')) {
                GCC_DELAY(10000);
                PLTAInit();
                UART_Transmit('C');
                info();
                AddresssValid = 0;
            }

            if ((AddresssValid) && (Data == 'L')) {
                LEDState = 1;
                AddresssValid = 0;
            }

            if ((AddresssValid) && (Data == 'H')) {
                LEDState = 0;
                AddresssValid = 0;
            }
        }

        LED = LEDState; // Update LED state
        PLTAOFF(); // Turn off PLT

        // System Tick Handling
        SecTick++;
        if (SecTick > ONE_SECOND) {
            SecondsCounterLED++;
            SecondsCounterCheckStatus++;
            SecTick = 0;
        }

        // Periodic Status Check
        if (SecondsCounterCheckStatus >= CHEK_STATUS_PERIOD) {
            ADCInit();
            NTC_POWER_ON;
            situation.TemperatureValue = temperature(ReadADC(1), 3.0f);
            NTC_POWER_OFF;
            InitSmokeDetection();
            CheckSmokeLevel(&situation.SmokeValue);
            if (situation.SmokeValue == 0) UART_Transmit('F');
            SmokeDetectionOFF();
            ADC_Inactive();
            SecondsCounterCheckStatus = 0;
        }

        // LED Blinking
        if (SecondsCounterLED >= LED_BLINKING_PERIOD) {
            LED = 1;
            GCC_DELAY(LED_BLINKING_ON_TIME);
            LED = 0;
            SecondsCounterLED = 0;
        }
    }
}

/**
 * @brief Transmit smoke and temperature information over UART.
 */
void info(void) {
    UART_Transmit((situation.SmokeValue / 1000) % 10 + 0x30);
    UART_Transmit((situation.SmokeValue / 100) % 10 + 0x30);
    UART_Transmit((situation.SmokeValue / 10) % 10 + 0x30);
    UART_Transmit((situation.SmokeValue) % 10 + 0x30);
    UART_Transmit('T');
    UART_Transmit('=');
    UART_Transmit((situation.TemperatureValue / 1000) % 10 + 0x30);
    UART_Transmit((situation.TemperatureValue / 100) % 10 + 0x30);
    UART_Transmit((situation.TemperatureValue / 10) % 10 + 0x30);
    UART_Transmit((situation.TemperatureValue) % 10 + 0x30);
    UART_Transmit(10); // Newline character
    AddresssValid = 0;
}
