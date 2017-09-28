/* Sweep across cardboard letter 3D
 *  POE Lab 2 - DIY 3D Scanner
 *  Emily Lepert and Gracey Wilson
*/

#include <Servo.h>

Servo servo1;          //create 1st servo object to control a servo
Servo servo2;       //create 2nd servo object to control 2nd servo

int pos1 = 0;          //initialize variable to store 1st servo position
int pos2 = 0;          //initialize variable to store 2nd servo position
int hdeg1 = 70;  // highest degree
int ldeg1 = 10;  // 
int ldeg2 = 0;
int rdeg2 = 70;

const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to

int sensorValue = 0;        // value read from the sensor

void setup() {
  servo1.attach(9);   //attaches servo1 on pin 9 to the servo object
  servo2.attach(8);   //attaches servo2 on pin 8 to the servo object
  Serial.begin(9600);
  scan();
  Serial.println("done");
}

void scan(){
  for (pos1 = ldeg1; pos1 <= hdeg1; pos1 +=1) { //servo1 moves from 0 to deg degrees in steps on 1 degree
    servo1.write(pos1); //servo1 moves to pos1 position
    delay(15);                           //wait 15ms for servo to reach position

    for (pos2 =ldeg2; pos2 <= rdeg2; pos2 +=1){
      servo2.write(pos2);
      sensorValue = analogRead(analogInPin);   // read the analog in value
    
      // print the results to the Serial Monitor:
      Serial.print(sensorValue);
      Serial.print(";");
      Serial.print(pos1);
      Serial.print("/");
      Serial.print(pos2);
      Serial.println(":");
    
      // wait 2 milliseconds before the next loop for the analog-to-digital
      // converter to settle after the last reading:
      delay(15);
    }
  }
  
}

void loop() {
  /*
  for (pos1 = hdeg1; pos1 >= ldeg1; pos1 -=1) { //servo1 moves from deg to 0 degrees in steps on 1 degree
    servo1.write(pos1); //servo1 moves to pos1 position
    servo2.write(pos1); 
    delay(15);                           //wait 15ms for servo to reach position

    for (pos2 =rdeg2; pos2 >= ldeg2; pos2 -=1){
      servo2.write(pos2);
      sensorValue = analogRead(analogInPin);   // read the analog in value
    
      // print the results to the Serial Monitor:
      Serial.print(sensorValue);
      Serial.print(";");
      Serial.print(pos1);
      Serial.print(";");
      Serial.println(pos2);
    
      // wait 2 milliseconds before the next loop for the analog-to-digital
      // converter to settle after the last reading:
      delay(15);
    }
  }*/
}
