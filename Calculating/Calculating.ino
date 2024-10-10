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

  int one = 100;
  int two = 55;
  char operator = '+';
  int result = 0;

  switch (operator) {
    case '+':
      result = one + two;
      break;
    case '-':
      result = one - two;
      break;
    case '*':
      result = one * two;
      break;
    case '/':
      if (two == 0) {
        result = -1;
        print("No division by zero allowed!");
      } else {
        result = one / two;
      }
      break;
    default:
      print("Operation is not recognized! Please type in '+', '-', '*' or '/'!");
      //Read
      break;
  }

  if (result < 0) {
    print("Result can not be displayed!");
    ring.write(120);
    middle.write(120);
    delay(2000);
    index.write(0);
    thumb.write(0);
    ring.write(0);
    middle.write(0);
    pinky.write(0);
    delay(2000);
    ring.write(120);
    middle.write(120);
    delay(8000);
  } else {
    print("Result is:");
    print(result);

    divisor = 1;

    while (true){
      n = result / divisor;
      if (n < 10) {
        break;
      } else {
        divisor = divisor * 10;
      }
    }

    while (true){
      number = result / divisor;

      switch (number) {
        case 0:
          index.write(0);
          thumb.write(0);
          ring.write(0);
          middle.write(0);
          pinky.write(0);
          
          break;
        case 1:
          break;
        case 2:
          break;
        case 3:
          break;
        case 4:
          break;
        case 5:
          break;
        case 6:
          break;
        case 7:
          break;
        case 8:
          break;
        case 9:
          break;
        default:
          break;
      }

      result = result - number * divisor;

      if (divisor == 1){
        break;
      } else {
        divisor = divisor / 10;
      }
    }
  }
  index.write(0);
  thumb.write(0);
  ring.write(0);
  middle.write(0);
  pinky.write(0);
  delay(4000);
}
