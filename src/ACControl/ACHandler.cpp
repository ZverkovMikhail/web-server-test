#include <Arduino.h>
#include "ACHandler.h"

ACHandler::ACHandler(){
    
}
void ACHandler::init(){
    this->_status = getDefaultStatus();
}
void ACHandler::setStatus(ACStatus status){
    status.print();
}

ACStatus ACHandler::getStatus(){
    return this->_status;
}
ACStatus ACHandler::getDefaultStatus(){
     ACStatus stat;
     stat.power = on;
     stat.mode = Auto;
     stat.temp = 25;
     stat.fan = Auto_fun;
     stat.swing_v = Auto_swing;
    return stat;
}

ACHandler ACHand;