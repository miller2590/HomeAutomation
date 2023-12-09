#include "../include/SmartDevice.h"
#include <iostream>
#include <string>

SmartDevice::SmartDevice(int id, string name) : id(id), name(name) {};

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

string SmartDevice::getName() {
    return name;
}

//This will return bool
void SmartDevice::getStatus() {
    cout << "Device Status..." << endl;
}

//This will return int
void SmartDevice::getAmSetPoint() {
    cout << "Device AM set point..." << endl;
}

//This will return int
void SmartDevice::getPmSetPoint() {
    cout << "Device PM set point..." << endl;
}

void SmartDevice::setId() {
    cout << "Set Device ID..." << endl;
}

void SmartDevice::setName() {
    cout << "Set Device Name..." << endl;
}

void SmartDevice::setSatus() {
    cout << "Set Device Status..." << endl;
}

void SmartDevice::setAmSetPoint() {
    cout << "Set AM set point..." << endl;
}

void SmartDevice::setPmSetPoint() {
    cout << "Set PM set point..." << endl;
}
