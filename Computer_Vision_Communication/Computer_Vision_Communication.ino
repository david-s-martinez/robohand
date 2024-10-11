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

  Serial.begin(115200);
  Serial.setTimeout(1);
  
  // Initial position: All fingers stretched (open)
  index.write(0);
  thumb.write(0);
  ring.write(0);
  middle.write(0);
  pinky.write(0);
  delay(4000);
}

void loop() {
  while (!Serial.available());
  String x = Serial.readString();  // Read input as string
  x.trim();  // Remove any newline or spaces

  if (x == "b") {
    closeAllFingers(15);  // Slowly close all fingers
  } else if (x == "k") {
    closeFingersExceptIndex(5);    // Close all fingers except index
    openAndCloseFinger(index, 5);  // Index opens and closes once
  } else if (x == "m") {
    closeFingersExceptIndexMiddle(5); // Close all except index and middle
    openAndCloseFinger(index, 5);     // Index opens and closes twice
    openAndCloseFinger(index, 5);
    openAndCloseFinger(middle, 5);    // Middle opens and closes twice
    openAndCloseFinger(middle, 5);
  }
}

// Function to close all fingers progressively
void closeAllFingers(int speedDelay) {
  for (int pos = 0; pos <= 120; pos++) {
    index.write(pos);
    thumb.write(pos);
    ring.write(pos);
    middle.write(pos);
    pinky.write(pos);
    delay(speedDelay);
  }
}

// Function to close all fingers except the index
void closeFingersExceptIndex(int speedDelay) {
  for (int pos = 0; pos <= 120; pos++) {
    thumb.write(pos);
    ring.write(pos);
    middle.write(pos);
    pinky.write(pos);
    delay(speedDelay);
  }
}

// Function to close all fingers except the index and middle
void closeFingersExceptIndexMiddle(int speedDelay) {
  for (int pos = 0; pos <= 120; pos++) {
    thumb.write(pos);
    ring.write(pos);
    pinky.write(pos);
    delay(speedDelay);
  }
}

// Function to open and close a single finger
void openAndCloseFinger(Servo &finger, int speedDelay) {
  // Open (stretch) the finger
  for (int pos = 120; pos >= 0; pos--) {
    finger.write(pos);
    delay(speedDelay);
  }
  // Close (contract) the finger
  for (int pos = 0; pos <= 120; pos++) {
    finger.write(pos);
    delay(speedDelay);
  }
}
