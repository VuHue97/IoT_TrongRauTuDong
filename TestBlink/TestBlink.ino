const int LED=13;//gan chan 13 la LED
void setup() {
  // put your setup code here, to run once:
  pinMode(LED,OUTPUT);//thiet lap chan 13 la output
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED,1);//xuat tin hieu chan 13 la 1-> den led sang
  delay(1000);//tre 1 giay
  digitalWrite(LED,0);//xuat tin hieu chan 13 la 0-> den led tat
  delay(1000);//tre 1 giay
}
