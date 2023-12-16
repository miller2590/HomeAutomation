/*
 * GenerateUUID.h
 * 
 * This file declares the GenerateUUID class, which is responsible for generating unique identifiers (UUIDs).
 * The class has a single public method, generator(), which returns a string representation of a UUID.
 * 
 * @author Gage Miller
 */

#ifndef GENERATE_UUID_H
#define GENERATE_UUID_H

#include <iostream>
#include <iomanip>
#include <random>
#include <sstream>

using namespace std;

// GenerateUUID class declaration
class GenerateUUID {
    public:
        // Method to generate a UUID
        string generator();       
};

#endif