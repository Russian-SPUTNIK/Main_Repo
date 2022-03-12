int const trigPin = 11;
int const echoPin = 10;
int const buzzPin = 4;

void setupsonic() //ultrasonic
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzPin, OUTPUT);
}

void ultrasonic() //ultrasonic
{
  int duration, distance; // preobraz. vreme v razst.

  digitalWrite(trigPin, HIGH); //output width on trigpin
  delay(1);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH); //izmerva puls input na echopin

  distance = (duration/2) / 29.1; //razst=(vremeto/2)/21.9    /ot datasheet/

    if (distance <= 75 && distance >= 0) //ako razst e < 75cm i poveche ot 0:
    {
      digitalWrite(buzzPin, HIGH); //zvunche
    } 
    else 
    {
      digitalWrite(buzzPin, LOW); //nqma zvunche
    }
    delay(60); //shtoto shto ne
}
