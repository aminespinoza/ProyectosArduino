int redLed = 4;
int blueLed = 5;
int greenLed = 6;

void setup()
{
  pinMode(redLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
}

void loop()
{
  digitalWrite(redLed, HIGH);
  digitalWrite(blueLed, LOW);
  digitalWrite(greenLed, LOW);
  delay(500);
  digitalWrite(redLed, LOW);
  digitalWrite(blueLed, HIGH);
  digitalWrite(greenLed, LOW);
  delay(500);
  digitalWrite(redLed, LOW);
  digitalWrite(blueLed, LOW);
  digitalWrite(greenLed, HIGH);
  delay(500);
}
