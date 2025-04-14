# 🚗 Remote_Control

An Arduino-powered robotic car with multiple driving modes:

- 🕹️ **Bluetooth Remote Control**
- 🧭 **Line Tracking**
- 🚧 **Obstacle Avoidance**

---

## 📦 Features

- Control the car using a smartphone ELEEGO app or serial terminal via Bluetooth.
- Detect and follow black lines using 3 IR sensors.
- Automatically avoid obstacles using an ultrasonic sensor mounted on a servo.
- All commands are communicated via JSON over serial.

---

## 🔌 Hardware Setup

| Component                   | Pin(s)    |
|----------------------------|-----------|
| **Ultrasonic Sensor**      | TRIG: A5, ECHO: A4 |
| **IR Line Sensors**        | Left: 2, Middle: 4, Right: 10 |
| **Servo Motor**            | 3         |
| **Motor Driver ENA / ENB** | 5 / 6     |
| **Motor Driver IN1–IN4**   | 7, 8, 9, 11 |
| **Bluetooth Module (HC-05)** | TX/RX (Serial) |

---

## 🧠 Modes

### 1. Bluetooth Remote Control Mode

- **Description:** Accepts movement commands from a Bluetooth device (e.g., smartphone).
- **Activation Command:** `{ "N": 5, "H": <id> }`
- **Movement Commands:**  
  Send: `{ "N": 2, "D1": <direction_code>, "H": <id> }`  
  Response: `{<id>_ok}`

| Direction Code (`D1`) | Action     |
|-----------------------|------------|
| 1                     | Turn Left  |
| 2                     | Turn Right |
| 3                     | Forward    |
| 4                     | Backward   |
| 5                     | Stop       |

---

### 2. Line Tracking Mode

- **Activation Command:** `{ "N": 3, "D1": 1, "H": <id> }`
- Follows black line using IR sensors.
- Adjusts direction based on sensor input.

---

### 3. Obstacle Avoidance Mode

- **Activation Command:** `{ "N": 3, "D1": 2, "H": <id> }`
- Scans for obstacles using ultrasonic sensor.
- Turns away based on proximity readings (left, front, right).

---

## 🔄 Command Flow

1. The function `getBTData_Plus()` continuously reads and parses incoming serial data.
2. If a valid JSON command is received:
   - Sets the operating mode (`func_mode`).
   - Sets the movement mode (`mov_mode`).
3. The loop processes the current mode:
   - `bluetooth_mode()` → Executes movement command.
   - `line_teacking_mode()` → Follows the line.
   - `obstacles_avoidance_mode()` → Scans and avoids obstacles.

---

## ⚙️ Setup Instructions

1. Clone or download the repository.
2. Install the **ArduinoJson v6.11.1** library.
3. Connect your Arduino-compatible board.
4. Upload the code using the Arduino IDE.
5. Pair your phone or computer with the HC-05 Bluetooth module.
6. Use a serial app or custom UI to send JSON commands.

---

## 🛠️ Requirements

- Arduino IDE
- HC-05 Bluetooth module
- Arduino-compatible board (Uno, Nano, etc.)
- L298N Motor Driver
- Ultrasonic sensor (HC-SR04)
- 3x IR Sensors
- Servo motor

---

## 🧪 Example Commands

- Set mode to Bluetooth and stop:  
  `{ "N": 5, "H": 1 }`

- Move forward in Bluetooth mode:  
  `{ "N": 2, "D1": 3, "H": 2 }`

- Switch to line tracking mode:  
  `{ "N": 3, "D1": 1, "H": 3 }`

---

## 🙌 Acknowledgements

Developed by **HOU Changhua**  
Initial release: **August 2019**
