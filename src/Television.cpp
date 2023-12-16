/*
 * Television.cpp
 * 
 * This file implements the Television class, which is a subclass of the SmartDevice class.
 * The Television class represents a smart television device in a home automation system.
 * It includes methods for getting and setting the television channel.
 * 
 * @author Gage Miller
 */

#include "../include/Television.h"
#include <iostream>

using namespace std;

// Television constructor, which calls the base class (SmartDevice) constructor
Television::Television(string id, string name, string deviceType) : SmartDevice(id, name, deviceType) {};

// Method to get the channel of the television
int Television::getChannel() {
    return channel;
}

// Method to set the channel of the television
void Television::setChannel() {
    cout << "Set Channel..." << endl;
}
