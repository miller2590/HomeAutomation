#ifndef TELEVISION_H
#define TELEVISION_H

#include "SmartDevice.h";

class Television : public SmartDevice {
    private:
        int channel;

    public:
        Television();
        //This will return int
        void getChannel();
        void setChannel();
};

#endif