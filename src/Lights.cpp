/*
 * Lights.cpp
 * 
 * This file implements the Lights class, which is a subclass of the SmartDevice class.
 * The Lights class represents a smart light device in a home automation system.
 * 
 * @author Gage Miller
 */


#include "../include/Lights.h"
#include <iostream>

using namespace std;

// Lights constructor, which calls the base class (SmartDevice) constructor
Lights::Lights(string id, string name, string deviceType) : SmartDevice(id, name, deviceType){}

// Method to test the connection of the Lights device
void Lights::testMessage() {
    // Output a test message to the console
    cout << "Testing Lights Connection..." << endl;
}