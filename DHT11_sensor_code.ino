#include <DHT.h>
#define Type DHT11

int sensePin = 7; //pin
DHT HT(sensePin, Type); //object HT- Humanity sensor
float humidity;
float tempC;
int set_time = 500;
int dt = 1000;
 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  HT.begin();
  delay(set_time);
}

void loop() {
  // put your main code here, to run repeatedly:
  humidity = HT.readHumidity();
  tempC = HT.readTemperature();
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print("Temperature: ");
  Serial.print(tempC);
  Serial.print("\n");
  delay(1000);
}
