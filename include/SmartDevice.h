#ifndef SMARTDEVICE_H
#define SMARTDEVICE_H

#include <string>

using namespace std;

class SmartDevice{
    private:
        int id;
        string name;
        bool status = false;
        int amSetPoint;
        int pmSetPoint;

    public:
        SmartDevice(int id, string name);
        virtual ~SmartDevice() = default;
        void activateDevice();
        void deavtivateDevice();

        int getId();
        string getName();
        bool getStatus();
        void getAmSetPoint();
        //This will return int
        void getPmSetPoint();
        void setId(int newId);
        void setName(string newName);
        void setSatus();
        void setAmSetPoint();
        void setPmSetPoint();
};

#endif