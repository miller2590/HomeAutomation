/*
 * SmartDevice.cpp
 * 
 * This file implements the SmartDevice class, which is the base class for all smart devices
 * in the home automation system. It includes methods for getting and setting the status of the 
 * device, and getting and setting the AM and PM set points.
 * 
 * @author Gage Miller
 */

#include "../include/SmartDevice.h"
#include <iostream>
#include <string>

//SmartDevice constructor
SmartDevice::SmartDevice(string id, string name, string deviceType) : id(id), name(name), deviceType(deviceType) {};

// Method to display the current settings of the device
void SmartDevice::displayCurrentSettings() const{
    cout << "Current status: " << to_string(status) << endl;
    cout << "Current AM start time: " << amSetPoint << endl;
    cout << "Current PM Start time: " << pmSetPoint << endl;
}

// Method to get the ID of the device
string SmartDevice::getId() {
    return id;
}

// Method to get the name of the device
string SmartDevice::getName() const {
    return name;
}

// Method to get the type of the device
string SmartDevice::getDeviceType() {
    return deviceType;
}

// Method to get the status of the device
bool SmartDevice::getStatus() {
    return status;
}

// Method to get the AM set point of the device
string SmartDevice::getAmSetPoint() {
    return amSetPoint;
}

// Method to get the PM set point of the device
string SmartDevice::getPmSetPoint() {
    return pmSetPoint;
}

// Method to set the ID of the device
void SmartDevice::setId(string newId) {  
    id = newId;
}

// Method to set the name of the device
void SmartDevice::setName(string newName) {
    name = newName;
}

// Method to set the stats of the device
void SmartDevice::setStatus() {
    
    if (status == true) {
        status = false;
    } else {
        status = true;
    }
}

// Method to set the AM set point of the device
void SmartDevice::setAmSetPoint(string newAmSetPoint) {
    amSetPoint = newAmSetPoint;
}

// Method to set the PM set point of the device
void SmartDevice::setPmSetPoint(string newPmSetPoint) {
    pmSetPoint = newPmSetPoint;
}
