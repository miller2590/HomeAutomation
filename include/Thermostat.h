/*
 * Thermostat.h
 * 
 * This file declares the Thermostat class, which is a subclass of the SmartDevice class.
 * The Thermostat class represents a smart thermostat device in a home automation system.
 * It includes methods for displaying the current settings, getting and setting the current, AM, and PM temperatures.
 * 
 * @author Gage Miller
 */

#ifndef THERMOSTAT_H
#define THERMOSTAT_H

#include "SmartDevice.h"

// Thermostat class declaration
class Thermostat : public SmartDevice{

    // Declare private data members
    private:
        int currentTemp = 0;
        int amTemp = 0;
        int pmTemp = 0;
    
    // Declare public methods
    public:
        // Constructor for Thermostat class
        Thermostat(string id, string name, string deviceType);

        // Virtual method to display current settings of smart device
        void displayCurrentSettings() const override;
        int getCurrentTemp();
        int getAmTemp();
        int getPmTemp();
        void setCurrentTemp(int newTemp); 
        void setAmTemp(int newAmTemp);
        void setPmTemp(int newPmTemp);

};

#endif