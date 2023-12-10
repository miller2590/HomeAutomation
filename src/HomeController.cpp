#include "../include/HomeController.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <memory>
#include <tuple>
#include <algorithm>

using namespace std;


HomeController::HomeController(){
    //May need to rethink private vs protected here
    runAmMode();
    runPmMode();
    getDateTime();
};

HomeController::~HomeController(){};

string HomeController::deviceNameConstruction(string deviceType) {

    string userDeviceName;
    cout << "______________________________________________" << endl;
    cout << "Please Enter a name for your " << deviceType << ": ";
    
    getline(cin, userDeviceName);
    for (char& character : userDeviceName) {
        if (character == ' ') {
            character = '_';
        }
    }

    return userDeviceName;
}

void HomeController::addDevice(unique_ptr<SmartDevice> device) {
    devices.push_back(move(device));
}

void HomeController::deleteDevice() {
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
        cout << "Device with ID: " << userChoice << ", not found." << endl;
    }
}

void HomeController::showDevices() {
    if (devices.empty()) {
    
        cout << "##################################" << endl;
        cout << "There are no Devices yet!" << endl;
        cout << "Select option (1) to add a device!" << endl;
        cout << "##################################" << endl;
        cout << endl << endl;

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

const SmartDevice* HomeController::getDeviceById(int Id) const {
    for (auto& device : devices) {
        if (device->getId() == Id) {
            return device.get();
        }
    }
}

void HomeController::runAmMode() {
    cout << "AM mode running..." << endl;
}

void HomeController::runPmMode() {
    cout << "PM mode running..." << endl;
}

void HomeController::getDateTime() {
    time_t currentTime = std::time(0);

    string currentTimeString = ctime(&currentTime);

    cout << "Current time and date: " << currentTimeString << endl; 
}

void HomeController::loadConfig() {
    cout << "Load Config File..." << endl;
}

void HomeController::saveConfig() {
    cout << "Save Config File..." << endl;
}

void HomeController::runAutomation() {
    cout << "Running Automation Task..." << endl;
}

void HomeController::manualOverride() {
    cout << "Running Manual Override..." << endl;
}