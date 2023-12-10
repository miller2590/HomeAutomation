#ifndef THERMOSTAT_H
#define THERMOSTAT_H

class Thermostat : public SmartDevice{
    private:
        int currentTemp;
    
    public:
        Thermostat(int id, string name);
        //This will return int
        void getCurrentTemp();
        void setCurrentTemp(); 
};

#endif