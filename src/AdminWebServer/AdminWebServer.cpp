#include "Arduino.h" 
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include "AdminWebServer.h"
#include "Router.h"
#include "ArduinoJson.h"

AsyncWebServer _server(80);
AsyncWebSocket _ws("/ws");
extern AsyncWebSocketClient *wsClient;
AdminWebServer::AdminWebServer(){
}

void wsOnEvent(AsyncWebSocket * server, AsyncWebSocketClient * client, AwsEventType type, void * arg, uint8_t *data, size_t len){
  if(type == WS_EVT_CONNECT){
    //client connected
    Serial.printf("ws[%s][%u] connect\n", server->url(), client->id());
    // client->printf("Hello Client %u :)", client->id());
    // client->ping();
  } else if(type == WS_EVT_DISCONNECT){
    //client disconnected
    Serial.printf("ws[%s][%u] disconnect: %u\n", server->url(), client->id());
  } else if(type == WS_EVT_ERROR){
    //error was received from the other end
    Serial.printf("ws[%s][%u] error(%u): %s\n", server->url(), client->id(), *((uint16_t*)arg), (char*)data);
  // } else if(type == WS_EVT_PONG){
  //   //pong message was received (in response to a ping request maybe)
  //   Serial.printf("ws[%s][%u] pong[%u]: %s\n", server->url(), client->id(), len, (len)?(char*)data:"");
  } else if(type == WS_EVT_DATA){
    //data packet
    AwsFrameInfo * info = (AwsFrameInfo*)arg;
    if(info->final && info->index == 0 && info->len == len){
      //the whole message is in a single frame and we got all of it's data
      // Serial.printf("ws[%s][%u] %s-message[%llu]: ", server->url(), client->id(), (info->opcode == WS_TEXT)?"text":"binary", info->len);
      if(info->opcode == WS_TEXT){
        data[len] = 0;
        char json[] = "{\"wifi_settings\": {\"ssid\":\"qwer\", \"pass\":\"123\"}}";
        client->printf("I hear you Client %u :)", client->id());
        DynamicJsonDocument doc(1024);
        deserializeJson(doc, data);
        const char* ssid = doc["wifi_settings"]["ssid"];
        const char* pass = doc["wifi_settings"]["pass"];
        Serial.println(pass);
        Serial.println(ssid);
      } else {
        for(size_t i=0; i < info->len; i++){
          Serial.printf("%02x ", data[i]);
        }
        Serial.printf("\n");
      }
      // if(info->opcode == WS_TEXT)
      //   client->text("I got your text message");
      // else
      //   client->binary("I got your binary message");
    } else {
      //message is comprised of multiple frames or the frame is split into multiple packets
      // if(info->index == 0){
      //   if(info->num == 0)
      //     Serial.printf("ws[%s][%u] %s-message start\n", server->url(), client->id(), (info->message_opcode == WS_TEXT)?"text":"binary");
      //   Serial.printf("ws[%s][%u] frame[%u] start[%llu]\n", server->url(), client->id(), info->num, info->len);
      // }

      // Serial.printf("ws[%s][%u] frame[%u] %s[%llu - %llu]: ", server->url(), client->id(), info->num, (info->message_opcode == WS_TEXT)?"text":"binary", info->index, info->index + len);
      // if(info->message_opcode == WS_TEXT){
      //   data[len] = 0;
      //   Serial.printf("%s\n", (char*)data);
      // } else {
      //   for(size_t i=0; i < len; i++){
      //     Serial.printf("%02x ", data[i]);
      //   }
      //   Serial.printf("\n");
      // }

      // if((info->index + len) == info->len){
      //   Serial.printf("ws[%s][%u] frame[%u] end[%llu]\n", server->url(), client->id(), info->num, info->len);
      //   if(info->final){
      //     Serial.printf("ws[%s][%u] %s-message end\n", server->url(), client->id(), (info->message_opcode == WS_TEXT)?"text":"binary");
      //     if(info->message_opcode == WS_TEXT)
      //       client->text("I got your text message");
      //     else
      //       client->binary("I got your binary message");
      //   }
      // }
    }
  }
}

void AdminWebServer::init(){
    initRoutes(_server);
    _ws.onEvent(wsOnEvent);
    _server.addHandler(&_ws);
    _server.begin();
}