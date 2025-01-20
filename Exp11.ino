#include <Servo.h>
#include <NewPing.h>

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

#define TRIG_PIN  12  // Change to your ultrasonic trigger pin
#define ECHO_PIN  11  // Change to your ultrasonic echo pin
#define MAX_DISTANCE 200  // Max distance (in cm) to check for

NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);  // Initialize ultrasonic sensor

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
  data = Serial.read();
  Serial.print(data);
  Serial.print("\n");
  if (data == 'a') { // Walk forward
    while (Serial.read() != 's') { // Continue walking until 's' is received
      walkForward();
    }
  } else if (data == 'b') { // Lay down
    layDown();
  } else if (data == 'r'){
    while (Serial.read() != 's')
      turnright();
  } else if (data == 'l'){
    while (Serial.read() != 's')
      turnleft();
  } else if (data == 't'){
    while (Serial.read() != 's')
      turn();
  } else if (data == 'u'){
    while (Serial.read() != 's')
      updown();    
  } else if (data == 'i'){
    while (Serial.read() != 's')
      backmotion();    
  } else if (data == 'z'){
    while (Serial.read() != 's')
      walkBackward();    
  }
  else {
    stand();
  }
}

void walkForward() {
  // Get the distance from the ultrasonic sensor
  int distance = sonar.ping_cm();

  // If the obstacle is detected at 30 cm or less, reduce speed
  if (distance <= 10) {
    stand();  // Stop the robot if the obstacle is very close
  } else if (distance <= 30) {
    cS1(140, 140, 80);  // Normal walking pattern (slower due to proximity)
    cS2(60, 110, 80);
    cS3(140, 105, 80);
    cS4(40, 110, 80);
    delay(1000);  // Increased delay for slower speed
  } else {
    // Normal forward movement
    cS1(140, 140, 80);
    cS2(60, 110, 80);
    cS3(140, 105, 80);
    cS4(40, 110, 80);
    delay(500);  // Faster movement when no obstacle is close
  }
  
  // Proceed with walking regardless of the proximity
  cS2(90, 60, 80);  
  delay(100);
  cS2(130, 60, 80);
  delay(100);
  cS2(130, 110, 80);
  delay(200);
  
  cS4(70, 60, 80);
  delay(100);
  cS4(110, 60, 80);
  delay(100);
  cS4(110, 110, 80);
  delay(200);
  
  cS1(90, 90, 80);
  delay(100);
  cS1(70, 90, 80);
  delay(100);
  cS1(70, 140, 80);
  delay(200);
  
  cS3(110, 55, 80);
  delay(100);
  cS3(70, 55, 80);
  delay(100);
  cS3(70, 105, 80);
  delay(200);
}

void layDown() {
  cS1(90, 70, 90);
  cS2(90, 55, 90);
  cS3(90, 50, 90);
  cS4(90, 55, 90);
  delay(500);
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

void turn(){
  cS1(40, 140, 80);
  cS2(40, 110, 80);
  cS3(40, 105, 80);
  cS4(40, 110, 80);
  delay(2000);

  cS1(140, 140, 80);
  cS2(140, 110, 80);
  cS3(140, 105, 80);
  cS4(140, 110, 80);
  delay(2000);
}

void updown(){
  cS1(90, 180, 120); // up max
  cS2(90, 160, 120);
  cS3(110, 155, 120);
  cS4(70, 160, 120);
  delay(2000);

  cS1(90, 50, 30); // down max
  cS2(90, 30, 30);
  cS3(110, 25, 30);
  cS4(70, 30, 30);
  delay(2000);
}
