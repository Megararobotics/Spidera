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
  data = Serial.read();
  Serial.print(data);
  Serial.print("\n");

  if (data == 'a') { // Walk forward, turn, and walk forward again
    unsigned long startTime = millis();
    
    // Step 1: Walk forward for 5 seconds
    while (millis() - startTime < 10000) { // Walk forward for 5 seconds
      walkForward();
    }
    
    stand(); // Stand before turning
    delay(1000); // Short pause before turning
    
    // Step 2: Turn right
    turnright(); 
    turnright(); 
    turnright(); 
    turnright(); 
    turnright(); 

    stand(); // Stand before next forward movement
    delay(1000); // Short pause after turning
    
    // Reset timer for the second forward movement
    startTime = millis();
    
    // Step 3: Walk forward for 2 seconds
    while (millis() - startTime < 5000) { // Walk forward for 2 seconds
      walkForward();
    }
    
    stand(); // Stand after finishing the movement
  } 
  if (data == 'b') { // Walk forward, turn, and walk forward again
    unsigned long startTime = millis();
    
    // Step 1: Walk forward for 5 seconds
    while (millis() - startTime < 10000) { // Walk forward for 5 seconds
      walkForward();
    }
    
    stand(); // Stand before turning
    delay(1000); // Short pause before turning
    
    // Step 2: Turn right
    turnleft(); 
    turnleft(); 
    turnleft(); 
    turnleft(); 
    turnleft(); 
    turnleft(); 

    stand(); // Stand before next forward movement
    delay(1000); // Short pause after turning
    
    // Reset timer for the second forward movement
    startTime = millis();
    
    // Step 3: Walk forward for 2 seconds
    while (millis() - startTime < 5000) { // Walk forward for 2 seconds
      walkForward();
    }
    
    stand(); // Stand after finishing the movement
  } 
  
  /* Optional additional commands
  else if (data == 'b') { // Lay down
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
  */
  else {
    stand();
  }
}

void turnright(){
  cS1(90, 90, 80); // j2
  delay(100);
  cS1(40, 90, 80); // j2
  delay(100);
  cS1(40, 140, 80);
  delay(200);
  cS2(90, 60, 80);  
  delay(100); 
  cS2(40, 60, 80);  
  delay(100);
  cS2(40, 110, 80);
  delay(200);
  cS4(70, 60, 80); 
  delay(100);
  cS4(40, 60, 80); 
  delay(100);
  cS4(40, 110, 80);
  delay(200);
  cS3(110, 55, 80); // j8
  delay(100);
  cS3(40, 55, 80); // j8
  delay(100);
  cS3(40, 105, 80);
  delay(200);
  
  
  cS1(140, 140, 80);
  cS2(140, 110, 80);
  cS3(140, 105, 80);//110
  cS4(140, 110, 80);
  delay(500);
}

void turnleft(){
  cS2(90, 60, 80);  
  delay(100); 
  cS2(140, 60, 80);  
  delay(100);
  cS2(140, 110, 80);
  delay(200);
  cS1(90, 90, 80); 
  delay(100);
  cS1(140, 90, 80); // j2
  delay(100);
  cS1(140, 150, 80);
  delay(200);
  cS3(110, 55, 80); // j8
  delay(100);
  cS3(140, 55, 80); // j8
  delay(100);
  cS3(140, 105, 80);
  delay(200);
  cS4(70, 60, 80); 
  delay(100);
  cS4(140, 60, 80); 
  delay(100);
  cS4(140, 110, 80);
  delay(200);
  
  
   
  cS1(40, 140, 80);
  cS2(40, 110, 80);
  cS3(40, 105, 80);//110
  cS4(40, 110, 80);
  delay(500);

}
void walkBackward() {
  // Step 1: Reverse the initial forward pattern
  cS1(40, 140, 80);  // Reverse position for Leg 1
  cS2(130, 110, 80); // Reverse position for Leg 2
  cS3(40, 105, 80);  // Reverse position for Leg 3
  cS4(110, 110, 80); // Reverse position for Leg 4
  delay(500);

  // Step 2: Backward pattern 1 (left side: Legs 2 & 4)
  cS2(130, 60, 80);  // Lift and move Leg 2 backward
  delay(100);
  cS2(90, 60, 80);   // Lower Leg 2
  delay(100);
  cS2(90, 110, 80);  // Position Leg 2 for next step
  delay(200);

  cS4(110, 60, 80);  // Lift and move Leg 4 backward
  delay(100);
  cS4(70, 60, 80);   // Lower Leg 4
  delay(100);
  cS4(70, 110, 80);  // Position Leg 4 for next step
  delay(200);

  // Step 3: Move right side legs (Legs 1 & 3) backward
  cS1(130, 60, 80);  // Lift and move Leg 1 backward
  delay(100);
  cS1(110, 60, 80);  // Lower Leg 1
  delay(100);
  cS1(100, 110, 40);   // Position Leg 1 for next step
  delay(200);

  cS3(130, 60, 80);  // Lift and move Leg 3 backward
  delay(100);
  cS3(110, 60, 80); // Lower Leg 3
  delay(100);
  cS3(90, 110, 80);  // Position Leg 3 for next step
  delay(200);
}

void walkForward() {
  // Step 1
 /* cS1(90, 160, 60); // stand up
  cS2(90, 110, 60);
  cS3(110, 105, 60);
  cS4(70, 110, 60);
  delay(2000);*/


  cS1(140, 140, 80); //forwad action
  cS2(60, 110, 80);
  cS3(140, 105, 80);//110
  cS4(40, 110, 80);
  delay(500);

  cS2(90, 60, 80);  // forward pattern 1 right side
  delay(100);
  cS2(130, 60, 80); // j4
  delay(100);
  cS2(130, 110, 80); // j5  cS2(130, 110, 80);
  delay(200);
  cS4(70, 60, 80); // j11
  delay(100);
  cS4(110, 60, 80); // j10
  delay(100);
  cS4(110, 110, 80); // j11  cS4(110, 110, 80);
  delay(200);
 /* cS1(90, 160, 60); // stand up
  cS2(90, 110, 60);
  cS3(110, 105, 60);
  cS4(70, 110, 60);
  delay(200);*/

  cS1(90, 90, 80); // j2
  delay(100);
  cS1(70, 90, 80); // j1
  delay(100);
  cS1(70, 140, 80); // j2 cS1(70, 140, 80); 
  delay(200);
  cS3(110, 55, 80); // j8
  delay(100);
  cS3(70, 55, 80); // j7
  delay(100);
  cS3(70, 105, 80); // j8  cS3(70, 105, 80);
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
  cS1(70, 140, 60); // stand up90
  cS2(130, 110, 60);
  cS3(70, 105, 60);//110
  cS4(110, 110, 60);
}
void stand() {
  cS1(90, 140, 80); // stand up90
  cS2(90, 110, 80);
  cS3(110, 105, 80);//110
  cS4(70, 110, 80);
}

void turn(){
  cS1(40, 140, 80);
  cS2(40, 110, 80);
  cS3(40, 105, 80);//110
  cS4(40, 110, 80);
  delay(2000);

  cS1(140, 140, 80);
  cS2(140, 110, 80);
  cS3(140, 105, 80);//110
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
