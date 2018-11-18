#include <ESP8266WiFi.h>
#include<ESP8266WebServer.h>
#include<WiFiClient.h>
#include "DHT.h"

#define DHTPIN D1 
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);
ESP8266WebServer server(80);

void setup()
{
  Serial.begin(115200);
  Serial.println();

  WiFi.begin("KhongWifi", "hue00111");

  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

//  server.on("/", handleRoot);
//  server.on("/temp", temperature);
//  server.on("/humi", humidity);
//khoi dong server
  server.begin();
  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());

  
  
}

void loop() {
  WiFiClient client = server.available();
  float h = dht.readHumidity();
  // Đọc giá trị nhiệt độ C (mặc định)
  float t = dht.readTemperature();
  // Đọc giá trị nhiệt độ F(isFahrenheit = true)
  float f = dht.readTemperature(true);
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Loi doc du lieu tu DHT!");
    return;
  }
   String req = client.readStringUntil('\r');
  Serial.println(req);
  client.flush();
  // Chuan bi tao web de phan hoi
  String s = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
  s += "<head>";
  s += "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">";
  s += "<meta http-equiv=\"refresh\" content=\"60\" />";
  s += "<script src=\"https://code.jquery.com/jquery-2.1.3.min.js\"></script>";
  s += "<link rel=\"stylesheet\" href=\"https://maxcdn.bootstrapcdn.com/bootstrap/3.3.4/css/bootstrap.min.css\">";
  s += "<style>body{font-size: 24px;} .voffset {margin-top: 30px;}</style>";
  s += "</head>";
  s += "<div class=\"container\">";
  s += "<h1>Theo doi nhiet do va do am</h1>";
  s += "<div class=\"row voffset\">";
  s += "<div class=\"col-md-3\">Nhiet do: </div><div class=\"col-md-3\">" + String(t) + "</div>";
  s += "<div class=\"col-md-3\">Do am: </div><div class=\"col-md-3\">" + String(h) + "</div>";
  s += "</div>";
   
  // Gui phan hoi toi client (o day la giao dien web)
  client.print(s);
  delay(1);
  Serial.println("Client da thoat");
  }
