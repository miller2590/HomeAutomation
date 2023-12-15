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
        string amSetPoint = "none";
        string pmSetPoint = "none";

    public:
        SmartDevice(string id, string name, string deviceType);
        virtual ~SmartDevice() = default;
        virtual void displayCurrentSettings() const;
        string getId();
        string getName() const;
        string getDeviceType();
        bool getStatus();
        string getAmSetPoint();
        string getPmSetPoint();
        void setId(string newId);
        void setName(string newName);
        void setStatus();
        void setAmSetPoint(string newAmSetPoint);
        void setPmSetPoint(string newPmSetPoint);
};

#endif