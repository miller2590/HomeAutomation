/*
 * SecuritySystem.h
 * 
 * This file declares the SecuritySystem class, which is a subclass of the SmartDevice class.
 * The SecuritySystem class represents a smart security system device in a home automation system.
 * It includes methods for getting and setting the sensitivity of the security system, 
 * checking the status of the motion lights and alarm, and turning on the motion lights.
 * 
 * @author Gage Miller
 */

#ifndef SECURITYSYSTEM_H
#define SECURITYSYSTEM_H

#include "SmartDevice.h"

// SecuritySystem class declaration
class SecuritySystem : public SmartDevice{

    // Declare private data members
    private: 
        int sensitivity;
        bool motionLightsIsOn = false;
        bool alarmIsOn = false;

    // Declare public methods
    public:
        // Constructor for SecuritySystem class
        SecuritySystem(string id, string name, string deviceType);
        int getSensitivity();
        bool getMotionLightsIsOn();
        bool getAlarmIsOn();
        void setSensitivity(int newSensitivity);
        void setMotionLightIsOn();
        void setAlarmIsOn();

};

#endif