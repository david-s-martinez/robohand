#include <Servo.h>

Servo index;
Servo thumb;
Servo ring;
Servo middle;
Servo pinky;

void setup() {
  index.attach(4);
  thumb.attach(5);
  ring.attach(6);
  middle.attach(9);
  pinky.attach(10);
  index.write(0);
  thumb.write(0);
  ring.write(0);
  middle.write(0);
  pinky.write(0);
  delay(4000);
}

void loop() {
  index.write(0);
  thumb.write(0);
  ring.write(0);
  middle.write(0);
  pinky.write(0);
  delay(4000);
  index.write(0);
  thumb.write(0);
  ring.write(0);
  middle.write(0);
  pinky.write(0);
  delay(4000);
}
