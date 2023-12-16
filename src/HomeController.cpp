/*
 * HomeController.h
 * 
 * This file declares the HomeController class, which is responsible for managing
 * a collection of smart devices. The HomeController can run different modes 
 * (AM and PM), get the current date and time, and write the device settings to a file.
 * 
 * @author: Gage Miller
 */

#include "../include/HomeController.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <memory>
#include <tuple>
#include <algorithm>
#include <stdexcept>
#include <regex>

using namespace std;

//HomeController constructor
HomeController::HomeController(){};

//HomeController destructor
HomeController::~HomeController(){
    if (automationThread.joinable()) {
        automationThread.join();
    }
};

bool HomeController::isValidAmFormat(const string& timeString) {
    // Valid AM time regex
    regex amTimeRegex("^(0[0-9]|1[0-1]):[0-5][0-9]$");

    // Check if the input string matches the regex
    return regex_match(timeString, amTimeRegex);
}

bool HomeController::isValidPmFormat(const string& timeString) {
    // Valid PM time regex
    std::regex pmTimeRegex("^(12:[0-5][0-9]|1[0-9]|2[0-3]):[0-5][0-9]$");

    // Check if the input string matches the regex
    return std::regex_match(timeString, pmTimeRegex);
}

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
    string userChoice;
    cout << "**********************************************" << endl;
    cout << "Copy and paste the ID of the Device to Delete." << endl;
    cout << "**********************************************" << endl;
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

        /*
        *Uses lambda function to iterate through the vector
        *and check if userChoice is == device ID.
        *Has basic error handling implimentations.
        */
        if (deleteConfirm == 1) {
            devices.erase(
                std::remove_if(devices.begin(), devices.end(),
                    [userChoice](const auto& device) {
                        return device->getId() == userChoice;
                    }
                ),
                devices.end()
            );
            cout <<  "Device removed successfully." << endl;

        } else {
            cout << "Action Canceled." << endl;

        }
    } else {
        //Error handling for device not found
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
        //Formated output
        cout << endl;
        cout << left 
            << setw(40) << "Device ID" 
            << setw(20) << "Device Name" 
            << setw(15) << "Device Type" 
            << endl;

        cout << left
            << setw(40) << "-----------" 
            << setw(20) << "-----------" 
            << setw(15) << "-----------" 
            << endl;
        //Iterates through devices vector and outputs device info
        for (const auto& device : devices) {
            cout << left
                << setw(40) << device->getId() 
                << setw(20) << device->getName() 
                << setw(15) << device->getDeviceType() 
                << '\n' 
                << '\n';
        }
        cout << endl << endl;
    }
}

//Gets device by ID, uses try, catch block to handle device not found
SmartDevice* HomeController::getDeviceById(string Id) const {
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
    
    //Error handling for device not found
    return nullptr;
}

//Runs the AM mode
void HomeController::getDateTime(string& date, string& time) const {
    time_t currentTime = std::time(0);
    struct tm* timeInfo = std::localtime(&currentTime);

    // Format the date
    char dateBuffer[12];  // Mon Jan 01
    std::strftime(dateBuffer, sizeof(dateBuffer), "%a %b %d", timeInfo);
    date = std::string(dateBuffer);

    // Format the time
    char timeBuffer[6];  // HH:MM:SS
    std::strftime(timeBuffer, sizeof(timeBuffer), "%H:%M", timeInfo);
    time = std::string(timeBuffer);
}

