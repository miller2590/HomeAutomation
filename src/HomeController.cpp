#include "../include/HomeController.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <memory>
#include <tuple>
#include <algorithm>
#include <stdexcept>

using namespace std;

//HomeController constructor
HomeController::HomeController(){
    //I think these will have to check if the user opted for a manual override.
    //If so, these functions will be exited. Might have to take them out of the
    //constructor. 
    runAmMode();
    runPmMode();
    getDateTime();
};

//HomeController destructor
HomeController::~HomeController(){};

//This functon creates a device name and type based on user input
string HomeController::deviceNameConstruction(string deviceType) {

    string userDeviceName;
    cout << "______________________________________________" << endl;
    cout << "Please Enter a name for your " << deviceType << ": ";
    
    //Checks for names with spaces and concatenates
    //them with an "_"
    getline(cin, userDeviceName); 
    for (char& character : userDeviceName) {
        if (character == ' ') {
            character = '_';
        }
    }

    return userDeviceName;
}

//Adds new device to devices vector
void HomeController::addDevice(unique_ptr<SmartDevice> device) {
    devices.push_back(move(device));
}

//Deletes device from the vector based on device ID
void HomeController::deleteDevice() {
    if (devices.empty()) {
        noDevicesAvailable();
        return;
    }
    int userChoice;
    cout << "*************************************" << endl;
    cout << "Enter the ID of the Device to Delete." << endl;
    cout << "*************************************" << endl;
    showDevices();
    cout << "> ";
    cin >> userChoice;
    const SmartDevice* deviceToDelete = getDeviceById(userChoice);

    if (deviceToDelete) {
        cout << "(" << deviceToDelete->getName() << ")" << " will be removed." << endl;
        cout << "Would you like to continue? 1: Yes, 2: No " << endl;
        cout << "> ";

        int deleteConfirm;
        cin >> deleteConfirm;

        //Uses lambda function to iterate through the vector
        //and check if userChoice is == device ID.
        //Has basic error handling implimentations.
        if (deleteConfirm == 1) {
            devices.erase(
                std::remove_if(devices.begin(), devices.end(),
                    [userChoice](const auto& device) {
                        return device->getId() == userChoice;
                    }
                ),
                devices.end()
            );
            cout << "Device removed successfully." << endl;

        } else {
            cout << "Action Canceled." << endl;

        }
    } else {
        cout << "************************************************" << endl;
        cout << "Device with ID: " << userChoice << ", not found." << endl;
        cout << "************************************************" << endl;

    }
}

//Lists devices in a formated output with three columns
//Device ID, Device Name, Device Type
void HomeController::showDevices() {
    if (devices.empty()) {
    
        noDevicesAvailable();

    } else {
        cout << endl << endl;
        cout  << left << setw(15) << "Device ID" << setw(30) << "Device Name" << setw(45) << "Device Type" << endl;
        cout << setw(15) << "---------" << setw(30) << "-----------" << setw(45) << "-----------" << endl;

        for (const auto& device : devices) {
            cout << setw(15) << to_string(device->getId()) << setw(30) << device->getName() << setw(45) << device->getDeviceType() << '\n' << '\n';
        }
        cout << endl << endl;
    }
}

//Gets device by ID, uses try, catch block to handle device not found
const SmartDevice* HomeController::getDeviceById(int Id) const {
    try
    {
        for (auto& device : devices) {
            if (device->getId() == Id) {
                return device.get();
            }
        } 
    }
    catch(const std::exception& e)
    {
        cerr << "Error: " << e.what() << endl;
    }
    
    //Will likely return something more suitable than nullptr
    return nullptr;
}

//Will handle AM automation
void HomeController::runAmMode() {
    cout << "AM mode running..." << endl;
}

//Will handle PM automation
void HomeController::runPmMode() {
    cout << "PM mode running..." << endl;
}

//DateTime may need to be a public function,
//will re-assess this choice
void HomeController::getDateTime() {
    time_t currentTime = std::time(0);

    string currentTimeString = ctime(&currentTime);

    cout << "Current time and date: " << currentTimeString << endl; 
}

/*
******************************************************
*These two will be the meat of the system. I think
*that they will just save the vector of devices and
*the AM and PM settings. Once loaded, the program will
*set itself up.
******************************************************
*/
void HomeController::loadConfig() {
    cout << "Load Config File..." << endl;
}

void HomeController::saveConfig() {
    cout << "Save Config File..." << endl;
}
//******************************************************

//This will likely utilize both AM and PM Mode
//to have one robust function.
void HomeController::runAutomation() {
    cout << "Running Automation Task..." << endl;
}

//This function should be simple enough.
//I'm thinking a setStatus call and automation override.
void HomeController::manualOverride() {
    cout << "Running Manual Override..." << endl;
}

void HomeController::noDevicesAvailable() {
    cout << "##################################" << endl;
    cout << "There are no Devices yet!" << endl;
    cout << "Select option (1) to add a device!" << endl;
    cout << "##################################" << endl;
    cout << endl << endl;
}