#include "../include/Menu.h"
#include "../include/HomeController.h"
#include "../include/Television.h"
#include "../include/Thermostat.h"
#include "../include/SmartDevice.h"
#include <iostream>
#include <limits>
#include <memory>
#include <algorithm>
#include <string>

using namespace std;

Menu::Menu(HomeController& homeController) : homeController(homeController){};

void Menu::errorMessage() {
    cout << endl << endl;
    cout << "*************ERROR*****************" << endl;
    cout << "Invalid choice, please try again..." << endl;
    cout << "*************ERROR*****************" << endl;
    cout << endl << endl;

    clearBuffer();
}

void Menu::clearBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void Menu::setUpDeviceMenu() {
    string deviceType[4] = {"Thermostat", "Television", "Lights", "Security System"};
    int userOption;
    
    do
    {
        cout << "**********************************************" << endl;
        cout << "Which device would you like to add and set up?" << endl;
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
            
            clearBuffer();
            
            homeController.addDevice(make_unique<Thermostat>(2, homeController.deviceNameConstruction(deviceType[0]), deviceType[0]));
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
            break;
        case 4:
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

void Menu::runMenu() {

    int userOption;

    do {

        cout << "========== Main Menu ================" << endl;
        cout << "Please make a selection: " << endl;
        cout << "1. Add and setup a new device." << endl;
        cout << "2. List current devices." << endl;
        cout << "3. Edit a device." << endl;
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
            break;
        case 3:
            break;
        case 4:
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