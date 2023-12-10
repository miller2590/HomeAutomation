#include "../include/HomeController.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <memory>

using namespace std;

//Template Class/function possibility

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

void HomeController::showDevices() {
    if (devices.empty()) {
        cout << "There are no Devices yet!" << endl;
    } else {
        std::cout  << left << setw(15) << "Device ID" << setw(30) << "Device Name" << endl;
        std::cout << setw(15) << "---------" << setw(30) << "-----------" << endl;

        for (const auto& device : devices) {
            cout << setw(15) << std::to_string(device->getId()) << setw(30) << device->getName() << '\n' << '\n';
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