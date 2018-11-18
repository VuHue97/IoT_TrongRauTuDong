
#include <Wire.h>

int ledPin = 13;        // chọn chân 13 báo hiệu LED
int inputPin = 4;       // chọn ngõ tín hiệu vào cho PIR
//int pirState = LOW;     // Bắt đầu với không có báo động
int val = 0;
const int trig = 8;     // chân trig của HC-SR04
const int echo = 7;     // chân echo của HC-SR04

void setup()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(inputPin, INPUT);
  pinMode(trig,OUTPUT);   // chân trig sẽ phát tín hiệu
  pinMode(echo,INPUT);    // chân echo sẽ nhận tín hiệu
}
 
void loop()
{
  val = digitalRead(inputPin);    // đọc giá trị đầu vào.
  if (val == HIGH)                // nếu giá trị ở mức cao.(1)
  {
    digitalWrite(ledPin, HIGH); // LED On
    //delay(50);
 
    if (val == HIGH)
    {
      //Serial.setCursor(0,0);
      Serial.println("Phat hien nguoi!");
      //pirState = HIGH;
    }
  }
  else
  {
    digitalWrite(ledPin, LOW);
    //delay(300);
    if (val == LOW)
    {
      //Serial.setCursor(0,0);
      Serial.println("K co chuyen dong");
      //pirState = LOW;
    }
  }
    unsigned long duration; // biến đo thời gian
    int distance;           // biến lưu khoảng cách
    
    /* Phát xung từ chân trig */
    digitalWrite(trig,0);   // tắt chân trig
    delayMicroseconds(2);
    digitalWrite(trig,1);   // phát xung từ chân trig
    delayMicroseconds(5);   // xung có độ dài 5 microSeconds
    digitalWrite(trig,0);   // tắt chân trig
    
    /* Tính toán thời gian */
    // Đo độ rộng xung HIGH ở chân echo. 
    duration = pulseIn(echo,HIGH);  
    // Tính khoảng cách đến vật.
    distance = int(duration/2/29.412);
    
    /* In kết quả ra Serial Monitor */
    //Serial.setCursor(0,1);
    Serial.print(distance);
    Serial.println("cm");
    delay(100);
}
