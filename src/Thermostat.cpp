#include "../include/SmartDevice.h"
#include "../include/Thermostat.h"
#include <iostream>

using namespace std;

Thermostat::Thermostat(string id, string name, string deviceType) : SmartDevice(id, name, deviceType){};

//This will return int

void Thermostat::getCurrentTemp() {
    cout << "Get Current Temp..." << endl;
}

void Thermostat::setCurrentTemp() {
    cout << "Set Current Temp..." << endl;
}
