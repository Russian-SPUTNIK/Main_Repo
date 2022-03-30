#include <DHT.h>
#include <LiquidCrystal.h>
#include <BMP280_DEV.h>

#define Type DHT11
#define LED_red 9
#define LED_blue 10

int sensePin = 8; //pin
float humidity;
float tempC;
int dt = 5000;
DHT HT(sensePin, Type); //object HT- Humanity sensor

float temperature, pressure, altitude;
BMP280_DEV bmp280;

LiquidCrystal lcd(11, 3, 4, 5, 6, 7);


void setup() {
  Serial.begin(9600);

  HT.begin();

  lcd.begin(16, 2);

  bmp280.begin(BMP280_I2C_ALT_ADDR);
  bmp280.setTimeStandby(TIME_STANDBY_2000MS);     // Set the standby time to 2 seconds
  bmp280.startNormalConversion();
}
void loop() {
  humidity = HT.readHumidity();
  tempC = HT.readTemperature();

  for (int i = 0; i < 2; i++) {
    if (i == 1) {
      lcd.setCursor(0, 0); //0,1 => 1- the second row
      lcd.print("Temp:  Humidity:");
      lcd.setCursor(0, 1);
      lcd.print(tempC);
      lcd.setCursor(7, 1);
      lcd.print(humidity);
      delay(dt);
      lcd.clear();
    }

    if (i == 0) {
      bmp280.getMeasurements(temperature, pressure, altitude);  // Check if the measurement is complete
      lcd.setCursor(0, 0);
      lcd.print("OutTemp: ");
      lcd.print(temperature);
      lcd.print(F("*C"));
      lcd.setCursor(0, 1);
      lcd.print("Pres: ");
      lcd.print(pressure);
      lcd.print(F("hPa"));
      delay(dt);
      lcd.clear();
    }
  }

  if (tempC < 32) {
    digitalWrite(LED_blue, HIGH);   // turn the LED on (HIGH is the voltage level)
  }
  else {
    digitalWrite(LED_blue, LOW);
  }
  if (tempC > 42) {
    digitalWrite(LED_red, HIGH);   // turn the LED on (HIGH is the voltage level)
  }
  else {
    digitalWrite(LED_red, LOW);
  }
  delay(2000);
}
