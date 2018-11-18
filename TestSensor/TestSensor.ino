#include "DHT.h" 
// The DHT data line is connected to pin 2 on the Arduino 
#define DHTPIN 2 
// Leave as is if you're using the DHT22. Change if not. 
//#define DHTTYPE DHT11   
// DHT 11 
#define DHTTYPE DHT22   // DHT 22  (AM2302) 
//#define DHTTYPE DHT21   // DHT 21 (AM2301) 
DHT dht(DHTPIN, DHTTYPE); 
void setup() {  
  // Start the Serial Monitor and print a first line of text  
  Serial.begin(9600);
  Serial.println("DHTxx test!");
  // Initialize the DHT library
  dht.begin();
  }
  void loop() {
    // Wait 2 seconds between measurements
    delay(2000);  
    // Read humidity (percent)  
    float h = dht.readHumidity();
    // Read temperature as Celsius
    float t = dht.readTemperature();
    // Read temperature as Fahrenheit
    float f = dht.readTemperature(true);    
}
  // Check if any reads failed and exit early (to try again)
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor :-(");
    return;  
    }
    // Compute heat index
    // Must send in temp in Fahrenheit!
    float hi = dht.computeHeatIndex(f, h);
    Serial.print("Humidity: ");
    Serial.print(h);
    Serial.print(" %\t");
    Serial.print("Temperature: ");
    Serial.print(t);
    Serial.print(" *C ");
    Serial.print(f);
    Serial.print(" *F\t");
    Serial.print("Heat index: ");
    Serial.print(hi);
    Serial.println(" *F");
    }
