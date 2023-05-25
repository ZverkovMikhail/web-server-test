#include "Arduino.h" 
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include "Pages.h"
#include "display/Display.h"


void indexPage(AsyncWebServerRequest *request) {
    Serial.println(request->url().c_str());
    request->send_P(200, "text/html", index_html);
}

void action(AsyncWebServerRequest *request)
{
  const char* ssid = request->getParam("ssid", true, false)->value().c_str();
  const char* pswd =  request->getParam("pswd", true, false)->value().c_str();
  Serial.println(ssid);
  Serial.println(pswd);
  Serial.println(WiFi.softAPIP().toString().c_str());
   DisPlay.setLine(DisPlay.FIRST, ssid)
         ->setLine(DisPlay.SECOND, pswd)
         ->setLine(DisPlay.THIRD,  WiFi.softAPIP().toString().c_str())
         ->setLine(DisPlay.FOURTH, "inited")
         ->print();
  request->redirect("/");
}

void notFoundPage(AsyncWebServerRequest *request) {
    request->send(404, "text/plain", "Not found");
}