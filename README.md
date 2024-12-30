# PowerLineTransceiver
Power Line Transceiver  with Holtek MCU BA45F5240
This project implements a gas and temperature monitoring system using the following two main files:

- `main.h`: The header file containing type definitions, macro definitions, and function prototypes.
- `main.c`: The source file implementing the main logic of the program.

## File Descriptions

### 1. main.h

This file provides the following:

- **Type Definitions**: Includes custom integer types (`uint8_t`, `uint16_t`, etc.) and a boolean type (`bool`).
- **Macro Definitions**: Defines macros for constants such as device address, push button states, LED controls, and ADC calculations.
- **Function Prototypes**: Declares the `info()` function, which transmits sensor information via UART.

#### Macro Definitions

- **PowerLineTransceiver (PLT) Configuration**:
  - `PLT0Init()`: Initializes the PLT0 system for PowerLineTransceiver communication.
  - `PLT1Init()`: Initializes the PLT1 system for advanced PowerLineTransceiver functionalities.
  - `PLTAInit()`: Activates the PowerLineTransceiver system.
  - `PLTAOFF()`: Turns off the PowerLineTransceiver system.
- **Smoke Detector Integration**:
  - `InitSmokeDetection()`: Initializes the smoke detection module.
  - `CheckSmokeLevel(value)`: Checks the current smoke level and updates the provided variable.
  - `SmokeDetectionOFF()`: Deactivates the smoke detection system.
- **NTC Sensor**:
  - `NTC_POWER_ON`: Macro to power on the NTC sensor.
  - `NTC_POWER_OFF`: Macro to power off the NTC sensor.

### 2. main.c

This file contains the main program logic, including:

- **Initialization**: Initializes the RCC, GPIO, UART, interrupts, and PLT modules.
- **Main Loop**:
  - Monitors a push button state and performs actions based on its state.
  - Receives and processes UART data to control LEDs or perform actions.
  - Periodically reads ADC values for temperature and smoke level detection.
  - Controls a relay and transmits data through UART.
- **Helper Function**: `info()` formats and transmits smoke and temperature values via UART.

## Features

1. **PowerLineTransceiver (PLT)**:
   - Communicates critical information through power lines using PLT0 and PLT1 systems.
   - Uses PLT activation and deactivation macros for efficient control.
2. **Push Button Monitoring**: Detects long and short button presses.
3. **LED Control**: Blinks an LED periodically and reacts to UART commands.
4. **Gas and Temperature Detection**:
   - Uses an NTC sensor for temperature measurement.
   - Integrates with a smoke detector specifically designed to detect cigarette smoke.
5. **UART Communication**: Receives commands and transmits status updates and sensor readings.

## Usage

To use this project:

1. Include `main.h` in the source files.
2. Implement the required hardware setup (e.g., sensors, UART, and LED).
3. Compile and flash the program to the target microcontroller.
4. Use UART commands (`'O'`, `'C'`, `'L'`, `'H'`) to interact with the system.

## Dependencies

This project depends on the following modules:

- RCC
- GPIO
- UART
- Interrupt
- ADC
- NTC
- SmokeDetector
- PowerLineTransceiver (PLT)

Ensure all dependent modules are properly configured for the target hardware.

## Example UART Commands

- `'O'`: Transmit smoke and temperature information.
- `'C'`: Clear the current status.
- `'L'`: Turn the LED ON.
- `'H'`: Turn the LED OFF.

## Future Improvements

- Add error handling for invalid UART commands.
- Optimize memory usage for low-resource microcontrollers.
- Extend support for additional sensors and functionalities.

