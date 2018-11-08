#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

void setup() 
{
  lcd.init();
  lcd.backlight();
  pinMode (2, INPUT);
  pinMode(A0, INPUT);
  pinMode (13, OUTPUT);
}
 
void loop() 
{
  int value = analogRead(A0);     // Ta sẽ đọc giá trị hiệu điện thế của cảm biến
                                      // Giá trị được số hóa thành 1 số nguyên có giá trị
                                      // trong khoảng từ 0 đến 1023
  lcd.setCursor(0,0);
  lcd.println(value);//Xuất ra serial Monitor                   
  
  int percent = map(value, 0, 1023, 100, 0);
  lcd.setCursor(0,1);
  lcd.print("Do am: ");
  lcd.print(percent);
  lcd.println('%');
  //lcd.println("-----------");
  
  // Đọc giá trị D0 rồi điều khiển Led 13...Các bạn cũng có thể điều khiển bơm nước thông qua rơle....
  if (digitalRead (2) == 0)
  {
   digitalWrite (13, HIGH);
  }
  else{
  digitalWrite (13, LOW);
       }
  delay(1000);
}
