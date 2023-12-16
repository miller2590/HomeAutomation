/*
 * SmartDevice.h
 * 
 * This file declares the SmartDevice class, which is the base class for all smart devices
 * in the home automation system. It includes methods for getting and setting the status of the 
 * device, and getting and setting the AM and PM set points.
 * 
 * @author Gage Miller
 */

#ifndef SMARTDEVICE_H
#define SMARTDEVICE_H

#include <string>

using namespace std;

// SmartDevice class declaration
class SmartDevice{

    // Declare private data members
    private:
        string id;
        string name;
        string deviceType;
        bool status = false;
        string amSetPoint = "none";
        string pmSetPoint = "none";

    // Declare public methods
    public:
        // Constructor for SmartDevice class
        SmartDevice(string id, string name, string deviceType);

        // Virtual destructor for SmartDevice class
        virtual ~SmartDevice() = default;

        // Virtual method to display current settings of smart device
        virtual void displayCurrentSettings() const;
        string getId();
        string getName() const;
        string getDeviceType();
        bool getStatus();
        string getAmSetPoint();
        string getPmSetPoint();
        void setId(string newId);
        void setName(string newName);
        void setStatus();
        void setAmSetPoint(string newAmSetPoint);
        void setPmSetPoint(string newPmSetPoint);
};

#endif