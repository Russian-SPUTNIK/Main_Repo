#include "Wire.h"
#include <MPU6050_light.h>
#include <Servo.h>

MPU6050 mpu(Wire);
unsigned long timer = 0;

const int sensorPin = A0;
const int ledPin = 3;


int lightCal;
int lightVal;

Servo myservo; 

int pos = 90;  
int pos4 = 90;

void setgyro() {
  Serial.begin(9600);
  Wire.begin();
  
  
  myservo.attach(9); 
  
  byte status = mpu.begin();
  Serial.print(F("MPU6050 status: "));
  Serial.println(status);
  while(status!=0){ } 

  Serial.println(F("Calculating offsets, do not move MPU6050"));
  delay(1000);

  pinMode(ledPin, OUTPUT);
  pinMode(sensorPin, OUTPUT);
  lightCal = analogRead(sensorPin);
  
  mpu.calcOffsets(); 
  Serial.println("Done!\n");
}

void gyro() {
  mpu.update();

  Serial.println(lightCal);
  lightVal = analogRead(sensorPin);
 
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
      
   if (lightVal*10 < 15)
      {
        digitalWrite(ledPin, HIGH);
      }
   else
      {
        digitalWrite(ledPin, LOW);
      }
      
    Serial.println(lightVal);
    delay(150);
 }

