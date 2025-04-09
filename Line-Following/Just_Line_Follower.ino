// Author: Arshia Keshvari
// Date: 1.11.2021
// Final Version

# include <Wire.h> // Allows to communicate to I2C / TWI devices

// Defining the pins
#define LT_R digitalRead(10)      // Right Sensor
#define LT_M digitalRead(4)       // Middle Sensor
#define LT_L digitalRead(2)       // Left Sensor
#define ENA 5                     // Left Motor
#define ENB 6                     // Right Motor
#define IN1 7                     // Wheel 1
#define IN2 8                     // Wheel 2
#define IN3 9                     // Wheel 3
#define IN4 11                    // Wheel 4
#define carSpeed 150              // Max Car Speed is 255

// We have to give wheel conditions boolean logic and carspeed will have to have an integer return
void Movement(bool, bool, bool, bool, int);
void FollowLine();

// What we want the car robot to do except the back function as it is not useful for line follower
void forward(); void left(); void right(); void Stop(); void back();

// Assign pin modes to all defined pins at the start of the program
void setup() {
  Serial.begin(9600);   // set baud rate to 9600
  pinMode(LT_R, INPUT);
  pinMode(LT_M, INPUT);
  pinMode(LT_L, INPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
}

// Follow line function will be looped in the entire runtime of the program
void loop() {FollowLine();}

// Defining movement of motors with respect to wheels
void Movement(bool BoolIN1, bool BoolIN2, bool BoolIN3, bool BoolIN4, int CarSpeed4Function = carSpeed){
  analogWrite(ENA, CarSpeed4Function);
  analogWrite(ENB, CarSpeed4Function);
  digitalWrite(IN1, BoolIN1);
  digitalWrite(IN2, BoolIN2);
  digitalWrite(IN3, BoolIN3);
  digitalWrite(IN4, BoolIN4);

}
// Stating movement conditions for motors
void forward() {Movement(HIGH, LOW, LOW, HIGH);}                  // Move forward

void left() {Movement(LOW, HIGH, LOW, HIGH);}                     // Move left

void right() {Movement(HIGH, LOW, HIGH, LOW);}                    // Move right

void stop() {digitalWrite (ENA, LOW); digitalWrite (ENB, LOW);}   // Stop

void back(){Movement(LOW, HIGH, HIGH, LOW);}                      // Move backwards not needed but could be useful for object avoidance and bluetooth

// Stating which movement to use under sensor conditions
void FollowLine(){
  if (LT_L == LOW && LT_M == HIGH && LT_R == LOW) {forward();}
  
  else if (LT_L == LOW && LT_M == LOW && LT_R == HIGH) {right();}
 
  else if (LT_L == HIGH && LT_M == LOW && LT_R == LOW) {left();}
 
  else if (LT_L == LOW && LT_M == HIGH && LT_R == HIGH) {right();}
  
  else if (LT_L == HIGH && LT_M == HIGH && LT_R == LOW) {left();}
  
  else if(LT_L == LOW && LT_M == LOW && LT_R == LOW){stop();}
  
  else if(LT_L == HIGH && LT_M == HIGH && LT_R == HIGH){stop();}

  else {stop(); }
}
