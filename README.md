
# ESP32 Bluetooth Controlled RC Car

## Author
**Bu_Thy**

---

## 📌 Project Overview

This project is a **Bluetooth-controlled RC car** built using an **ESP32 development board** and an **L298N motor driver**.

The ESP32 uses its **built-in Bluetooth** to receive commands from a mobile device and control the DC motors.

---

## Features

- Bluetooth wireless control
- Forward, Backward, Left, and Right movement
- Variable motor speed control
- Forward and backward differential steering
- No external HC-05 Bluetooth module required

---

## Components Required

1. ESP32 Development Board
2. L298N Motor Driver
3. DC Motors × 2 or 4
4. Wheels × 2 or 4
5. RC Car Chassis
6. Battery Pack
7. Jumper Wires
8. Switch
9. USB Cable

### Optional Components

- 3S Li-ion Battery Pack
- 3S Li-ion BMS
- 3S Li-ion Charging Module

---

## Project Cost

| # | Component | Price (₹) |
|---|---|---:|
| 1 | ESP32 Development Board | — |
| 2 | L298N Motor Driver | — |
| 3 | DC Motors | — |
| 4 | Wheels | — |
| 5 | RC Car Chassis | — |
| 6 | Battery Pack | — |
| 7 | Jumper Wires | — |
| 8 | Switch | — |

### Total Project Cost

**To be updated**

> Note: The total cost depends on the components and prices used for the project.

---

## 🔌 Connections Diagram

<img width="907" height="656" alt="WhatsApp Image 2026-08-25 at 10 35 59 PM" src="https://github.com/user-attachments/assets/d4b5a68a-2d36-4edd-ad8c-66afa666d14b" />


### ESP32 to L298N

| L298N | ESP32 |
|---|---|
| ENA | GPIO 12 |
| IN1 | GPIO 14 |
| IN2 | GPIO 27 |
| IN3 | GPIO 26 |
| IN4 | GPIO 25 |
| ENB | GPIO 33 |
| GND | GND |

### Motor Connections

| L298N | Motor |
|---|---|
| OUT1 | Motor A |
| OUT2 | Motor A |
| OUT3 | Motor B |
| OUT4 | Motor B |

---

## Power Connections

- Battery (+) → **L298N motor supply**
- Battery (−) → **L298N GND**
- ESP32 GND → **L298N GND**

### Important

- ESP32 and L298N must have a **common GND**.
- Do not connect motors directly to ESP32 GPIO pins.
- Do not connect the battery directly to the ESP32 3.3V pin.
- Check the voltage rating of the motor driver and motors.
- Check battery polarity before powering the circuit.
- A fully charged 3S Li-ion battery can reach approximately **12.6V**.

---


## 📱 Control App

The car can be controlled using any compatible **Bluetooth Classic controller or terminal application** that allows custom character commands.

The application should send the commands listed above.

---

## How It Works

1. The ESP32 is powered on.
2. The ESP32 initializes Bluetooth.
3. The mobile device connects to **ESP32_B-Ty**.
4. The mobile application sends a movement command.
5. The ESP32 receives and processes the command.
6. The ESP32 sends control signals to the L298N.
7. The L298N drives the DC motors according to the command.

### System Flow

```text
Mobile Phone
     |
 Bluetooth
     |
     v
   ESP32
     |
 GPIO + PWM
     |
     v
   L298N
     |
     v
 DC Motors
```

---

## Software Requirements

### Arduino IDE

The project can be programmed using the **Arduino IDE** with the ESP32 board package installed.


---


## ⚠️ Common Mistakes

* No common GND between ESP32 and L298N
* Incorrect motor driver connections
* Incorrect ENA/ENB connections
* Incorrect IN1/IN2/IN3/IN4 connections
* Connecting motors directly to ESP32 GPIO pins
* Incorrect battery polarity
* Using an unsuitable battery voltage
* Exceeding the L298N current rating

---

## 🔋 Battery Precautions

If using a 3S Li-ion battery:

```text
Nominal voltage = 11.1V
Fully charged = 12.6V
```

* Use a suitable 3S BMS.
* Use a proper 3S Li-ion charger.
* Check battery polarity before connection.
* Do not short-circuit the battery.
* Disconnect the battery before modifying the circuit.

---

