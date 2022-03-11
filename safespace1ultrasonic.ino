int const trigPin = 10;
int const echoPin = 9;
int const buzzPin = 2;

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzPin, OUTPUT);
}

void loop()
{
  int duration, distance; // preobraz. vreme v razst.
  
  digitalWrite(trigPin, HIGH); //output width on trigpin
  delay(1);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH); //izmerva puls input na echopin
  
  distance = (duration/2) / 29.1; //razst=(vremeto/2)/21.9    /ot datasheet/
  
    if (distance <= 75 && distance >= 0) //ako razst e < 1m i poveche ot 0:
    {
      digitalWrite(buzzPin, HIGH); //zvunche
    } 
    else 
    {
      digitalWrite(buzzPin, LOW); //nqma zvunche
    }
    delay(60);
}
