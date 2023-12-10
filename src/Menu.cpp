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
Menu::Menu(HomeController& homeController) : homeController(homeController){};

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

        switch (userOption)
        {
        case 1:
            // Will add id check for duplicates function/update id here
            clearBuffer();
            homeController.addDevice(make_unique<Thermostat>(0, homeController.deviceNameConstruction(deviceType[0]), deviceType[0]));
            homeController.showDevices();
            clearBuffer();
            break;
        case 2:
            clearBuffer();
            // Will add id check for duplicates function/update id here
            homeController.addDevice(make_unique<Television>(1, homeController.deviceNameConstruction(deviceType[1]), deviceType[1]));
            homeController.showDevices();
            clearBuffer();
            
            break;
        case 3:

            clearBuffer();
            // Will add id check for duplicates function/update id here
            homeController.addDevice(make_unique<Lights>(2, homeController.deviceNameConstruction(deviceType[2]), deviceType[2]));
            homeController.showDevices();
            clearBuffer();

            break;
        case 4:

            clearBuffer();
            // Will add id check for duplicates function/update id here
            homeController.addDevice(make_unique<SecuritySystem>(3, homeController.deviceNameConstruction(deviceType[3]), deviceType[1]));
            homeController.showDevices();
            clearBuffer();
            break;
        case 5:
            cout << "Returning to Main Menu..." << endl;
            break;
        default:
            errorMessage();
            break;
        }
    } while (userOption != 5);
    
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

        switch (userOption)
        {
        case 1:
            setUpDeviceMenu();
            break;
        case 2:
            homeController.showDevices();
            break;
        case 3:
            //This is my next portion to tackle this week
            cout << "Your Device is magically automated now." << endl;
            
        case 4:
            homeController.deleteDevice();
            clearBuffer();
            homeController.showDevices();

            break;
        case 5:
            cout << "Exiting Program...." << endl;
            break;
        default:
            
            errorMessage(); 
            break;
        }
        
    } while (userOption != 5); 
}