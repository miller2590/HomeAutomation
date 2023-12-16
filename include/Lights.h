/*
 * Lights.h
 * 
 * This file declares the Lights class, which is a subclass of the SmartDevice class.
 * The Lights class represents a smart light device in a home automation system.
 * It includes a constructor and a method for testing the connection of the Lights device.
 * 
 * @author Gage Miller
 */

#ifndef LIGHTS_H
#define LIGHTS_H

#include "SmartDevice.h"

// Lights class declaration 
class Lights : public SmartDevice{

    // Declare public methods
    public:
        // Constructor 
        Lights(string id, string name, string deviceType);
        void testMessage();
};

#endif
