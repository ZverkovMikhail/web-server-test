#ifndef AdminWebServer_h
#define AdminWebServer_h
#include "Arduino.h" 
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
// #include "Pages.cpp"
// #include "View.cpp"

class AdminWebServer{
    public:
    AdminWebServer();
    void init();
};
#endif