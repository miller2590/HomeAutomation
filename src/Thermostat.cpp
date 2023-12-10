#include "../include/SmartDevice.h"
#include "../include/Thermostat.h"
#include <iostream>

using namespace std;

Thermostat::Thermostat(int id, string name) : SmartDevice(id, name){};

//This will return int

void Thermostat::getCurrentTemp() {
    cout << "Get Current Temp..." << endl;
}

void Thermostat::setCurrentTemp() {
    cout << "Set Current Temp..." << endl;
}
