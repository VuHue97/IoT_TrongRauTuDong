
#include <Wire.h>
#include <BH1750.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16,2);

BH1750 lightMeter;


void setup(){

  lcd.init();
  lcd.backlight();

  // Initialize the I2C bus (BH1750 library doesn't do this automatically)
  Wire.begin();
  // On esp8266 you can select SCL and SDA pins using Wire.begin(D4, D3);

  lightMeter.begin();

  //lcd.println(F("BH1750 Test begin"));
  
}


void loop() {

  uint16_t lux = lightMeter.readLightLevel();
  lcd.setCursor(0,0);
  lcd.print("Light: ");
  lcd.print(lux);
  lcd.println(" lx");
  delay(1000);


}
