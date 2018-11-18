const int LED=13;//gan chan 13 cho led
const int BUTTON =7;//gan chan 7 cho button
int val=0;//gan bien val=0
//int state = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(LED,OUTPUT);//thiet lap chan 13 la output
  pinMode(BUTTON,INPUT);//thiet lap chan 7 la input
}

void loop() {
  // put your main code here, to run repeatedly:
  val=digitalRead(BUTTON);//doc du lieu tu chan 7 
  if(val==HIGH){//neu val =1
    digitalWrite(LED,HIGH);//xuat tin hieu chan 13 la HIGH -> den sang
  }else{
    digitalWrite(LED,LOW);//nguoc lai ->den tat
  }
  }
