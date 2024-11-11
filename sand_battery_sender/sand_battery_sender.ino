/**
   BasicHTTPClient.ino

    Created on: 24.05.2015

*/

#include <Arduino.h>
#include <WiFi.h>
#include <WiFiMulti.h>
#include <HTTPClient.h>
#include <HardwareSerial.h>

WiFiMulti wifiMulti;
String content;

void setup() {

  Serial.begin(9600);
  Serial1.begin(9600, SERIAL_8N1, 16, 17);

  wifiMulti.addAP("Airtel_nkri_1180", "air45355");
  wifiMulti.addAP("Raj Hotspot", "ubqz1497");
  wifiMulti.addAP("Sivaramana", "Siva@4546");
  wifiMulti.addAP("IQOO Z5", "12340987");

  pinMode(2, OUTPUT);
  digitalWrite(2, LOW);
  Serial1.flush();
}

void loop() {

  if ((wifiMulti.run() == WL_CONNECTED)) {
    if (Serial1.available()){
      
      HTTPClient http;
      http.begin("http://marudhu2004.pythonanywhere.com/update"); 
      
      content = Serial1.readString();
      Serial.print(content);
      Serial.print(" ");
      Serial.println(content.length());

      uint8_t length = content.length();
      uint8_t byteArray[length];

      for (int i = 0; i < length; i++){
        byteArray[i] = content[i];
      }

      int httpCode = http.POST(byteArray, length);

      if (httpCode == HTTP_CODE_OK) {
      
        String payload = http.getString();
        Serial.println(payload);

        digitalWrite(2, HIGH);
        delay(200);
        digitalWrite(2, LOW);
      }
      
      else {
        Serial.printf("[HTTP] POST... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }
      http.end();
      Serial1.flush();
    }
  }
  else{
    Serial1.flush();
  }
}
