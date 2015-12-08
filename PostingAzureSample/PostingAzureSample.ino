#include <SPI.h>
#include <Ethernet.h>

//coloca aquí la MAC address de tu shield
byte mac[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
EthernetClient client;

void setup()
{
  Serial.begin(9600);

  Serial.println("ethernet");

  if (Ethernet.begin(mac) == 0) {
    Serial.println("ethernet failed");
    for (;;) ;
  }
  delay(1000);
}

void loop()
{
  send_request();
  wait_response();
  read_response();
  end_request();

  delay(5000);
}

void send_request()
{
  Serial.println("\nconnecting...");

  if (client.connect("<url>.azure-mobile.net", 80)) 
  {
    client.println("POST /tables/<nombre tabla> HTTP/1.1");
    client.println("Host: <url>.azure-mobile.net");
    client.println("X-ZUMO-APPLICATION: <application key>");
    client.println("Content-Type: application/json");
    client.println("Content-Length: <tamaño de cadena>");
    client.println();
    //esta cadena es de ejemplo, lo ideal es reemplazarla por lecturas reales
    client.println("{\"Sensorname\":\"Subject01\",\"Temperature\":25,\"Humidity\":35,\"Latitude\":19.3456,\"Longitude\":-99.4785}");
    client.println();
    Serial.println("Data sent");
  } 
  else 
  {
    Serial.println("connection failed");
  }
}


void wait_response()
{
  while (!client.available()) {
    if (!client.connected()) {
      return;
    }
  }
}


void read_response()
{
  bool print = true;
  
  while (client.available()) {
    char c = client.read();
    if (c == '\n')
      print = false;
    if (print)
      Serial.print(c);
  }
}

void end_request()
{
  client.stop();
}
