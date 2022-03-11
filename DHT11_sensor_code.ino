#include <DHT.h>
#define Type DHT11
#define LED1 8
#define LED2 4

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

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
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

  if (tempC < 32) {
    digitalWrite(LED2, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(1000);                       // wait for a second
  }
  else {
    digitalWrite(LED2, LOW);
    delay(1000);
  }
  if (tempC > 42.9) {
    digitalWrite(LED1, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(1000);                       // wait for a second
  }
  else {
    digitalWrite(LED1, LOW);
    delay(1000);
  }

  delay(1000);
}
