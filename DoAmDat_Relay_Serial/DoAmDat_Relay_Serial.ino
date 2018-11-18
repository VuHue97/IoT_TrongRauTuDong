
void setup() 
{
  Serial.begin(9600);//Mở cổng Serial ở mức 9600
  pinMode (2, INPUT);
  pinMode(A0, INPUT);
  pinMode (13, OUTPUT);
}
 
void loop() 
{
  int value = analogRead(A0);     // Ta sẽ đọc giá trị hiệu điện thế của cảm biến
                                      // Giá trị được số hóa thành 1 số nguyên có giá trị
                                      // trong khoảng từ 0 đến 1023
  Serial.println(value);//Xuất ra serial Monitor                   
//  if(value<500){
//    digitalWrite(4,HIGH);
//  }
//  else{
//    digitalWrite(4,LOW);
//  }
  int percent = map(value, 0, 1023, 100, 0);
  Serial.print(percent);
  Serial.println('%');
  Serial.println("-----------");
  
  // Đọc giá trị D0 rồi điều khiển Led 13...Các bạn cũng có thể điều khiển bơm nước thông qua rơle....
//  if (digitalRead (2) == 0)
//  {
//   digitalWrite (13, HIGH);
//  }
//  else{
//  digitalWrite (13, LOW);
//       }
  if(value>500){
    digitalWrite(13,HIGH);
  }
  else{
    digitalWrite(13,LOW);
  }
  delay(1000);
}
