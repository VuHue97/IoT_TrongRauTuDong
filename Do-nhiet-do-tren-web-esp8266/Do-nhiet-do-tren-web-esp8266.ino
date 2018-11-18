// Them thu vien
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <WiFiClient.h>
#include "DHT.h"
#include "index.h"

// Pin
// Su dung cam bien DHT22
#define DHTTYPE DHT22
#define DHTPIN D1
// Thiet lap DHT
DHT dht(DHTPIN, DHTTYPE);

// Thong so WiFi nha ban
//const char* ssid = "mynet";
//const char* password = "honganh1997";
const char* ssid = "KhongWifi";
const char* password = "hue00111";

// Tao server voi cong 80
ESP8266WebServer server(80);

void setup() {

  // Mo Serial
  Serial.begin(115200);
  delay(10);

  // Khoi tao DHT
  dht.begin();

  // Ket noi toi mang WiFi
  Serial.println();
  Serial.println();
  Serial.print("Ket noi toi mang ");
  Serial.println(ssid);
//ket noi ESP8266 vao mang lan
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("Da ket noi WiFi");
  
  server.on("/", handleRoot);
  server.on("/temp", temperature);
  server.on("/humi", humidity);
  
  // Khoi dong server
  server.begin();
  Serial.println("Khoi dong Server");

  // In ra dia chi IP
  Serial.println(WiFi.localIP());
  
 
}

void loop(void){
  server.handleClient();          //Handle client requests
}

void handleRoot()
{
  String s = MAIN_page; //Read HTML contents
  server.send(200, "text/html", s); //Send web page
}

void temperature()
{
    int temp = dht.readTemperature();
    server.send(200, "text/plane", String(temp));
}

void humidity()
{
    int humi = dht.readHumidity();
    server.send(200, "text/plane", String(humi));
}
