# Adjustable Clock with Timer1 – AVR/Arduino Project

This project implements a real-time clock (RTC) using Timer1 of an AVR microcontroller on an Arduino Uno. The current time is continuously displayed on an LCD screen in `HH:MM:SS` format and can be adjusted dynamically via UART and a push button.


## 🎯 Project Objective

Design a digital clock using the Timer1 module on the Arduino Uno. The system supports setting the hour and minute values through UART communication triggered by a push button.

## 🧰 Components Required

- Arduino Uno  
- Arduino Base Shield  
- LCD Display (I2C or Parallel)  
- Push Button  
- Breadboard  
- Jumper Wires  
- Computer with Arduino IDE

## 🔧 Software Functionality

### 🕒 Real-Time Clock Display
- Continuously shows time in `HH:MM:SS` format on the LCD screen.
- Time is updated using **Timer1** on AVR.

### ⏱️ Time Adjustment via Button & UART
- **UART** is used to receive hour and minute values from the user.
- **Push button behavior** determines what gets set:
  - 🔘 **Single press (within 2 seconds)** → Sets the **hour**.
  - 🔘🔘 **Double press (within 2 seconds)** → Sets the **minute**.

### 🔁 Value Handling
- If input values are out of valid range:
  - Hours: `hour % 24`
  - Minutes: `minute % 60`
- Example:
  - Input hour: `30` → sets clock hour to `6`
  - Input minute: `70` → sets clock minute to `10`

## 🧪 Key Features

| Feature | Description |
|--------|-------------|
| Timer1 | Used to generate 1-second intervals |
| UART | Used to input new hour/minute values |
| Button Logic | Determines whether hour or minute should be updated |
| LCD Display | Outputs current time in `HH:MM:SS` format |

## 📈 How It Works

```plaintext
1. Initialize Timer1 for 1-second ticks.
2. Start a clock that updates and displays time every second.
3. Wait for user input via UART.
4. Use button presses to decide whether to update hour or minute.
5. Normalize invalid values using modulo operation.
