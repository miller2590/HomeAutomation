#ifndef MENU_H
#define MENU_H

#include "HomeController.h"

using namespace std;

class Menu{
    private:
    HomeController& homeController;
    void clearBuffer();
    void setUpDeviceMenu();
    
    public:
        Menu(HomeController& homeController);
        void runMenu();
};

#endif