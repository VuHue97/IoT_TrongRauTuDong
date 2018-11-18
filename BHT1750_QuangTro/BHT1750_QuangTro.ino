/*

  Example of BH1750 library usage.

  This example initialises the BH1750 object using the default high resolution
  continuous mode and then makes a light level reading every second.

  Connection:

    VCC -> 3V3 or 5V
    GND -> GND
    SCL -> SCL (A5 on Arduino Uno, Leonardo, etc or 21 on Mega and Due, on esp8266 free selectable)
    SDA -> SDA (A4 on Arduino Uno, Leonardo, etc or 20 on Mega and Due, on esp8266 free selectable)
    ADD -> (not connected) or GND

  ADD pin is used to set sensor I2C address. If it has voltage greater or equal to
  0.7VCC voltage (e.g. you've connected it to VCC) the sensor address will be
  0x5C. In other case (if ADD voltage less than 0.7 * VCC) the sensor address will
  be 0x23 (by default).

*/

#include <Wire.h>
#include <BH1750.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

BH1750 lightMeter;
int quangtro = A3;

void setup(){

  //Serial.begin(9600);

  // Initialize the I2C bus (BH1750 library doesn't do this automatically)
  Wire.begin();
  // On esp8266 you can select SCL and SDA pins using Wire.begin(D4, D3);

  lightMeter.begin();
  lcd.init();       //Khởi động màn hình. Bắt đầu cho phép Arduino sử dụng màn hình, cũng giống như dht.begin() trong chương trình trên
  
  lcd.backlight();
  //Serial.println(F("BH1750 Test begin"));

}


void loop() {

  uint16_t lux = lightMeter.readLightLevel();
  lcd.setCursor(0,0);
  lcd.print("BH1750: ");
  lcd.print(lux);
  lcd.println(" lx");

  //code quang tro
  int giatriquangtro = analogRead(quangtro);
  lcd.setCursor(0,1);
  lcd.print("Quang tro:");
  lcd.println(giatriquangtro);
  lcd.println("-----------------");

    delay(1000);
  
  
}
