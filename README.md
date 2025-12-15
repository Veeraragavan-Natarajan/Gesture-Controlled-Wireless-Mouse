🖱️ Gesture-Controlled Wireless Mouse

ESP32-C3 / ESP32 Dev Module + MPU6050

This project aims to create a gesture-based wireless mouse that allows the user to control the cursor using hand movements.
It uses the MPU6050 for motion sensing and the ESP32 (C3 or Dev Module) for processing and BLE HID communication. Two tactile switches handle left and right click actions.

This repository will track the entire development process from circuit design to the final prototype.

🔧 Current Progress — Circuit Design Completed

For the initial stage, the circuit design has been completed.
To keep the enclosure and internal layout flexible, two design variants were created:

• ESP32-C3 Version

Compact and efficient layout

I²C connection with MPU6050

Tactile switches for click inputs

• ESP32 Dev Module Version

Classic ESP32 form factor

Same IMU + switch integration

Good for breadboard testing

A short circuit design demo video is included in this repository.

🧩 Components Used

ESP32-C3 Dev Board or *ESP32 Dev Module

MPU6050 IMU sensor

2 × Tactile Switches (Left & Right Click)

Breadboard / jumper wires

USB cable for programming

🎯 Next Steps

Implement BLE HID mouse functionality

Tune IMU gesture sensitivity & smoothing

Add calibration for drift reduction

Begin enclosure/casing design

Integrate full interaction flow
