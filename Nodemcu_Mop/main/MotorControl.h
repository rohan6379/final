#ifndef MOTORCONTROL_H
#define MOTORCONTROL_H
/*
  moveFront(); moveBack(); moveLeft(); moveRight();
*/


// Motor A pins (Left Motor)
#define IN1 12   // GPIO5
#define IN2 13   // GPIO4
#define ENA 10   // GPIO0

// Motor B pins (Right Motor)
#define IN3 8   // GPIO14
#define IN4 9   // GPIO12
#define ENB 11   // GPIO13

#define IN5 4   // GPIO14
#define IN6 3   // GPIO12
#define ENC 5   // GPIO13

int trigPin = 7;
int echoPin = 6;

void pinConfig() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);

  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(IN5, OUTPUT);
  pinMode(IN6, OUTPUT);
  pinMode(ENC, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}
//
// === Movement Functions ===
//

// Move both motors forward
void moveFront(int speed) {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, speed);

  digitalWrite(IN3, 0);
  digitalWrite(IN4, 1);
  analogWrite(ENB, speed);
}

// Move both motors backward
void moveBack(int speed) {
  digitalWrite(IN1, 0);
  digitalWrite(IN2, 1);
  analogWrite(ENA, speed);

  digitalWrite(IN3, 1);
  digitalWrite(IN4, 0);
  analogWrite(ENB, speed);
  
}

// Turn left: stop left motor, run right motor
void moveLeft(int speed) {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0); // Left motor stopped

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, speed); // Right motor forward
}

// Turn right: run left motor, stop right motor
void moveRight(int speed) {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, speed); // Left motor forward

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 0); // Right motor stopped
}

// Stop both motors
void stop() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void mopOn(int speed)
{
  digitalWrite(IN5, HIGH);
  digitalWrite(IN6, LOW);
  analogWrite(ENC, speed);
}

void mopOFF(int speed)
{
  digitalWrite(IN5, LOW);
  digitalWrite(IN6, LOW);
  analogWrite(ENC, speed);
}



#endif
