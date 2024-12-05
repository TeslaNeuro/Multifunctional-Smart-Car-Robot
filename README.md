# Multifunctional Smart Car Robot

A multifunctional smart car robot built using the ELEEGO Robot package, designed for autonomous navigation with obstacle avoidance and line following capabilities.

## Features
- **Obstacle Avoidance**: Ultrasonic sensors detect and avoid obstacles in the robot's path.
- **Line Following**: Infrared sensors detect and follow a line with high accuracy.
- **Customizable**: Easily tweak sensor calibration, motor control, and algorithms for optimized performance.

## Hardware Requirements
- ELEEGO Smart Robot Kit (includes motors, ultrasonic sensor, infrared sensors, etc.)
- Microcontroller (e.g., Arduino or compatible board)
- Jumper wires and battery pack

## Software Requirements
- Arduino IDE or compatible platform
- ELEEGO Robot Library
- C++ for control algorithms

## Setup Instructions

### 1. Hardware Assembly
- Assemble the robot using the ELEEGO robot kit.
- Connect ultrasonic and infrared sensors to the microcontroller as per the kit's wiring guide.

### 2. Software Installation
- Download and install [Arduino IDE](https://www.arduino.cc/en/software).
- Install the ELEEGO Robot library through the Arduino Library Manager.
- Clone this repository or download the ZIP file.

### 3. Upload Code
- Open the Arduino IDE and load the main source code files.
- Select the correct microcontroller and port under `Tools`.
- Upload the code to the robot.

### 4. Calibration
- Adjust sensor thresholds and motor speeds in main script for optimal performance.

## Usage
Once powered on, the robot will:
- Navigate autonomously by avoiding obstacles.
- Follow a visible line on the ground, maintaining track alignment.

## Customization
- Modify the line-following and obstacle avoidance parameters in the main source code.
- Add additional sensors or modify the control logic for new features (e.g., remote control).
