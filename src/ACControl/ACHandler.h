#ifndef ACHandler_h
#define ACHandler_h
#include <Arduino.h>
#include "ACEnum.h"


class ACHandler{
    public:
        ACHandler();
        void init();
        void setStatus(ACStatus status);
        ACStatus getStatus();
        static ACStatus getDefaultStatus();
    protected:
        ACStatus _status;
};

extern ACHandler ACHand;

#endif