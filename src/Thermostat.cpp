#include "../include/SmartDevice.h"
#include "../include/Thermostat.h"
#include <iostream>

using namespace std;

Thermostat::Thermostat(string id, string name, string deviceType) : SmartDevice(id, name, deviceType){};

void Thermostat::displayCurrentSettings() const {
    SmartDevice::displayCurrentSettings();
    cout << "Current Temp: " << to_string(currentTemp) << endl;
    cout << "Current AM Temp: " << to_string(amTemp) << endl;
    cout << "Current PM Temp: " << to_string(pmTemp) << endl;
}

int Thermostat::getCurrentTemp() {
    return currentTemp;
}

int Thermostat::getAmTemp() {
    return amTemp;
}

int Thermostat::getPmTemp() {
    return pmTemp;
}

void Thermostat::setCurrentTemp(int newTemp) {
    currentTemp = newTemp;
}

void Thermostat::setAmTemp(int newAmTemp) {
    amTemp = newAmTemp;
}

void Thermostat::setPmTemp(int newPmTemp) {
    pmTemp = newPmTemp;
}
