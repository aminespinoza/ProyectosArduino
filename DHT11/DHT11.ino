#include <DHT.h>

#define dht_dpin A0
DHT weatherSensor(dht_dpin, DHT11);
 
void setup()
{
  Serial.begin(9600); 
}
 
void loop()
{ 
  Serial.print("Humedad = ");
  Serial.print(weatherSensor.readHumidity());
  Serial.print(" % Temp = ");
  Serial.print(weatherSensor.readTemperature());
  Serial.println(" C");
  delay(1000);
}

