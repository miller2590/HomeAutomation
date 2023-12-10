#ifndef HOMECONTROLLER_H
#define HOMECONTROLLER_H

#include "SmartDevice.h"

#include<memory>
#include <vector>
#include <string>

using namespace std;

class HomeController{
    private:
        vector<unique_ptr<SmartDevice>> devices;
        string configFile;
        void runAmMode();
        void runPmMode();
        void getDateTime();

    public:
        HomeController();
        virtual ~HomeController();
        string deviceNameConstruction(string deviceType);
        void addDevice(unique_ptr<SmartDevice> device);
        void showDevices();
        void loadConfig();
        void saveConfig();
        void runAutomation();
        void manualOverride();   
};

#endif