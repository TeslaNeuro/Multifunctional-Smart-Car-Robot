# Multifunctional Smart Car Robot

A multifunctional smart car robot built using the ELEEGO Robot package, designed for autonomous navigation with obstacle avoidance and line following capabilities.

## Features
- **Obstacle Avoidance**: Ultrasonic sensors detect and avoid obstacles in the robot's path.
- **Line Following**: Infrared sensors detect and follow a line with high accuracy.
- **Customizable**: Easily tweak sensor calibration, motor control, and algorithms for optimized performance.
- **Bluetooth Control**: Use the ELEEGO app to control the robot via Bluetooth, enabling manual override or custom feature activation.

## Hardware Requirements
- ELEEGO Smart Robot Kit (includes motors, ultrasonic sensor, infrared sensors, etc.)
- Microcontroller (e.g., Arduino or compatible board)
- Bluetooth module (HC-05 or similar)
- Jumper wires and battery pack

## Software Requirements
- Arduino IDE or compatible platform
- ELEEGO Robot Library
- C++ for control algorithms
- ELEEGO app (available on Android and iOS)

## Setup Instructions

### 1. Hardware Assembly
- Assemble the robot using the ELEEGO robot kit.
- Connect ultrasonic and infrared sensors to the microcontroller as per the kit's wiring guide.
- Connect the Bluetooth module (HC-05 or similar) to the microcontroller for wireless communication.

### 2. Software Installation
- Download and install [Arduino IDE](https://www.arduino.cc/en/software).
- Install the ELEEGO Robot library through the Arduino Library Manager.
- Clone this repository or download the ZIP file.

### 3. Upload Code
- Open the Arduino IDE and load the source code files.
- Select the correct microcontroller and port under `Tools`.
- Upload the code to the robot.

### 4. Calibration
- Adjust sensor thresholds and motor speeds for optimal performance.

### 5. ELEEGO App Setup
- Install the ELEEGO app on your smartphone (available on Android and iOS).
- Pair the robot with your phone via Bluetooth.
- Use the app to manually control the robot, toggle obstacle avoidance, line following, or activate custom features.

## Usage
Once powered on, the robot will:
- Navigate autonomously by avoiding obstacles and following a line.
- Be controllable via the ELEEGO app through Bluetooth for manual control or custom feature activation.

## Customization
- Modify the line-following and obstacle avoidance hardware or software parameters for better resolution or accuracy.
- Add additional sensors or modify the control logic for new features (e.g., remote control through the app).

