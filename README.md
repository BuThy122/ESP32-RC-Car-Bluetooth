# 🚗 ESP32 Bluetooth RC Car

![ESP32](https://img.shields.io/badge/ESP32-Controller-blue?logo=espressif)
![Bluetooth](https://img.shields.io/badge/Bluetooth-Wireless-0082FC?logo=bluetooth)
![Arduino](https://img.shields.io/badge/Arduino-IDE-00979D?logo=arduino)
![L298N](https://img.shields.io/badge/Driver-L298N-orange)

A simple **4-wheel Bluetooth-controlled RC car** built using an **ESP32** and **L298N motor driver**.

The ESP32 uses its built-in Bluetooth to receive commands from a smartphone and control the four DC motors.

---

## ✨ Features

- 📱 Bluetooth control
- ⬆️ Forward / Backward
- ⬅️ Left / Right
- ⚡ Variable speed control
- 
---

## 🧰 Components

| Component | Qty. |
|---|---:|
| ESP32 Development Board | 1 |
| L298N Motor Driver | 1 |
| DC Motors | 4 |
| Wheels | 4 |
| 3.7V Li-ion Cells | 3 |
| Chassis | 1 |
| Jumper Wires (Female-Female) | 1 |
| Switch | 1 |

---

## 💰 Cost

| Component | Price |
|---|---:|
| ESP32 | ₹375 |
| L298N | ₹128 |
| DC Motors × 4 | ₹176 |
| Wheels × 4 | ₹76 |
| Li-ion Cells × 3 | ₹135 |
| Jumper Wires | ₹50 |
| Switch | ₹10 |
| **Total** | **₹950** |

*Prices based on RoboCaze and may vary.*

---

## 🔌 Circuit

<img width="907" height="656" alt="WhatsApp Image 2026-08-25 at 10 35 59 PM" src="https://github.com/user-attachments/assets/f03928ca-4a6f-44d6-a593-d6386218f4a8" />
### ESP32 → L298N

| L298N | ESP32 |
|---|---|
| ENA | GPIO 12 |
| IN1 | GPIO 14 |
| IN2 | GPIO 27 |
| IN3 | GPIO 26 |
| IN4 | GPIO 25 |
| ENB | GPIO 33 |
| GND | GND |

### Motors

| L298N | Motor |
|---|---|
| OUT1 + OUT2 | Left Motors |
| OUT3 + OUT4 | Right Motors |


## 🔋 Power

**3S Battery (+)** → **L298N Motor Supply**

**3S Battery (−)** → **L298N GND**

**3S Battery** → **Buck Converter** → **ESP32 5V/VIN**

**ESP32 GND** → **L298N GND**

> ⚠️ A fully charged 3S Li-ion pack reaches **12.6V**. Do not connect it directly to the ESP32 3.3V pin.

---

## 📱 Bluetooth Control App

Compatible controller apps include:

- Arduino Bluetooth Control
- Arduino Car
- Bluetooth RC Controller

### Control

| Command | Movement |
|---|---|
| ⬆️ | Forward |
| ⬇️ | Backward |
| ⬅️ | Left |
| ➡️ | Right |
| ⏹️ | Stop |

---

## ⚙️ How It Works

```text
📱 Phone
   │
   │ Bluetooth
   ▼
ESP32
   │
   │ GPIO + PWM
   ▼
L298N
   │
   ▼
DC Motors
```

The smartphone sends a command → ESP32 receives it → ESP32 controls the L298N → motors move accordingly.

---

## 💻 Code

The Arduino sketch is located in:

👉 [**ESP32_Bluetooth_RC_code.ino**](ESP32_Bluetooth_RC_code.ino)

The code handles Bluetooth communication, motor direction, and PWM speed control.

---

## ⚠️ Notes

- Keep **ESP32 and L298N GND connected**.
- Do not connect motors directly to ESP32 GPIO pins.
- Check battery polarity before powering the circuit.
- Use a suitable **3S BMS and charger** for the battery pack.
- Make sure motor current is within the L298N's capability.

---

## 👨‍💻 Author

**Bu_Thy**

*Robotics • ESP32 • Arduino • Embedded Systems*

---

⭐ If you found this project useful, consider giving it a star!
