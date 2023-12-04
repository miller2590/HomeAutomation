#ifndef THERMOSTAT_H
#define THERMOSTAT_H

class Thermostat{
    private:
        int currentTemp;
    
    public:
        Thermostat();
        //This will return int
        void getCurrentTemp();
        void setCurrentTemp(); 
};

#endif