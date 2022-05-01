#include <TM1637Display.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <ArduinoJson.h>

//Pinout
const int CLK = D5;
const int DIO = D6;

//Wifi
const char* ssid     = "YOUR_SSID";
const char* password = "YOUR_PW";
 
TM1637Display display(CLK, DIO);
 
void setup() {
  display.setBrightness(0x0a); //Max brightness on 7 segment display
  Serial.begin(115200);  //ESP8266 operates at 115200 baud
  delay(10); //Cushion
  
  WiFi.begin(ssid, password);
  Serial.print("Connecting to ");
  Serial.print(ssid); Serial.println(" ...");

  int i = 0;
  while (WiFi.status() != WL_CONNECTED) { // Wait for the Wi-Fi to connect
    delay(1000);
    Serial.print(++i); Serial.print(' ');
  }

  Serial.println('\n');
  Serial.println("Connection established!");  
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP()); 
}
 
 
void loop() {

 WiFiClient client;
 HTTPClient http;
 http.begin(client, "http://api.etherscan.io/api?module=gastracker&action=gasoracle&apikey=YOUR_API_KEY"); //Get an API key here: https://etherscan.io/apis

 int httpResponseCode = http.GET();

 if (httpResponseCode > 0) {
    String payload = http.getString();
    DynamicJsonDocument doc(1024);
    deserializeJson(doc, payload);
    const char* proposedGas = doc["result"]["ProposeGasPrice"]; //Use the proposed gas price. Can also do Fast and Safe prices
    display.showNumberDec(atoi(proposedGas)); //Set number on display. atoi for type casting
 } else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
 }
 // Free resources
 http.end();

 delay(3000); //Run once every 3 seconds. 28,800 queries per day
}
