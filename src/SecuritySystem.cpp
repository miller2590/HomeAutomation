#include "../include/SecuritySystem.h"
#include <iostream>

using namespace std;

SecuritySystem::SecuritySystem(int id, string name, string deviceType) : SmartDevice(id, name, deviceType){};

//This will return an int
void SecuritySystem::getSensitivity() {
    cout << "Sensitivity is {}..." << endl;

};

//This will return a bool
void SecuritySystem::getMotionLightsIsOn() {
    cout << "Motion Lights are On..." << endl;
}

//This will return a bool
void SecuritySystem::getAlarmIsOn() {
    cout << "Alarm is On..." << endl;
}

void SecuritySystem::setSensitivity() {
    cout << "Setting Sensitivity to {}..." << endl;
}

void SecuritySystem::setMotionLightIsOn() {
    cout << "Setting Motion Lights On..." << endl;
}

void SecuritySystem::setAlarmIsOn() {
    cout << "Setting Alarm On..." << endl;
}
