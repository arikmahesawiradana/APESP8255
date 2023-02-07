#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
 
 
// Replace with your network credentials
const char* ssid = "Arik";
const char* password = "ARIKMAHESA";
ESP8266WebServer server(80);   //instantiate server at port 80 (http port)
 
 
void setup(void){
  //make the LED pin output and initially turned off
  pinMode(2, OUTPUT);
  digitalWrite(2, LOW);
  
  delay(1000);
  Serial.begin(115200);
  WiFi.softAP(ssid, password); //begin WiFi access point
  Serial.println("");
  
  server.on("/", [](){
    server.send(200, "text/plain", "You are connected");
  });
  
  server.on("/LEDOn", [](){
    server.send(200, "text/plain", "ON");
    digitalWrite(2, HIGH);
    delay(1000);
  });
  server.on("/LEDOff", [](){
    server.send(200, "text/plain", "OFF");
    digitalWrite(2, LOW);
    delay(1000);
  });
  server.begin();
  Serial.println("Web server started!");
}
void loop(void){
  server.handleClient();
}
