# Obstacle Avoidance Robot

This project is an Arduino-based obstacle avoidance robot that uses an ultrasonic sensor and a servo motor to detect and avoid obstacles in its path. The robot moves forward while continuously scanning for obstacles. When an obstacle is detected, it adjusts its direction accordingly through closed loop feedback from sensors.

---

## Features

- **Ultrasonic Obstacle Detection**: Utilizes an ultrasonic sensor to measure distances to obstacles.
- **Servo Motor Control**: Sweeps the ultrasonic sensor to scan the environment.
- **Automated Navigation**: Adjusts the robot's direction to avoid collisions.
- **Customizable Speed**: Motor speed can be adjusted by modifying the `CarSpeed` value.

---

## Components

### Hardware Requirements
- Arduino Board (e.g., Arduino Uno)
- Ultrasonic Sensor (e.g., HC-SR04)
- Servo Motor (e.g., SG90)
- Motor Driver (e.g., L298N)
- Brushed DC Motors (2)
- Wheels (2)
- 12V Power Supply (Battery pack)
- Chassis
- Jumper wires and Dupont cables

### Pin Configuration
| Component         | Pin on Arduino |
|-------------------|----------------|
| Servo Motor       | 3              |
| Ultrasonic Sensor |
| - Trigger Pin     | A5             |
| - Echo Pin        | A4             |
| Motor Driver      |
| - ENA (Speed A)   | 5              |
| - ENB (Speed B)   | 6              |
| - IN1 (Left Fwd)  | 7              |
| - IN2 (Left Back) | 8              |
| - IN3 (Right Back)| 9              |
| - IN4 (Right Fwd) | 11             |

---

## Code Overview

### Key Functions
- **`servoctrl()`**: Handles servo motor rotation and checks distances at different angles to determine obstacles.
- **`distance_()`**: Calculates the distance to an obstacle using the ultrasonic sensor.
- **Movement Functions**:
  - `forward()`: Moves the robot forward.
  - `left()`: Rotates the robot to the left.
  - `right()`: Rotates the robot to the right.
  - `back()`: Moves the robot backward.
  - `stop()`: Stops all motor movements.

### Adjustable Parameters
- **`CarSpeed`**: The speed of the motors, set using PWM values (0-255). Modify this variable in the code to change the robot's speed.
- **`delay(50)`**: Modify delay values in the `servoctrl()` function to adjust the scanning and decision-making speed.

---

## Setup and Usage

1. **Assemble the Hardware**:
   - Connect the ultrasonic sensor, servo motor, and motor driver to the Arduino as per the pin configuration table.
   - Mount the components on the robot chassis.
2. **Upload the Code**:
   - Open the Arduino IDE and upload the provided code to your Arduino board.
3. **Power Up**:
   - Connect the power supply and place the robot on a flat surface.
4. **Observe the Robot**:
   - The robot will move forward and avoid obstacles autonomously.

---

## Customization

- **Motor Speed**: Change the value of `CarSpeed` to adjust the robot's movement speed.
- **Obstacle Threshold**: Modify the `if (distance_() <= 30)` condition to change the obstacle detection distance.
- **Servo Sweep Range**: Adjust the servo angle range in `servoctrl()` to change the scanning area.

---

## Troubleshooting

- **Robot Not Moving**:
  - Check motor driver connections.
  - Verify that the power supply is sufficient for the motors.
- **Incorrect Obstacle Detection**:
  - Ensure that the ultrasonic sensor is securely connected.
  - Verify the trigger and echo pin connections.
- **Servo Not Sweeping**:
  - Confirm that the servo motor is properly connected to pin 3.
  - Check the servo motor power supply.

---

## Future Enhancements

- Add IR sensors for better obstacle detection.
- Integrate Bluetooth or Wi-Fi for remote control.
- Implement path planning for more complex navigation.

