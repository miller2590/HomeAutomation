#include "../include/SmartDevice.h"
#include <iostream>
#include <string>

SmartDevice::SmartDevice(int id, string name, string deviceType) : id(id), name(name), deviceType(deviceType) {};

void SmartDevice::activateDevice() {
    cout << "Device Activated..." << endl;
}

void SmartDevice::deavtivateDevice() {
    cout << "Device Deavtivated..." << endl;
}

//This will return int
int SmartDevice::getId() {
    return id;
}

string SmartDevice::getName() const {
    return name;
}

string SmartDevice::getDeviceType() {
    return deviceType;
}

//This will return bool
bool SmartDevice::getStatus() {
    return status;
}

//This will return int
void SmartDevice::getAmSetPoint() {
    cout << "Device AM set point..." << endl;
}

//This will return int
void SmartDevice::getPmSetPoint() {
    cout << "Device PM set point..." << endl;
}

void SmartDevice::setId(int newId) {
    //This will use a getDevices() function in oreder to sort through 
    //Device id's and make sure there are no duplicates.
    //Or, I will use UUID
    id = newId;
}

void SmartDevice::setName(string newName) {
    //This will use a getDevices() function in oreder to sort through 
    //Device names and make sure there are no duplicates.
    name = newName;
}

void SmartDevice::setSatus() {
    if (status) {
        status = false;
    } else {
        status = true;
    }
}

void SmartDevice::setAmSetPoint() {
    cout << "Set AM set point..." << endl;
}

void SmartDevice::setPmSetPoint() {
    cout << "Set PM set point..." << endl;
}
