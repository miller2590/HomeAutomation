#ifndef LIGHTS_H
#define LIGHTS_H

#include "SmartDevice.h"

class Lights : public SmartDevice{
    public:
        Lights(int id, string name, string deviceType);
        void testMessage();
};

#endif
