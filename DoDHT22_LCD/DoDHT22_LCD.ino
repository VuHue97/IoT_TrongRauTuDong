#include <Wire.h>
#include "DHT.h"
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

const int DHTPIN=2;
const int DHTTYPE = DHT22;
DHT dht(DHTPIN,DHTTYPE);
void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd.backlight();   //Bật đèn nền
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  lcd.setCursor(0,0);
  lcd.print("Nhiet do: ");
  lcd.println(t);
  lcd.setCursor(0,1);
  lcd.print("Do am: ");
  lcd.println(h);
  lcd.println();
  delay(1000);
}
