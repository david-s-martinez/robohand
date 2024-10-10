#include <Servo.h>

//create Servo objects
Servo index;
Servo thumb;
Servo ring;
Servo middle;
Servo pinky;
Servo fingers[5] = {thumb, index, middle, ring, pinky};

//define servo positions
int positions[5] = {0, 0, 0, 0, 0};
int new_positions[5];

//remember the current classifications
char current_mode = 'b';
char new_mode;

//index used for sequential movement for a specific mode to keep track of what was already done before
int index = 0;


void setup() {
  index.attach(4);
  thumb.attach(5);
  ring.attach(6);
  middle.attach(9);
  pinky.attach(10);
  for (Servo element : fingers){
    element.write(0);
  }
  delay(4000);
}

void loop() {
  
  //scan computer vision classification
  //get new mode
  char new_mode = 'm';
  
  if (new_mode != current_mode){
    current_mode = new_mode;
    index = 0;
    
    //reset fingers to starting position
    for (int i = 0; i < 5; i++){
      if (positions[i] != 0){
        fingers[i].write(0);
      }
    }
    positions = {0, 0, 0, 0, 0};
    delay(2000);
  }

  //corresponding to classification change the servo positions
  switch (current_mode){

    //bottle
    case 'b':

      new_positions = {0, 120, 120, 120, 120};
      break;

    //maus
    case 'm':

      switch (index){
        case 0:
          new_positions = {120, 0, 0, 120, 120};
          break;

        case 1:
          new_positions = {120, 120, 0, 120, 120};
          break;

        case 2:
          new_positions = {120, 0, 120, 120, 120};
          break;

        default:
          index = 0;
          new_positions = {120, 0, 0, 120, 120};
          break;
      }

      index = index + 1;
      break;

    //keyboard
    case 'k':

      if (index == 0) {
        new_positions = {120, 0, 120, 120, 120};
        index = 1;
      } else {
        new_positions = {120, 120, 120, 120, 120};
        index = 0;
      }

      break;
    
    //remote control
    case 'r':
      new_positions = {120, 120, 120, 120, 120};
      break;

    default:
      new_positions = {0, 0, 0, 0, 0};
      break;

  }

  // set the servos to the new position
  for (int i = 0; i < 5; i++){
    if (positions[i] != new_positions[i]){
      fingers[i].write(new_positions[i]);
    }
  }
  positions = new_positions;
  delay(2000);  
}
