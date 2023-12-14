#ifndef SECURITYSYSTEM_H
#define SECURITYSYSTEM_H

#include "SmartDevice.h"

class SecuritySystem : public SmartDevice{
    private: 
        int sensitivity;
        bool motionLightsIsOn;
        bool alarmIsOn;

    public:
        SecuritySystem(string id, string name, string deviceType);
        //This will return an int
        void getSensitivity();
        //This will return a bool
        void getMotionLightsIsOn();
        //This will return a bool
        void getAlarmIsOn();
        void setSensitivity();
        void setMotionLightIsOn();
        void setAlarmIsOn();

};

#endif