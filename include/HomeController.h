#ifndef HOMECONTROLLER_H
#define HOMECONTROLLER_H

#include <vector>
#include <string>

using namespace std;

class HomeController{
    private:
        vector<string> devices;
        string configFile;
        void runAmMode();
        void runPmMode();
        void getDateTime();

    public:
        HomeController();
        void loadConfig();
        void saveConfig();
        void runAutomation();
        void manualOverride();   
};

#endif