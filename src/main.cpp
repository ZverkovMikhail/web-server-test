#include <Arduino.h>
#include <WiFi.h>
#include "display/Display.h"
#include <admin/AdminWebServer.h>

const char* ssid = "ACRem";
const char* password = "12345678";


AdminWebServer webServer;
int count = 0;

void setup(void) {
  Serial.begin(115200 , SERIAL_8N1);
  while (!Serial) 
    delay(50);
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password);
  DisPlay.init();
  webServer.init();
  DisPlay.setLine(DisPlay.FIRST, ssid)
         ->setLine(DisPlay.SECOND, password)
         ->setLine(DisPlay.THIRD,  WiFi.softAPIP().toString().c_str())
         ->setLine(DisPlay.FOURTH, "inited")
         ->print();
  delay(8000);
}


void loop(void) {         
}