#include <DHT.h>
#include <LiquidCrystal.h>
#include <Wire.h> //DS3231 RTC Module uses I2C protocol
#include "RTClib.h"

#define Type DHT11
#define LED_red 9
#define LED_blue 10

int sensePin = 8; //pin
float humidity;
float tempC;
int set_time = 500;
int dt = 5000;

RTC_DS3231 rtc;
DHT HT(sensePin, Type); //object HT- Humanity sensor

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
char daysOfTheWeek[7][12] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};


void setup(){
  Serial.begin(9600);
  HT.begin();
  delay(set_time);

  lcd.begin(16, 2);

  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
}

void loop(){
  humidity = HT.readHumidity();
  tempC = HT.readTemperature();

  //delay(1000);
  for(int i=0; i<2; i++){
    if(i==0){
      lcd.setCursor(0, 0); //0,1 => 1- the second row
      lcd.print("Temp:  Humidity:");
      lcd.setCursor(0, 1);
      lcd.print(tempC);
      lcd.setCursor(7,1);
      lcd.print(humidity);
      delay(dt);
      lcd.clear();
    }
    
    if(i==1){
      DateTime now = rtc.now();
      lcd.setCursor(0, 0);
     
      lcd.print("Date&Time: ");
      lcd.print(now.month(), DEC);
      lcd.print('/');
      lcd.print(now.day(), DEC);
      lcd.setCursor(0,1);
      lcd.print(daysOfTheWeek[now.dayOfTheWeek()]);
      lcd.setCursor(6,1);
      lcd.print(now.hour(), DEC);
      lcd.print(':');
      lcd.print(now.minute(), DEC);
      lcd.print(':');
      lcd.print(now.second(), DEC);
      Serial.println();
      delay(dt);
      lcd.clear();
    }
  }
  if (tempC < 32) {
    digitalWrite(LED_blue, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(1000);                       // wait for a second
  }
  else {
    digitalWrite(LED_blue, LOW);
    delay(1000);
  }
  if (tempC > 42.9) {
    digitalWrite(LED_red, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(1000);                       // wait for a second
  }
  else {
    digitalWrite(LED_red, LOW);
    delay(1000);
  }
}
