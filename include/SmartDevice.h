#ifndef SMARTDEVICE_H
#define SMARTDEVICE_H

#include <string>

using namespace std;

class SmartDevice{
    private:
        string id;
        string name;
        string deviceType;
        bool status = false;
        int amSetPoint;
        int pmSetPoint;

    public:
        SmartDevice(string id, string name, string deviceType);
        virtual ~SmartDevice() = default;
        void activateDevice();
        void deavtivateDevice();
        string getId();
        string getName() const;
        string getDeviceType();
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