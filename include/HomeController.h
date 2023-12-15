
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

class HomeController{
    private:
        vector<unique_ptr<SmartDevice>> devices;
        string configFile;
        void getDateTime(string& date, string& time) const;
        bool isValidAmFormat(const string& timeString);
        bool isValidPmFormat(const string& timeString);
        bool automationRunning = false;
        thread automationThread;

    public:
        HomeController();
        virtual ~HomeController();
        string deviceNameConstruction(string deviceType);
        void addDevice(unique_ptr<SmartDevice> device);
        void deleteDevice();
        void showDevices();
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