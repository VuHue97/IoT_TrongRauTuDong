const int LED=13;//gan chan 13 la LED
void setup() {//Ham khoi tao
  // put your setup code here, to run once:
  pinMode(LED,OUTPUT);//thiet lap chan 13 la dau ra
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED,HIGH);//
  delay(1000);
  digitalWrite(LED,LOW);
  delay(1000);
}
