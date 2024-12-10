# Line Follower Robot Code

## Introduction
This project controls a line-following robot using an Arduino microcontroller. The robot detects a line on the ground using three sensors and adjusts its movement by controlling two DC motors. The code is modular, making it easy to expand or adapt for additional functionalities like obstacle avoidance or remote control.

---

## Features
- **Line Detection**: Uses three sensors (left, middle, and right) to track a line.
- **Dynamic Movement**: Smooth transitions between forward, left, and right movements based on sensor input.
- **Speed Control**: Adjustable motor speed to suit different environments or track designs.
- **Modular Design**: Easy to integrate additional functionalities like object detection, wireless control, or advanced pathfinding.

---

## Hardware Requirements
1. **Microcontroller**: Arduino Uno or similar.
2. **Line Sensors**: Three reflective optical sensors for detecting the line.
3. **Motor Driver Module**: Dual H-Bridge (e.g., L298N or L293D) to drive two DC motors.
4. **DC Motors**: Two motors with wheels for movement.
5. **Power Source**: Batteries (e.g., LiPo, 18650 cells) to power the motors and Arduino.
6. **Robot Chassis**: Base for mounting components (e.g., wheels, sensors, motor driver).
7. **Connecting Wires**: For proper connections between components.

---

## Pin Configuration
| Pin   | Component           | Description                    |
|-------|----------------------|--------------------------------|
| `2`   | Left Sensor (LT_L)  | Detects line on the left       |
| `4`   | Middle Sensor (LT_M)| Detects line in the middle     |
| `10`  | Right Sensor (LT_R) | Detects line on the right      |
| `5`   | ENA                 | Speed control for left motor   |
| `6`   | ENB                 | Speed control for right motor  |
| `7`   | IN1                 | Controls direction for left motor (Wheel 1) |
| `8`   | IN2                 | Controls direction for left motor (Wheel 2) |
| `9`   | IN3                 | Controls direction for right motor (Wheel 3)|
| `11`  | IN4                 | Controls direction for right motor (Wheel 4)|

---

## Code Explanation

### Initialization (`setup`)
- Assigns pin modes:
  - Sensors are configured as inputs.
  - Motor driver pins are configured as outputs.
- Sets up serial communication at 9600 baud for debugging.

### Continuous Operation (`loop`)
- Repeatedly calls the `FollowLine()` function to evaluate sensor input and adjust motor movement accordingly.

### Modular Functions
1. **`Movement(bool BoolIN1, bool BoolIN2, bool BoolIN3, bool BoolIN4, int CarSpeed4Function = carSpeed)`**  
   Central function to control motor movement.  
   - Accepts boolean inputs for motor directions and an optional speed parameter.  
   - Allows fine-tuned movement control.

2. **Predefined Movements**:
   - **`forward()`**: Moves the robot straight ahead.
   - **`left()`**: Turns the robot left.
   - **`right()`**: Turns the robot right.
   - **`stop()`**: Stops all motors to halt the robot.
   - **`back()`**: Moves the robot backward (not used in this program but available for extensions).

3. **Line Following Logic (`FollowLine`)**:
   - Reads the state of the three sensors:
     - **Middle sensor active**: Move forward.
     - **Right sensor active**: Turn right.
     - **Left sensor active**: Turn left.
     - **No sensors active**: Stop (robot is off-track).
     - **All sensors active**: Stop (end of the track or error state).
   - Decides the appropriate movement based on the sensor states.

---

## Usage Instructions
1. **Assemble the Hardware**: Connect all components as per the Pin Configuration table.
2. **Upload Code**: Load the program onto the Arduino using the Arduino IDE.
3. **Calibrate Sensors**: Ensure the sensors correctly detect the track (black line on a white surface or vice versa).
4. **Power On**: Power the Arduino and motors to activate the robot.
5. **Test Movement**: Place the robot on the track and observe its performance.

---

## Scalability and Expansion Ideas
This code is designed to be a starting point for a wide range of robotics applications. Below are some ideas for extending its functionality:
1. **Obstacle Avoidance**:
   - Add ultrasonic or infrared sensors to detect and avoid obstacles.
   - Integrate logic to navigate around objects while staying on track.

2. **Wireless Control**:
   - Use a Bluetooth or Wi-Fi module for remote control and monitoring.
   - Incorporate a mobile app or web interface to control the robot manually.

3. **Advanced Line Following**:
   - Add more sensors for better accuracy on complex tracks.
   - Implement PID control for smoother movement and better line adherence.

4. **Autonomous Features**:
   - Include a mapping system to navigate predefined paths.
   - Integrate GPS for outdoor navigation.

5. **Power Efficiency**:
   - Use energy-efficient motors and optimize speed for battery longevity.
   - Implement sleep modes for idle states.

---

## Troubleshooting
1. **Robot Doesn’t Move**:
   - Check power connections to the Arduino and motors.
   - Ensure the motor driver is properly connected.

2. **Robot Moves Erratically**:
   - Verify sensor alignment and calibration.
   - Adjust motor speed if the robot is too fast for accurate line detection.

3. **Sensors Not Detecting Line**:
   - Check the wiring and ensure sensors are functional.
   - Test with different track surfaces or adjust lighting conditions.

---

## Notes
- Ensure proper insulation of wires to prevent short circuits.
- Regularly check battery levels to maintain consistent performance.
- Customize `carSpeed` to match your robot’s speed requirements.

This program is flexible and designed to grow with your project. Have fun experimenting and innovating!
