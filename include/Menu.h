/*
 * Menu.h
 * 
 * This file declares the Menu class, which is responsible for handling the user interface
 * of the home automation system. It includes methods for displaying the menu, handling user
 * input, and performing actions based on user choices.
 * 
 * @author Gage Miller
 */

#ifndef MENU_H
#define MENU_H

#include "HomeController.h"
#include "GenerateUUID.h"

using namespace std;

// Menu class declaration
class Menu{

    // Declare private data members
    private:
    // HomeController object to access home automation system
    HomeController& homeController;

    // GenerateUUID object to generate unique identifiers
    GenerateUUID& generateUUID;
    void errorMessage();
    void clearBuffer();
    void setUpDeviceMenu();
    void setUpAutomationMenu();
    
    // Declare public methods
    public:
        // Constructor takes references to HomeController and GenerateUUID objects
        Menu(HomeController& homeController, GenerateUUID& generateUUID);
        void runMenu();
};

#endif