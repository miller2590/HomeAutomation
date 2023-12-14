#ifndef LIGHTS_H
#define LIGHTS_H

#include "SmartDevice.h"

class Lights : public SmartDevice{
    public:
        Lights(string id, string name, string deviceType);
        void testMessage();
};

#endif
