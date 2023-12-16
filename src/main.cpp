/*
 * main.cpp
 * 
 * This is the main entry point of the home automation program. It includes the necessary
 * header files, creates instances of HomeController, GenerateUUID, and Menu, runs the menu,
 * stops the automation loop in the HomeController, and then exits.
 * 
 * @author Gage Miller
 */

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

    // Create an instance of HomeController and GenerateUUID
    HomeController homeController;
    GenerateUUID generateUUID;
    
    // Create an instance of Menu and run it
    Menu menu(homeController, generateUUID);
    menu.runMenu();

    // Stop the automation loop in the HomeController if destructor hasn't already
    homeController.stopAutomationLoop();
    return 0;
}