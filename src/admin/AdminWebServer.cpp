#include "Arduino.h" 
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include "AdminWebServer.h"
#include "Router.h"
AsyncWebServer _server(80);

AdminWebServer::AdminWebServer(){
}


void AdminWebServer::init(){
    initRoutes(_server);
    _server.begin();
}