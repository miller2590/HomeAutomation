#ifndef THERMOSTAT_H
#define THERMOSTAT_H

#include "SmartDevice.h"

class Thermostat : public SmartDevice{
    private:
        int currentTemp = 0;
        int amTemp = 0;
        int pmTemp = 0;
    
    public:
        Thermostat(string id, string name, string deviceType);
        void displayCurrentSettings() const override;
        int getCurrentTemp();
        int getAmTemp();
        int getPmTemp();
        void setCurrentTemp(int newTemp); 
        void setAmTemp(int newAmTemp);
        void setPmTemp(int newPmTemp);

};

#endif