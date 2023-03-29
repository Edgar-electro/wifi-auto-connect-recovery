/*
  Rui Santos
  Complete project details at https://RandomNerdTutorials.com/solved-reconnect-esp8266-nodemcu-to-wifi/
  
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files.
  
  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
*/
#include <WiFiManager.h> 
#include <ESP8266WiFi.h>

// Replace with your network credentials
const char* ssid = "androidAP";
const char* password = "12345678";

unsigned long previousMillis = 5000;
unsigned long interval = 5000;

void initWiFi() {
 
    Serial.begin(115200);
    WiFi.begin(ssid, password);
    Serial.print("Connecting to WiFi");
    delay(5000);{
    WiFiManager wifiManager;
    wifiManager.autoConnect("BLYNK-IOT");
    Serial.println(WiFi.localIP());  
    }
  
     //The ESP8266 tries to reconnect automatically when the connection is lost
  WiFi.setAutoReconnect(true);
  WiFi.persistent(true);
}

void setup() {
  Serial.begin(115200);
  initWiFi();
  Serial.print("RSSI: ");
  Serial.println(WiFi.RSSI());
}

void loop() {
  //print the Wi-Fi status every 30 seconds
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >=interval){
    switch (WiFi.status()){
      case WL_NO_SSID_AVAIL:
        Serial.println(" WIFI SSID NOT FOUND");
        break;
      case WL_CONNECTED:
        Serial.println("WIFI CONNECDIT ");
        break;
      case WL_CONNECT_FAILED:
        Serial.println("Connection failed");
        break;
    }
    Serial.printf("Connection status: %d\n", WiFi.status());
    Serial.print("RRSI: ");
    Serial.println(WiFi.RSSI());
    previousMillis = currentMillis;
  }
}
