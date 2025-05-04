# 🕒 24-Hour Clock with Alarm System

> A real-time clock system with millisecond precision, alarm functionality, and interactive user interface using buttons and LEDs on an embedded platform.

---

## 📄 Project Overview

This project is part of the coursework for the **Software for Embedded Systems** course at **Technische Universität Hamburg (TU Hamburg)**.

It implements a **real-time 24-hour clock** with:
- **1-millisecond resolution**
- **Alarm functionality**
- **User configuration via Rotary and Joystick Buttons**
- **LED indicators for seconds, alarm status, and alarm trigger**

The system runs on an embedded microcontroller and uses a scheduler framework to manage timing events and user interactions.

---

## 🔧 Key Features

- **24-hour format display (HH:MM:SS)**
- **Manual time setting during initialization**
- **Alarm toggle and configuration**
- **LED feedback:**
  - Green LED: Blinks every second
  - Yellow LED: Indicates alarm is armed
  - Red LED: Flashes at 4 Hz when alarm triggers
- **5-second alarm duration or until any button is pressed**
- **Alarm only triggers during normal operation mode**

---

## ⚙️ Operation Modes

### 1. **Uninitialized Mode (Time Setup)**

Upon power-up:
- Display shows "HH:MM" with a message prompting time setup.
- Use **Rotary Button** to increment hours.
- Press **Joystick Button** to proceed to minute setup.
- Press **Joystick Button again** to confirm and start the clock.

### 2. **Normal Operation Mode**

- Clock displays time in **HH:MM:SS** format.
- **Rotary Button**: Toggles alarm state (ON/OFF)
- **Joystick Button**: Enters **Alarm Setting Mode**

### 3. **Alarm Setting Mode**

- Display switches to show **alarm time (HH:MM)**
- Use **Rotary Button** to set alarm time
- Press **Joystick Button** to return to normal mode

### 4. **Alarm Triggered Mode**

- When current time matches alarm time **and alarm is ON**:
  - Red LED flashes at **4 Hz**
  - Alarm lasts **5 seconds** or until any button is pressed

---

## 🧰 Hardware Components

- **Microcontroller**: (e.g., STM32, AVR, or similar)
- **Display**: 16x2 LCD or OLED (I2C or parallel)
- **Buttons**:
  - **Rotary Encoder / Pushbutton**: For incrementing values
  - **Joystick Button**: For navigating modes
- **LEDs**:
  - Green: Second indicator
  - Yellow: Alarm enabled
  - Red: Alarm triggered

---

## 🛠️ Software Architecture

- **Scheduler Framework** used to manage:
  - 1ms timer callback for timekeeping
  - Button debouncing and input handling
  - LED blinking patterns
- Modular design with separate modules for:
  - Clock logic (`clock.c/h`)
  - Alarm logic (`alarm.c/h`)
  - User interface (`ui.c/h`)
  - Scheduler (`scheduler.c/h`)

---

## 📋 Functional Behavior Summary

| Action                        | Effect                                                                 |
|-----------------------------|------------------------------------------------------------------------|
| Power On                    | Show default HH:MM, prompt to set time                                 |
| Rotate Button               | Increment hour/minute/alarm time based on current mode                 |
| Press Joystick              | Confirm hour ➔ move to minutes ➔ confirm time ➔ enter alarm setting     |
| Rotate in Normal Mode       | Toggle alarm ON/OFF                                                    |
| Press Joystick in Normal    | Enter alarm setting mode                                               |
| Time Match + Alarm ON       | Red LED blinks at 4Hz for 5 seconds or until button pressed            |

---

## 🎓 Course Context

This project was developed as part of the **Software for Embedded Systems** course at **Technische Universität Hamburg (TU Hamburg)**. It demonstrates understanding of:
- Real-time scheduling
- State machine design
- Input/output interfacing
- Timing accuracy and synchronization
- Modular software architecture
