#ifndef SECURITYSYSTEM_H
#define SECURITYSYSTEM_H

class SecuritySystem{
    private: 
        int sensitivity;
        bool motionLightsIsOn;
        bool alarmIsOn;

    public:
        SecuritySystem();
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