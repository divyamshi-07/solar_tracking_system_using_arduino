#include <Servo.h>

Servo solarServo;

// LDR pins
int ldrLeft = A0;
int ldrRight = A1;

// Servo position
int servoPos = 90;

void setup() {
  solarServo.attach(9);   // Servo connected to pin 9
  solarServo.write(servoPos);

  Serial.begin(9600);
}

void loop() {

  int leftValue = analogRead(ldrLeft);
  int rightValue = analogRead(ldrRight);

  Serial.print("Left LDR: ");
  Serial.print(leftValue);
  Serial.print("  Right LDR: ");
  Serial.println(rightValue);

  int threshold = 50;   // Sensitivity threshold

  if (leftValue - rightValue > threshold) {
    servoPos--;
    if (servoPos < 0) servoPos = 0;
    solarServo.write(servoPos);
  }

  else if (rightValue - leftValue > threshold) {
    servoPos++;
    if (servoPos > 180) servoPos = 180;
    solarServo.write(servoPos);
  }

  delay(100);
}