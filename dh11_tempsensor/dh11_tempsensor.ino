#include "DHT.h"

#define DHT_TYPE DHT11

const int DHT_PIN = 5;
DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);  
  Serial.begin(9600);
  dht.begin();
}

// runs over and over again
void loop() {
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
 
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  Serial.print("Temperatur: ");
  Serial.print(t);
  Serial.print("°C, Luftfeuchtigkeit: ");
  Serial.print(h);
  Serial.println("%");
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  delay(1000);
}
