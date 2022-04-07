#include <DHT.h>
#include <LiquidCrystal.h>
#include <BMP280_DEV.h>
#include <Servo.h>


#define Type DHT11
#define LED_red 9
#define LED_blue 10
#define POTENTIOMETER_PIN A1

int dt = 800;

//Dht11
int sensePin = 8; //pin
float humidity;
float tempC;
DHT HT(sensePin, Type); //object HT- Humanity sensor

//BMP 
float temperature, pressure, altitude;
BMP280_DEV bmp280;

//Ultrasonik
int const trigPin = 13;
int const echoPin = 12;
int const buzzPin = 2;

//display
LiquidCrystal lcd(11, 3, 4, 5, 6, 7);

void setsonik()
{
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);
  pinMode(buzzPin, OUTPUT); 
}

void ultrasonic()
{

  int duration, distance; //inputva distanciq i vreme
 
  digitalWrite(trigPin, HIGH); 
  delay(1);
  digitalWrite(trigPin, LOW);


  duration = pulseIn(echoPin, HIGH);
 
  distance = (duration/2) / 29.1; // polovin vr/29.1 (from datasheet)
 
    if (distance <= 30 && distance >= 0) {
 
      digitalWrite(buzzPin, HIGH); //zvunche
    } else {

      digitalWrite(buzzPin, LOW); //nqq zvunche
    }

    delay(60); //chakane
}

void setup() {
  Serial.begin(9600);

  Wire.begin();

  HT.begin();

  lcd.begin(16, 2);

  bmp280.begin(BMP280_I2C_ALT_ADDR);
  bmp280.setTimeStandby(TIME_STANDBY_2000MS);     // Set the standby time to 2 seconds
  bmp280.startNormalConversion();

  setsonic();

  myservo.attach(10);
}

void loop() {
  int data = analogRead(POTENTIOMETER_PIN);
  int degree = map(data, 0, 1023, 0, 180);
  myservo.write(degree);
  humidity = HT.readHumidity();
  tempC = HT.readTemperature();

  ultrasonic();
  
  for (int i = 0; i < 3; i++) {
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
}
