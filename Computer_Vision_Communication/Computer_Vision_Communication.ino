#include <Servo.h>
Servo myservo;  // create servo object to control a servo

void setup() {
  myservo.attach(6);  // attaches the servo on pin 6 to the servo object
  Serial.begin(115200);
  Serial.setTimeout(1);
}

void loop() {
  while (!Serial.available());
  String x = Serial.readString();  // Read input as string
  x.trim();  // remove any newline or spaces
  
  if (x == "b") {
    moveServoProgressively(0, 180, 15);  // Slow move from 0 to 180
  } else if (x == "k") {
    moveServoProgressively(0, 90, 5);    // Fast move from 0 to 90
  } else if (x == "m") {
    moveServoProgressively(0, 90, 5);    // Fast move from 0 to 90 twice
    moveServoProgressively(0, 90, 5);
  }
}

// Function to move the servo progressively from startPos to endPos with a delay
void moveServoProgressively(int startPos, int endPos, int speedDelay) {
  // Moving servo from startPos to endPos
  for (int pos = startPos; pos <= endPos; pos++) {
    myservo.write(pos);
    delay(speedDelay);
  }

  // Optionally move back to the start position
  for (int pos = endPos; pos >= startPos; pos--) {
    myservo.write(pos);
    delay(speedDelay);
  }
}
