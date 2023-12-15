#include "../include/HomeController.h"
#include "../include/GenerateUUID.h"
#include "../include/Lights.h"
#include "../include/Menu.h"
#include "../include/SecuritySystem.h"
#include "../include/SmartDevice.h"
#include "../include/Television.h"
#include "../include/Thermostat.h"
#include "../include/Vacuum.h"
#include <iostream>

using namespace std;

int main() {

    HomeController homeController;
    GenerateUUID generateUUID;
    
    Menu menu(homeController, generateUUID);
    menu.runMenu();

    homeController.stopAutomationLoop();
    return 0;
}