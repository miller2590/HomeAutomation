#ifndef THERMOSTAT_H
#define THERMOSTAT_H

#include "SmartDevice.h"

class Thermostat : public SmartDevice{
    private:
        int currentTemp;
    
    public:
        Thermostat(string id, string name, string deviceType);
        //This will return int
        void getCurrentTemp();
        void setCurrentTemp(); 
};

#endif