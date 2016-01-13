const int redControl = A0;
const int greenControl = A1;
const int blueControl = A2;

const int redLed = 4;
const int greenLed = 5;
const int blueLed = 6;

int redLedBright = 0;
int greenLedBright = 0;
int blueLedBright = 0;

int redPotenciometerValue = 0;
int greenPotenciometerValue = 0;
int bluePotenciometerValue = 0;

void setup() 
{
    pinMode(redControl, INPUT);  
    pinMode(greenControl, INPUT);
    pinMode(blueControl, INPUT);
    
    pinMode(redLed, OUTPUT);  
    pinMode(greenLed, OUTPUT);
    pinMode(blueLed, OUTPUT);           
}

void loop()
{
    ConvertPotenciometerToLed(redControl, redPotenciometerValue, redLedBright, redLed);
    ConvertPotenciometerToLed(greenControl, greenPotenciometerValue, greenLedBright, greenLed);
    ConvertPotenciometerToLed(blueControl, bluePotenciometerValue, blueLedBright, blueLed);
    delay(100);     
}

void ConvertPotenciometerToLed(int potenciometerOrigin, int potenciometerValue, int ledBright, int ledType)
{
    potenciometerValue = analogRead(potenciometerOrigin);
    ledBright = map(potenciometerValue, 0, 1023, 0, 255);
    analogWrite(ledType, ledBright);
}

