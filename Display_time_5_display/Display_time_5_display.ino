#include <TM1637.h>

const int button = D8;
const int Relay1 = D7;

#define CLK D5
#define DIO D6
TM1637 Display1(CLK, DIO);

#define BRIGHT_DARKEST 2
#define CHAR_BLANK 127

int button_read = 0;

const int displayTime_1 = D0;
const int displayTime_2 = D1;
const int displayTime_3 = D2;
const int displayTime_4 = D3;
const int displayTime_5 = D4;

int timeRead_1 = 0;
int timeRead_2 = 0;
int timeRead_3 = 0;
int timeRead_4 = 0;
int timeRead_5 = 0;


void setup() {
  Serial.begin(115200);
  pinMode(displayTime_1, INPUT);
  pinMode(displayTime_2, INPUT);
  pinMode(displayTime_3, INPUT);
  pinMode(displayTime_4, INPUT);
  pinMode(displayTime_5, INPUT);

  pinMode(button, INPUT);
  pinMode(Relay1, OUTPUT);
  digitalWrite(Relay1, HIGH);

  Display1.init();
  Display1.set(BRIGHT_DARKEST);
}

void loop() {

  int timeSwitcn = 0;
  button_read = digitalRead(button);

  timeRead_1 = digitalRead(displayTime_1);
  timeRead_2 = digitalRead(displayTime_2);
  timeRead_3 = digitalRead(displayTime_3);
  timeRead_4 = digitalRead(displayTime_4);
  timeRead_5 = digitalRead(displayTime_5);
  if (timeRead_1 == 1) {
    timeSwitcn = timeRead_1;
    Display1.point(POINT_ON);
    Display1.display(1, 1);
    Display1.display(2, 0);
    Display1.display(3, 0);


  } else if (timeRead_2 == 1) {
    timeSwitcn = timeRead_2 + 1;
    Display1.point(POINT_ON);
    Display1.display(1, 2);
    Display1.display(2, 0);
    Display1.display(3, 0);


  } else if (timeRead_3 == 1) {
    timeSwitcn = timeRead_3 + 2;
    Display1.point(POINT_ON);
    Display1.display(1, 3);
    Display1.display(2, 0);
    Display1.display(3, 0);

  } else if (timeRead_4 == 1) {
    timeSwitcn = timeRead_4 + 3;
    Display1.point(POINT_ON);
    Display1.display(1, 4);
    Display1.display(2, 0);
    Display1.display(3, 0);

  } else if (timeRead_5 == 1) {
    timeSwitcn = timeRead_5 + 4;
    Display1.point(POINT_ON);
    Display1.display(1, 5);
    Display1.display(2, 0);
    Display1.display(3, 0);

  } else {
    Display1.display(1, 4);
    Display1.display(2, 0);
    Display1.display(3, 4);
    Display1.point(POINT_OFF);

  }

  pinMode(displayTime_1, OUTPUT);
  pinMode(displayTime_2, OUTPUT);
  pinMode(displayTime_3, OUTPUT);
  pinMode(displayTime_4, OUTPUT);
  pinMode(displayTime_5, OUTPUT);
  digitalWrite(displayTime_1, LOW);
  digitalWrite(displayTime_2, LOW);
  digitalWrite(displayTime_3, LOW);
  digitalWrite(displayTime_4, LOW);
  digitalWrite(displayTime_5, LOW);

  if (button_read == 1) {
    button_read = 0;
    delay(1000);
    switch (timeSwitcn) {
      case 1:
        for (int z = 0; z >= 0; z--) {
          Display1.display(1, z); // แสดงเลข 1 ที่หลัก 0
          digitalWrite(Relay1, LOW);
          for (int i = 5; i >= 0; i--) {
            Display1.display(2, i); // แสดงเลข 2 ที่หลัก 1
            for (int j = 9; j >= 0; j--) {
              Display1.display(3, j); // แสดงเลข 5 ที่หลัก 2
              if (digitalRead(button) == 1) {
                break;
              }
              delay(1000);
            }
          }
        }
        digitalWrite(Relay1, HIGH);
        delay(1000);
        break;

      case 2:
      delay(1000);
        for (int z = 1; z >= 0; z--) {
          Display1.display(1, z); // แสดงเลข 1 ที่หลัก 0
          for (int i = 5; i >= 0; i--) {
            Display1.display(2, i); // แสดงเลข 2 ที่หลัก 1
            for (int j = 9; j >= 0; j--) {
              Display1.display(3, j); // แสดงเลข 5 ที่หลัก 2
              digitalWrite(Relay1, LOW);
              if (digitalRead(button) == 1) {
                break;
              }
              delay(1000);
            }
          }
        }
        digitalWrite(Relay1, HIGH);
        delay(1000);
        break;

      case 3:
      delay(1000);
        for (int z = 2; z >= 0; z--) {
          Display1.display(1, z); // แสดงเลข 1 ที่หลัก 0
          for (int i = 5; i >= 0; i--) {
            Display1.display(2, i); // แสดงเลข 2 ที่หลัก 1
            for (int j = 9; j >= 0; j--) {
              Display1.display(3, j); // แสดงเลข 5 ที่หลัก 2
              digitalWrite(Relay1, LOW);
              if (digitalRead(button) == 1) {
                break;
              }
              delay(1000);
            }
          }
        }
        digitalWrite(Relay1, HIGH);
        delay(1000);
        break;

      case 4:
      delay(1000);
        for (int z = 3; z >= 0; z--) {
          Display1.display(1, z); // แสดงเลข 1 ที่หลัก 0
          for (int i = 5; i >= 0; i--) {
            Display1.display(2, i); // แสดงเลข 2 ที่หลัก 1
            for (int j = 9; j >= 0; j--) {
              Display1.display(3, j); // แสดงเลข 5 ที่หลัก 2
              digitalWrite(Relay1, LOW);
              if (digitalRead(button) == 1) {
                break;
              }
              delay(1000);
            }
          }
        }
        digitalWrite(Relay1, HIGH);
        delay(1000);
        break;

      case 5:
      delay(1000);
        for (int z = 4; z >= 0; z--) {
          Display1.display(1, z); // แสดงเลข 1 ที่หลัก 0
          for (int i = 5; i >= 0; i--) {
            Display1.display(2, i); // แสดงเลข 2 ที่หลัก 1
            for (int j = 9; j >= 0; j--) {
              Display1.display(3, j); // แสดงเลข 5 ที่หลัก 2
              digitalWrite(Relay1, LOW);
              if (digitalRead(button) == 1) {
                break;
              }
              delay(1000);
            }
          }
        }
        digitalWrite(Relay1, HIGH);
        delay(1000);
        break;
    }
  }
}
