# Project 02: Ultrasonic Proximity Warning System

## Overview
This project uses an ultrasonic distance sensor to detect nearby objects and provide visual and audio warnings based on the measured distance.

The system uses two LEDs and a passive buzzer to indicate three different distance zones.

## Components Used
- Arduino UNO R4 WiFi
- HC-SR04 Ultrasonic Distance Sensor
- Yellow LED
- Red LED
- 2 × 220Ω resistors
- Passive buzzer
- Breadboard
- Jumper wires

## Circuit Connections

| Component | Arduino Pin |
|---|---|
| Ultrasonic TRIG | 9 |
| Ultrasonic ECHO | 10 |
| Yellow LED | 6 |
| Red LED | 7 |
| Passive buzzer (+) | 8 |
| VCC | 5V |
| GND | GND |

## How It Works

The ultrasonic sensor sends out a sound pulse and measures how long it takes for the echo to return.

The Arduino calculates the distance using the travel time of the sound wave.

The system has three warning zones:

- **Safe:** Above 30 cm — Both LEDs and buzzer are off.
- **Caution:** Between 15 cm and 30 cm — Yellow LED blinks.
- **Danger:** 15 cm or closer — Red LED stays on and the buzzer sounds.

If the sensor does not receive a valid echo, the warning indicators turn off.

## What I Learned
- Measuring distance using an ultrasonic sensor.
- Using `pulseIn()` to measure signal duration.
- Converting sound travel time into distance.
- Using conditional statements to create multiple warning zones.
- Using `millis()` for non-blocking LED blinking.
- Controlling a passive buzzer with `tone()` and `noTone()`.
- Handling invalid sensor readings with a timeout.

## Future Improvements
- Add an OLED display to show SAFE, CAUTION, and DANGER.
- Display the measured distance in centimeters.
- Improve the warning system with additional features.
