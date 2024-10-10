#include <Servo.h>
Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
int x;
void setup() {
  myservo.attach(6);  // attaches the servo on pin 9 to the servo object
  Serial.begin(115200);
  Serial.setTimeout(1);
  
}

void loop() {
  while (!Serial.available());
  x = Serial.readString().toInt();
  Serial.print(x + 1); // send back message to confirm script got it
  
  for (pos = 0+x; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0+x; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
}
