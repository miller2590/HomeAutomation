/*
 * HomeController.h
 * 
 * This file declares the HomeController class, which is responsible for managing
 * a collection of smart devices in a home automation system. The HomeController can 
 * get the current date and time, validate AM and PM time formats, and manage a vector 
 * of unique pointers to SmartDevice objects.
 * 
 * @author Gage Miller
 */

#ifndef HOMECONTROLLER_H
#define HOMECONTROLLER_H

#include "SmartDevice.h"
#include "Thermostat.h"
#include "Television.h"
#include "Lights.h"
#include "SecuritySystem.h"
#include <ioStream>
#include<memory>
#include <fstream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>
#include <filesystem>

using namespace std;

// HomeController class declaration 
class HomeController{
    // Declare private data members
    private:
        vector<unique_ptr<SmartDevice>> devices;
        string configFile;
        void getDateTime(string& date, string& time) const;
        bool isValidAmFormat(const string& timeString);
        bool isValidPmFormat(const string& timeString);
        bool automationRunning = false;
        // Thread to run automation loop
        thread automationThread;

    // Declare public methods
    public:
        HomeController();
        virtual ~HomeController();
        string deviceNameConstruction(string deviceType);

        // Uses unique_ptr to create a smart device object and add it to the vector
        void addDevice(unique_ptr<SmartDevice> device);
        void deleteDevice();
        void showDevices();

        // Uses unique_ptr to get a smart device object from the vector by ID
        SmartDevice* getDeviceById (string Id) const;
        void runAutomation();
        void manualOverride(); 
        void confirmAndRunAutomation();
        void startAutomationLoop();
        void stopAutomationLoop();
        void writeDeviceSettingsToFile();
        void noDevicesAvailable();
};

#endif