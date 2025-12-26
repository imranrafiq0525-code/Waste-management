# Smart Dustbin Overflow Alert IoT System
## Overview
IoT-based smart dustbin system that monitors the garbage level using an ultrasonic sensor and alerts when the bin is almost full.
Designed using Arduino and tested through Wokwi simulation.
## Features
Ultrasonic sensor measures the garbage height/level inside the bin.
When the level crosses the set threshold, buzzer and LED alert are triggered.
Real-time bin level displayed via Serial Monitor or LCD.
Thresholds can be customized in code.
Future enhancement: Add GSM/WiFi module for message or cloud notification.
## Hardware Used
Arduino Uno / Nano
Ultrasonic Sensor (HC-SR04)
Buzzer
LEDs, Resistors, Jumper wires
9V Battery / USB Power Supply
## Simulation
Wokwi project link: https://wokwi.com/projects/451239779777724417
## Code
Main file: smart_dustbin_overflow.ino
Circuit image: Smart_dustbin_overflow.png
