
#include <Wire.h>
#include <BH1750.h>

BH1750 lightMeter;
int quangtro = A3;

void setup(){

  //Serial.begin(9600);

  // Initialize the I2C bus (BH1750 library doesn't do this automatically)
  Wire.begin();
  // On esp8266 you can select SCL and SDA pins using Wire.begin(D4, D3);

  lightMeter.begin();
  Serial.begin(9600);   

}


void loop() {

  uint16_t lux = lightMeter.readLightLevel();
  Serial.print("BH1750: ");
  Serial.print(lux);
  Serial.println(" lx");

  //code quang tro
  int giatriquangtro = analogRead(quangtro);
  Serial.print("Quang tro:");
  Serial.println(giatriquangtro);
  Serial.println("-----------------");

    delay(1000);
  
  
}
