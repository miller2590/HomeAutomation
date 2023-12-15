#include "../include/SmartDevice.h"
#include <iostream>
#include <string>

//SmartDevice constructor
SmartDevice::SmartDevice(string id, string name, string deviceType) : id(id), name(name), deviceType(deviceType) {};

void SmartDevice::displayCurrentSettings() const{
    cout << "Current status: " << to_string(status) << endl;
    cout << "Current AM start time: " << amSetPoint << endl;
    cout << "Current PM Start time: " << pmSetPoint << endl;
}

string SmartDevice::getId() {
    return id;
}

string SmartDevice::getName() const {
    return name;
}

string SmartDevice::getDeviceType() {
    return deviceType;
}


bool SmartDevice::getStatus() {
    return status;
}


string SmartDevice::getAmSetPoint() {
    return amSetPoint;
}

//This will return int
string SmartDevice::getPmSetPoint() {
    return pmSetPoint;
}

void SmartDevice::setId(string newId) {  
    id = newId;
}

void SmartDevice::setName(string newName) {
    name = newName;
}

void SmartDevice::setStatus() {
    
    if (status == true) {
        status = false;
    } else {
        status = true;
    }
}

void SmartDevice::setAmSetPoint(string newAmSetPoint) {
    amSetPoint = newAmSetPoint;
}

void SmartDevice::setPmSetPoint(string newPmSetPoint) {
    pmSetPoint = newPmSetPoint;
}
