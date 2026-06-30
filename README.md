# Solar Tracking System Using Arduino

## Overview
This project presents a Single-Axis Solar Tracking System developed using Arduino UNO, LDR (Light Dependent Resistor) sensors, and a servo motor. The system automatically tracks the sun's movement by continuously monitoring light intensity and adjusting the solar panel's orientation toward the brightest light source. This improves solar energy capture compared to a fixed solar panel system.

## Features
- Automatic single-axis solar tracking
- Real-time sunlight detection using dual LDR sensors
- Servo motor-based panel alignment
- Sensor calibration using EEPROM memory
- Adjustable tracking threshold to reduce servo jitter
- Low-cost and energy-efficient design

## Components Used
- Arduino UNO
- 2 × LDR Sensors
- SG90 Servo Motor
- 10kΩ Resistors
- Solar Panel (Demonstration Model)
- Push Button Switch (Calibration)
- Jumper Wires
- Wooden Base Structure

## Working Principle
Two LDR sensors are placed on opposite sides of the solar panel. The Arduino continuously compares the light intensity measured by both sensors. When a difference in light intensity is detected, the servo motor rotates the panel toward the brighter side until both sensors receive nearly equal illumination. The system also includes a calibration feature that stores sensor offsets in EEPROM to improve tracking accuracy.

## Software and Tools
- Arduino IDE
- Embedded C/C++
- Arduino Servo Library
- EEPROM Library

## Circuit Connections
| Component | Arduino Pin |
|------------|------------|
| LDR 1 | A1 |
| LDR 2 | A0 |
| Servo Signal | D10 |
| Calibration Switch | D2 |
| Servo VCC | 5V |
| Servo GND | GND |

## Challenges Faced
LDR sensors are highly sensitive to changes in light intensity. Small shadows or external light variations can cause unwanted servo movement. Proper calibration and threshold tuning were implemented to improve tracking stability and accuracy.

## Future Improvements
- Dual-axis solar tracking
- IoT-based performance monitoring
- MPPT integration
- Higher precision light sensors
- Automatic night return mechanism

## Applications
- Solar Energy Systems
- Smart Renewable Energy Projects
- Educational and Research Applications
- Remote Power Generation Systems

## Team Members
- Siva Sankar (2024MEB1362)
- Koppu Divyamshi (2024MEB1363)
- Laxmi Niwas (2024MEB1364)
- Malhar Dave (2024MEB1365)
- Manav Gulati (2024MEB1366)

## Conclusion
The developed Arduino-based solar tracking system successfully demonstrates automatic solar panel alignment using LDR sensors and a servo motor. By continuously orienting the panel toward the direction of maximum sunlight, the system improves solar energy utilization while maintaining a simple, cost-effective, and scalable design.
