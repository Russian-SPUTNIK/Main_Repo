#include "Wire.h"
#include <MPU6050_light.h>
#include <Servo.h>

MPU6050 mpu(Wire);
unsigned long timer = 0;

const int BUTTON = 2;
const int LED = 3;
const int BUTTON2 = 5;
int BUTTONstate = 0;
int BUTTONstate2 = 0;

int lightCal;
int lightVal;

Servo myservo; 

int pos = 90;  
int pos4 = 90;

void setup() {

  Wire.begin();
    pinMode(BUTTON, INPUT);
  pinMode(BUTTON2, INPUT);
  pinMode(LED, OUTPUT);
  
  myservo.attach(9); 
  
  byte status = mpu.begin();
  Serial.print(F("MPU6050 status: "));
  Serial.println(status);
  while(status!=0){ } 

  Serial.println(F("Calculating offsets, do not move MPU6050"));
  delay(1000);
  
  mpu.calcOffsets(); 
  Serial.println("Done!\n");
}

void loop() {
  mpu.update();
 
	Serial.print("\tZ : ");
	Serial.println(mpu.getAngleZ());
	timer = millis();  
 
   if(mpu.getAngleZ()< 2)    
     {
        pos4 = pos - (mpu.getAngleZ());
        myservo.write(pos4);
          if(pos4 >= 170)
            {
              pos4 = 170;
              myservo.write(pos4);
            }
        Serial.print("\tpos4 : ");
        Serial.println(pos4);
      }
   if(mpu.getAngleZ()> -2)   
     {
        pos4=pos - (mpu.getAngleZ());
        myservo.write(pos4);
          if(pos4 <= 10)
            {
              pos4 = 10;
              myservo.write(pos4);
            }        
        Serial.print("\tpos4 : ");
        Serial.println(pos4);
      }
  if(mpu.getAngleZ()<2)  
      {
        if(mpu.getAngleZ()>-2)
          {
            pos4 = 90;
            myservo.write(pos4);
          }
    
      }
  BUTTONstate = digitalRead(BUTTON);
     if (BUTTONstate == HIGH)
      {
    digitalWrite(LED, HIGH);
       } 
  BUTTONstate2 = digitalRead(BUTTON2);
    if (BUTTONstate2 == HIGH)
      {
    digitalWrite(LED, LOW);
      } 
 }
