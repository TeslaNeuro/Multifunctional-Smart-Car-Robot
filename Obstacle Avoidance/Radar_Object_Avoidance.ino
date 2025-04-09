/* 
   Object Avoidance using Ultrasonic Sensor
   Authour: Arshia
   09/04/2022
*/

// TO ADJUST SPEED OF THE MOTORS LOOK AT THE END OF THE CODE AND CHANGE NUMBERS

#include <Servo.h>
Servo servo;

int angle = 0;      // Position or angle of servo motor
int Direction = 0;  // Direction of ultrasonic sensor

int leftD = 0;      // Left Distance
int rightD = 0;     // Right Distance

int echo = A4;      // Ultrasonic Echo pin
int trig = A5;      // Ultrasonic Trigger pin

#define ENA 5       // controls speed Motors A
#define ENB 6       // controls speed Motors B
#define IN1 7       // Left front motor
#define IN2 8       // Left back motor
#define IN3 9       // Right back motor
#define IN4 11      // Right front motor

/* uint8_t CarSpeed = 200; //PWM value for maximum speed. */

// We have to give wheel conditions boolean logic and carspeed will have to have a unsigned 8 bit integer return
void Movement(bool, bool, bool, bool, uint8_t);

// What we want the car robot to do
void forward(); void left(); void right(); void stop(); void back();


void setup() {
  Serial.begin(9600);         // baud rate
  servo.attach(3, 500, 2400); // 3: pin , 500: 0 degree , 2400: 180 degree
  servo.write(90);            // Sets the servo position according to the 90（middle）
  
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);    
  
  pinMode(IN1,OUTPUT); 
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  stop(); // Stop motors at start
}

// Keep going forward but always check for objects using ultrasonic sensor
// and check servo motor positions. If object is discovered at that specific angle
// change directions. For loop and if conditional statements do this well.
void loop() {
  forward();
  servoctrl();
}

void servoctrl(){
  while (Direction<1){
  for(angle=30; angle<=170; angle+=15){
    if (angle>=170){
      angle=leftD;
      leftD=distance_();
    }
    if (angle<=30){
      angle=rightD;
      rightD=distance_();
    }
    servo.write(angle);
    if (distance_()<=30){
      stop();
      delay(10);
      if (rightD > leftD){
        back();
        delay(50);
        right();
        delay(100);
      }
      else if (rightD < leftD){
        back();
        delay(50);
        left();
        delay(100);
      }
      else if((rightD <= 20) && (leftD <= 20)){
        back();
        delay(50);
      }
    }
    delay(50); // decrease this to increase speed of the motor
    Direction+=1;
  }
  }
  while (Direction>=1){
  for(angle=170; angle>=30; angle-=15){
    if (angle>=170){
      angle=leftD;
      leftD=distance_();
    }
    if (angle<=30){
      angle=rightD;
      leftD=distance_();
    }
    servo.write(angle);
    if (distance_()<=30){
      stop();
      delay(10);
      if (rightD > leftD){
        back();
        delay(50);
        right();
        delay(100);
      }
      else if (rightD < leftD){
        back();
        delay(50);
        left();
        delay(100);
      }
      else if((rightD <= 20) && (leftD <= 20)){
        back();
        delay(50);
      }
    }
    delay(50); // decrease this to increase speed of the motor
    Direction-=1;
    }
  }
}

// Ultrasonic sensor distance calculation
int distance_() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  unsigned long duration = pulseIn(echo, HIGH); // Integer should do fine float or long are a little more accurate
  int distance = duration/58;
  return distance;       
}

// Defining movement of motors with respect to wheels
void Movement(bool BoolIN1, bool BoolIN2, bool BoolIN3, bool BoolIN4, uint8_t CarSpeed4Function){
  analogWrite(ENA, CarSpeed4Function);
  analogWrite(ENB, CarSpeed4Function);
  digitalWrite(IN1, BoolIN1);
  digitalWrite(IN2, BoolIN2);
  digitalWrite(IN3, BoolIN3);
  digitalWrite(IN4, BoolIN4);
}

// Stating movement conditions for motors
void forward() {Movement(HIGH, LOW, LOW, HIGH, 200);}            // Motor will spin forward

void left() {Movement(LOW, HIGH, LOW, HIGH, 200);}               // Motor will spin to the left

void right() {Movement(HIGH, LOW, HIGH, LOW, 200);}              // Motor will spin to the right

void back(){Movement(LOW, HIGH, HIGH, LOW, 200);}                // Motor will spin in reverse

void stop() {digitalWrite (ENA, LOW); digitalWrite (ENB, LOW);}  // will stop motors from moving
