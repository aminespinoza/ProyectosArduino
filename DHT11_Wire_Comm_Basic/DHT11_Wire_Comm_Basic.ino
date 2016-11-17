#include <DHT.h>
#include <Wire.h>

#define dht_pin0 A0
#define dht_pin1 A1
#define dhtType DHT11
//#define DHTTYPE DHT22
//#define DHTTYPE DHT21

DHT weatherReceiver(dht_pin0, dhtType);
int temperature, humidity;
const char* temperatureArray;
String finalString;

void setup()
{
  Serial.begin(9600);
  Wire.begin(0x40); 
}
 
void loop()
{
  temperature = weatherReceiver.readTemperature();
  humidity = weatherReceiver.readHumidity();

  String temperatureString = String(temperature);
  String humidityString = String(humidity);

  finalString = temperatureString + "|" + humidityString;
  
  temperatureArray = finalString.c_str();
  Serial.println(finalString);
  Wire.onRequest(sendData);
  
  delay(800);
}

void sendData()
{
  Wire.write(temperatureArray);
}

