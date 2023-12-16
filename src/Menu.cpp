/*
 * Menu.cpp
 * 
 * This file implements the Menu class, which is responsible for handling the user interface
 * of the home automation system. It includes methods for displaying the menu, handling user
 * input, and performing actions based on user choices.
 * 
 * @author Gage Miller
 */

#include "../include/Menu.h"
#include "../include/Television.h"
#include "../include/Thermostat.h"
#include "../include/Lights.h"
#include "../include/SecuritySystem.h"
#include "../include/SmartDevice.h"
#include <iostream>
#include <limits>
#include <memory>
#include <algorithm>
#include <string>

using namespace std;

//Menu constructor injects HomeController as dependency
Menu::Menu(HomeController& homeController, GenerateUUID& generateUUID) : homeController(homeController), generateUUID(generateUUID){};

//Error message for failed actions
void Menu::errorMessage() {
    cout << endl << endl;
    cout << "*************ERROR*****************" << endl;
    cout << "Invalid choice, please try again..." << endl;
    cout << "*************ERROR*****************" << endl;
    cout << endl << endl;

    clearBuffer();
}

//Clears the input buffer in menu screens
void Menu::clearBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

//As of now, this only sets up the required attributes of a device.
//This is a sub menu
void Menu::setUpDeviceMenu() {
    //Array of device types
    string deviceType[4] = {"Thermostat", "Television", "Lights", "Security System"};
    int userOption;
    
    //Menu options
    do
    {
        cout << "**********************************************" << endl;
        cout << "Which device would you like to add?" << endl;
        cout << "1. Thermostat" << endl;
        cout << "2. Television" << endl;
        cout << "3. Lights" << endl;
        cout << "4. Security System" << endl;
        cout << "5. Return to Main Menu" << endl;
        cout << "**********************************************" << endl;
        cout << "> ";

        cin >> userOption;

        //Switch statement for user input and device creation 
        switch (userOption)
        {
        case 1:
            clearBuffer();
            // Add thermostat to the home controller
            homeController.addDevice(make_unique<Thermostat>(generateUUID.generator(), homeController.deviceNameConstruction(deviceType[0]), deviceType[0]));
            homeController.showDevices();
            clearBuffer();
            break;
        case 2:
            clearBuffer();
            //Add television to the home controller
            homeController.addDevice(make_unique<Television>(generateUUID.generator(), homeController.deviceNameConstruction(deviceType[1]), deviceType[1]));
            homeController.showDevices();
            clearBuffer();
            
            break;
        case 3:
            clearBuffer();
            //Add lights to the home controller
            homeController.addDevice(make_unique<Lights>(generateUUID.generator(), homeController.deviceNameConstruction(deviceType[2]), deviceType[2]));
            homeController.showDevices();
            clearBuffer();

            break;
        case 4:
            clearBuffer();
            //Add security system to the home controller
            homeController.addDevice(make_unique<SecuritySystem>(generateUUID.generator(), homeController.deviceNameConstruction(deviceType[3]), deviceType[3]));
            homeController.showDevices();
            clearBuffer();
            break;
        case 5:
        //Return to main menu
            cout << "Returning to Main Menu..." << endl;
            break;
        default:
        //Error message for invalid input
            errorMessage();
            break;
        }
    } while (userOption != 5);
    
}

//Sub menu for automating or manually operating a device
void Menu::setUpAutomationMenu() {
    int userOption;
    
    do {
        cout << "*****************************" << endl;
        cout << "Please make a Selection." << endl;
        cout << "1. Automate a Device." << endl;
        cout << "2. Manually operate a device." << endl;
        cout << "3. Return to Main Menu." << endl;
        cout << "*****************************" << endl;
        cout << "> ";

        cin >> userOption;

        // Switch statement for user input and device automation
        switch (userOption)
        {
        case 1:
        //Automate a device in the home controller
            homeController.runAutomation();
            break;
        case 2:
        //Manually operate a device in the home controller
            homeController.manualOverride();
            break;
        case 3:
        //Return to main menu
            cout << "Returning to Main Menu..." << endl;
            break;
        default:
        //Error message for invalid input
            errorMessage();
            break;
        }
    } while (userOption != 3);
}

//Main menu options
void Menu::runMenu() {

    int userOption;

    do {

        cout << "========== Main Menu ================" << endl;
        cout << "Please make a selection: " << endl;
        cout << "1. Add a new device." << endl;
        cout << "2. List current devices." << endl;
        cout << "3. Automate or manually operate a device." << endl;
        cout << "4. Delete a device." << endl; 
        cout << "5. Exit Program." << endl;
        cout << "======= Home Automation =============" << endl;
        cout << "> ";

        cin >> userOption;

        //Switch statement for user input and menu options 
        switch (userOption)
        {
        case 1:
            //Sub menu for adding a device
            setUpDeviceMenu();
            break;
        case 2:
            //Show devices in the home controller
            homeController.showDevices();
            break;
        case 3:
            //Sub menu for automating or manually operating a device
            setUpAutomationMenu();
            break;
        case 4:
            //Delete a device in the home controller
            homeController.deleteDevice();
            clearBuffer();
            //Show devices in the home controller
            homeController.showDevices();
            break;
        case 5:
        //Exit program
            cout << "Exiting Program...." << endl;
            break;
        default:
            //Error message for invalid input
            errorMessage(); 
            break;
        }
        
    } while (userOption != 5); 
}