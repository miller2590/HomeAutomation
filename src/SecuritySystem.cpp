#include "../include/SecuritySystem.h"
#include <iostream>

using namespace std;

SecuritySystem::SecuritySystem(string id, string name, string deviceType) : SmartDevice(id, name, deviceType){};


int SecuritySystem::getSensitivity() {
    return sensitivity;
};

void SecuritySystem::getMotionLightsIsOn() {
    cout << "Motion Lights are On..." << endl;
}

void SecuritySystem::getAlarmIsOn() {
    cout << "Alarm is On..." << endl;
}

void SecuritySystem::setSensitivity(int newSensitivity) {
    sensitivity = newSensitivity;
}

void SecuritySystem::setMotionLightIsOn() {
    cout << "Setting Motion Lights On..." << endl;
}

void SecuritySystem::setAlarmIsOn() {
    cout << "Setting Alarm On..." << endl;
}
