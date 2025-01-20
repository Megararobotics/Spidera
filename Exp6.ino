#include <Servo.h>

Servo J1; 
Servo J2;
Servo J3; 
Servo J4; 
Servo J5;
Servo J6;
Servo J7; 
Servo J8;
Servo J9;
Servo J10; 
Servo J11;
Servo J12;
char data;

void cS1(int ang1, int ang2, int ang3){
  J1.write(ang1);
  J2.write(ang2);
  J3.write(ang3);
}
void cS2(int ang4, int ang5, int ang6){
  J4.write(ang4);
  J5.write(ang5);
  J6.write(ang6);
}
void cS3(int ang7, int ang8, int ang9){
  J7.write(ang7);
  J8.write(ang8);
  J9.write(ang9);
}
void cS4(int ang10, int ang11, int ang12){
  J10.write(ang10);
  J11.write(ang11);
  J12.write(ang12);
}

void setup() {
  Serial.begin(9600);
  J1.attach(4); 
  J2.attach(3);
  J3.attach(2); 
  J4.attach(7); 
  J5.attach(6);
  J6.attach(5);
  J7.attach(10); 
  J8.attach(9);
  J9.attach(8); 
  J10.attach(13); 
  J11.attach(12);
  J12.attach(11);
}

void loop() {
  if (Serial.available()) {
    data = Serial.read();
    Serial.print(data);
    Serial.print("\n");
    if (data == 'a') { // Walk forward
      walkForward();
    } else if (data == 'b') { // Lay down
      layDown();
    } else if (data == 'r') { // Turn right
      turnRight();
    } else if (data == 'l') { // Turn left
      turnLeft();
    } else if (data == 't') { // Turn
      turn();
    } else if (data == 'u') { // Up and down motion
      updown();
    } else if (data == 'i') { // Back motion
      backmotion();
    } else if (data == 'z') { // Walk backward
      walkBackward();
    } else {
      stand();
    }
  }
}

void walkForward() {
  cS1(140, 140, 80);
  cS2(60, 110, 80);
  cS3(140, 105, 80);
  cS4(40, 110, 80);
  delay(500);
}

void walkBackward() {
  cS1(70, 140, 80);
  cS2(130, 110, 80);
  cS3(70, 105, 80);
  cS4(130, 110, 80);
  delay(500);
}

void layDown() {
  cS1(90, 70, 90);
  cS2(90, 55, 90);
  cS3(90, 50, 90);
  cS4(90, 55, 90);
  delay(500);
}

void turnRight() {
  cS1(90, 90, 80);
  cS2(40, 110, 80);
  cS3(40, 105, 80);
  cS4(70, 110, 80);
  delay(500);
}

void turnLeft() {
  cS1(40, 140, 80);
  cS2(140, 110, 80);
  cS3(140, 105, 80);
  cS4(40, 110, 80);
  delay(500);
}

void turn() {
  cS1(40, 140, 80);
  cS2(40, 110, 80);
  cS3(40, 105, 80);
  cS4(40, 110, 80);
  delay(2000);
}

void updown() {
  cS1(90, 180, 120);
  cS2(90, 160, 120);
  cS3(110, 155, 120);
  cS4(70, 160, 120);
  delay(2000);
  cS1(90, 50, 30);
  cS2(90, 30, 30);
  cS3(110, 25, 30);
  cS4(70, 30, 30);
  delay(2000);
}

void backmotion() {
  cS1(70, 140, 60);
  cS2(130, 110, 60);
  cS3(70, 105, 60);
  cS4(110, 110, 60);
}

void stand() {
  cS1(90, 140, 80);
  cS2(90, 110, 80);
  cS3(110, 105, 80);
  cS4(70, 110, 80);
}
