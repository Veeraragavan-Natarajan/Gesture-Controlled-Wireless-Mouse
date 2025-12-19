🖱️ Gesture-Controlled Wireless Mouse

ESP32 + MPU6050 | BLE HID | Calibrated Gesture Control

This project implements a gesture-controlled wireless mouse that allows cursor movement using natural hand tilts. It is built using an ESP32 and an MPU6050 IMU, with tactile switches for left and right click actions. The mouse communicates with the host system via Bluetooth Low Energy (BLE) HID.

The project was developed through multiple stages — from breadboard prototyping to a finalized zero PCB build with manual soldering and calibrated motion control.

✨ Key Features

Gesture-based cursor control using MPU6050 IMU

BLE HID mouse implementation using ESP32

Left & right click using tactile switches

Motion calibration on startup

Dead-zone handling to eliminate jitter

Smooth cursor movement with low-pass filtering

Tuned sensitivity for natural DPI-like behavior (~800–1600 DPI feel)

Compact zero PCB hardware with manual soldering

🧩 Hardware Used

ESP32 Dev Module

MPU6050 (Accelerometer + Gyroscope)

2 × Tactile switches (Left / Right click)

Zero PCB

Jumper wires (for prototyping)

USB cable

🔌Schematics & Connections

The gesture-controlled mouse uses a simple and reliable hardware layout centered around the ESP32 Dev Module and MPU6050 IMU. The MPU6050 communicates with the ESP32 over the I²C interface, while tactile switches are used for mouse click inputs.

📍 MPU6050 Connections
MPU6050 Pin	ESP32 Pin	Description
VCC	3.3V	Power supply
GND	GND	Common ground
SDA	GPIO 21	I²C data
SCL	GPIO 22	I²C clock
🖱️ Tactile Switch Connections
Function	ESP32 Pin	Notes
Left Click	GPIO 18	Uses internal pull-up
Right Click	GPIO 19	Uses internal pull-up
Other switch pin	GND	Active LOW
⚠️ Design Notes

All components operate at 3.3V logic levels

Internal pull-up resistors are enabled for switch inputs

A common ground is maintained across all components

The same pin mapping was used for both breadboard and zero PCB builds

🧠 How It Works (Brief)

MPU6050 measures pitch and roll angles

Sensor data is filtered and smoothed in firmware

Cursor movement is mapped from hand tilt

BLE HID sends mouse movement and click events

Calibration offsets ensure stable resting behavior

🔧 Development Stages
1️⃣ Breadboard Prototype

Hardware validation

BLE mouse testing

Initial gesture mapping

2️⃣ Zero PCB Final Build

Manual soldering

Compact layout

Final pin mapping

Full calibration & tuning

