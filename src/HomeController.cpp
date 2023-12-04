#include "../include/HomeController.h"
#include <iostream>
#include <ctime>

using namespace std;

//Template Class/function possibility

HomeController::HomeController(){
    //May need to rethink private vs protected here
    runAmMode();
    runPmMode();
    getDateTime();
};

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