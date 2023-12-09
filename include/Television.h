#ifndef TELEVISION_H
#define TELEVISION_H

#include "SmartDevice.h"

class Television : public SmartDevice {
    private:
        int channel;

    public:
        Television(int id, string name);
        //This will return int
        void getChannel();
        void setChannel();
};

#endif