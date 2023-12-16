/*
 * Thermostat.cpp
 * 
 * This file implements the Thermostat class, which is a subclass of the SmartDevice class.
 * The Thermostat class represents a smart thermostat device in a home automation system.
 * It includes methods for displaying the current settings, and getting the current, AM, and PM temperatures.
 * 
 * @author Gage Miller
 */

#include "../include/SmartDevice.h"
#include "../include/Thermostat.h"
#include <iostream>

using namespace std;

// Thermostat constructor, which calls the base class (SmartDevice) constructor
Thermostat::Thermostat(string id, string name, string deviceType) : SmartDevice(id, name, deviceType){};

// Method to display the current settings of the device (overrides the base class method)
void Thermostat::displayCurrentSettings() const {
    SmartDevice::displayCurrentSettings();
    cout << "Current Temp: " << to_string(currentTemp) << endl;
    cout << "Current AM Temp: " << to_string(amTemp) << endl;
    cout << "Current PM Temp: " << to_string(pmTemp) << endl;
}

// Method to get the current temperature
int Thermostat::getCurrentTemp() {
    return currentTemp;
}

// Method to get the AM temperature
int Thermostat::getAmTemp() {
    return amTemp;
}

// Method to get the PM temperature
int Thermostat::getPmTemp() {
    return pmTemp;
}

// Method to set the current temperature
void Thermostat::setCurrentTemp(int newTemp) {
    currentTemp = newTemp;
}

// Method to set the AM temperature
void Thermostat::setAmTemp(int newAmTemp) {
    amTemp = newAmTemp;
}

// Method to set the PM temperature
void Thermostat::setPmTemp(int newPmTemp) {
    pmTemp = newPmTemp;
}
