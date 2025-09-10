// moveFront(); moveBack(); moveLeft(); moveRight();

#include "MotorControl.h"

void setup()
{
  Serial.begin(115200);
  pinConfig();
  
}

void loop()
{
  int distance = getDistance();
  Serial.println(distance);
  delay(200);
  if(distance <= 15)
  {
    mopOFF(0);
    stop();
    delay(1000);
    moveBack(255);
    delay(1000);
    moveRight(255);
    delay(1000);
    stop();
  }
  if(distance > 10)
  {
    moveFront(255);
    mopOn(200);
  }
}

int getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  long distance = duration * 0.034 / 2;

  return distance;
}
