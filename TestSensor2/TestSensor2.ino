#include "DHT.h"

const int DHTPIN=2;
const int DHTTYPE = DHT22;
DHT dht(DHTPIN,DHTTYPE);
void setup() {
  // put your setup code here, to run once:
  //Bật đèn nền
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  Serial.print("Nhiet do: ");
  Serial.println(t);
  Serial.print("Do am: ");
  Serial.println(h);
  Serial.println();
  delay(1000);
}
