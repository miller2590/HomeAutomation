/*
 * SecuritySystem.cpp
 * 
 * This file implements the SecuritySystem class, which is a subclass of the SmartDevice class.
 * The SecuritySystem class represents a smart security system device in a home automation system.
 * It includes methods for getting and setting the sensitivity of the security system, 
 * checking the status of the motion lights and alarm, and turning on the motion lights.
 * 
 * @author Gage Miller
 */

#include "../include/SecuritySystem.h"
#include <iostream>

using namespace std;

// SecuritySystem constructor, which calls the base class (SmartDevice) constructor
SecuritySystem::SecuritySystem(string id, string name, string deviceType) : SmartDevice(id, name, deviceType){};

// Method to set the sensitivity of the security lights
int SecuritySystem::getSensitivity() {
    return sensitivity;
};

// Method to check if the motion lights are on
bool SecuritySystem::getMotionLightsIsOn() {
    return motionLightsIsOn;
}

// Method to check if the alarm is on
bool SecuritySystem::getAlarmIsOn() {
    return alarmIsOn;
}

// Method to set the sensitivity of the security lights
void SecuritySystem::setSensitivity(int newSensitivity) {
    sensitivity = newSensitivity;
}

// Method to set the motion lights to on
void SecuritySystem::setMotionLightIsOn() {
    if (motionLightsIsOn == false) {
        motionLightsIsOn = true;
    } else {
        motionLightsIsOn = false;
    }
}

// Method to set the alarm to on
void SecuritySystem::setAlarmIsOn() {
    if (alarmIsOn == false) {
        alarmIsOn = true;
    } else {
        alarmIsOn = false;
    }
}