//Runs the AM mode and sets the device status to on or off 
void HomeController::runAutomation() {
    if (devices.empty()) {
        //Error handling for no devices
        noDevicesAvailable();
        return;
    } 

    string userChoice;

    //Formated output for user to choose device to automate
    cout << "**********************************************" << endl;
    cout << "Copy and paste the ID of the Device to Automate." << endl;
    cout << "**********************************************" << endl;
    showDevices();
    cout << "> ";
    cin >> userChoice;
    
    //Gets device by ID 
    SmartDevice* deviceToAutomate = getDeviceById(userChoice);

    if (deviceToAutomate) {
        string userAmChoice, userPmChoice;

        cout << "Current Settings" << endl;
        cout << "*************************" << endl;
        deviceToAutomate->displayCurrentSettings();

        cout << "Please enter AM start time. HH:MM 24hr Format" << endl;
        cout << "> ";
        cin >> userAmChoice;

        cout << "Please enter PM stop time. HH:MM 24hr Format" << endl;
        cout << "> ";
        cin >> userPmChoice;

        //Checks if user input is valid and sets device start and stop times
        if (isValidAmFormat(userAmChoice) && isValidPmFormat(userPmChoice)) {
            deviceToAutomate->setAmSetPoint(userAmChoice);
            deviceToAutomate->setPmSetPoint(userPmChoice);
            cout << "Start and Stop times set." << endl;
        } 
        else {

            //Error handling for invalid time format
            cout << "**************" << endl;
            cout << "Invalid Entry." << endl;
            cout << "**************" << endl;
            return;
        }

        //Checks device type and sets device settings
        if (Thermostat* thermostat = dynamic_cast<Thermostat*>(deviceToAutomate)) {
            
            //Error handling for invalid temp range
            int userAmTemp, userPmTemp;
            cout << "Please enter AM temperature (60 - 80): ";
            cin >> userAmTemp;

            //Checks for valid temp range and sets temp
            if (userAmTemp >= 60 && userAmTemp <= 80) {
                thermostat->setAmTemp(userAmTemp);

                cout << "Please enter PM temperature (60 - 80): ";
                cin >> userPmTemp;

                //Checks for valid temp range and sets temp 
                if (userPmTemp >= 60 && userPmTemp <= 80) {
                    thermostat->setPmTemp(userPmTemp);
                    cout << "Temperatures Set." << endl;
                } else {
                    //Error handling for invalid temp range
                    cout << "Please enter a temp between 60 & 80." << endl;
                    return;
                }
 
            } else {
                //Error handling for invalid temp range
                cout << "Please enter a temp between 60 & 80." << endl;
                return;
            }

        // Checks device type and sets device settings  
        } else if (Television* television = dynamic_cast<Television*>(deviceToAutomate)) {
            confirmAndRunAutomation();
            cout << "Television Times Set." << endl;
            return;

        } else if (Lights* lights = dynamic_cast<Lights*>(deviceToAutomate)) {
            confirmAndRunAutomation();
            cout << "Light times set" << endl;
            return;

        } else if (SecuritySystem* securitySystem = dynamic_cast<SecuritySystem*>(deviceToAutomate)) {
            int userSensitivity;
            cout << "Please enter security light sensitivity (1 - 5)";
            cout << "> ";
            //Checks for valid sensitivity range and sets sensitivity
            if (cin >> userSensitivity) {
                //Error handling for invalid sensitivity range
                if (userSensitivity >=1 && userSensitivity <= 5) {
                    securitySystem->setSensitivity(userSensitivity);
                
                    confirmAndRunAutomation();
                    cout << "Sensitivity Set." << endl;
                } else {
                    cout << "Please Enter a number between 1 & 5." << endl;
                    return;
                }
            } else {
                //Error handling for whole number
                cout << "Please Enter a Whole Number." << endl;
                return;
            }
        } else {
            //Error handling for device type not found
            cout << "This device type is not supported for automation." << endl;
            return;
        }
        //Runs automation loop
        confirmAndRunAutomation();
    }
}

//Runs manual override and sets the device status to on or off
void HomeController::manualOverride() {
    stopAutomationLoop();
    cout << "Manual Override..." << endl;
}

// Automation loop runs every 30 seconds and checks if the current time matches the device start time 
// and sets the device status to on or off, and writes the device settings to a file in seperate thread
void HomeController::startAutomationLoop() {
    automationRunning = true;
    automationThread = thread([this]() {
        // Write the initial device settings to the file
        writeDeviceSettingsToFile();
        // Run the automation loop
        while (automationRunning) {
            string currentDate, currentTime;
            getDateTime(currentDate, currentTime);
            // Check if the current time matches the device start time
            for (auto& device : devices) {
                if (device->getAmSetPoint() == currentTime) {
                    device->setStatus();
                    writeDeviceSettingsToFile();
                }
                // Check if the current time matches the device stop time
                if (device->getPmSetPoint() == currentTime) {
                    device->setStatus();
                    writeDeviceSettingsToFile();
                }
            }
            // Sleep for 30 seconds before checking the time again
            this_thread::sleep_for(chrono::seconds(30));
        }
    });
}

// Stops the automation loop
void HomeController::stopAutomationLoop() {
    automationRunning = false;
    // Wait for the thread to finish before returning
    if (automationThread.joinable()) {
        automationThread.join();
    }
}

// Confirms that the user has finished setting up their devices and runs the automation loop
void HomeController::confirmAndRunAutomation() {
    string userConfirmation;
    cout << "Have you finished setting up your devices? 1: Yes, 2: No" << endl;
    cin >> userConfirmation;

    if (userConfirmation == "1") {
        startAutomationLoop();
    } else {
        cout << "Please finish setting up your devices." << endl;
    }

}

// Writes the device settings to a file in the current directory
void HomeController::writeDeviceSettingsToFile() {
    // Get the absolute path of the file
    filesystem::path filePath = filesystem::absolute("device_status.txt");

    // Print the path
    cout << endl;
    cout << "File path: " << filePath << endl;
    cout << "> ";
    // Open a file in append mode
    ofstream outfile(filePath, ios_base::app);

    // Check if the file was opened successfully
    if (!outfile) {
        cout << endl;
        cout << "Failed to open the file." << endl << endl;
        cout << "> ";
        return;
    }

    for (auto& device : devices) {
        // Write the device status to the file
        outfile << "Device ID: " << device->getId() << "\n"
                << "Device Name: " << device->getName() << "\n"
                << "Device Type: " << device->getDeviceType() << "\n"
                << "Current status: " << device->getStatus() << "\n"
                << "Current AM start time: " << device->getAmSetPoint() << "\n"
                << "Current PM Start time: " << device->getPmSetPoint() << "\n\n";
    }

    // Close the file
    outfile.close();
}

// Error handling for no devices
void HomeController::noDevicesAvailable() {
    cout << "#########################" << endl;
    cout << "There are no Devices yet!" << endl;
    cout << "#########################" << endl;
    cout << endl << endl;
}