#ifndef MENU_H
#define MENU_H

#include "HomeController.h"
#include "GenerateUUID.h"

using namespace std;

class Menu{
    private:
    HomeController& homeController;
    GenerateUUID& generateUUID;
    void errorMessage();
    void clearBuffer();
    void setUpDeviceMenu();
    
    public:
        Menu(HomeController& homeController, GenerateUUID& generateUUID);
        void runMenu();
};

#endif