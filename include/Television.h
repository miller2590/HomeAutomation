#ifndef TELEVISION_H
#define TELEVISION_H

#include "SmartDevice.h"

class Television : public SmartDevice {
    private:
        int channel;

    public:
        Television(string id, string name, string deviceType);
        void getChannel();
        void setChannel();
};

#endif