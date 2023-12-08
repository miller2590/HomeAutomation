#ifndef SMARTDEVICE_H
#define SMARTDEVICE_H

#include <string>

using namespace std;

class SmartDevice{
    private:
        int id;
        string name;
        bool status;
        int amSetPoint;
        int pmSetPoint;

    public:
        SmartDevice();
        virtual ~SmartDevice() = default;
        void activateDevice();
        void deavtivateDevice();

        //This will return int
        void getId();
        void getName();
        //This will return bool
        void getStatus();
        //This will return int
        void getAmSetPoint();
        //This will return int
        void getPmSetPoint();
        void setId();
        void setName();
        void setSatus();
        void setAmSetPoint();
        void setPmSetPoint();
};

#endif