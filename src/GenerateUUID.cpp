/*
 * GenerateUUID.cpp
 * 
 * This file implements the GenerateUUID class, which is responsible for generating
 * unique identifiers (UUIDs). The UUIDs are generated using a random number generator
 * and are formatted as hexadecimal strings.
 * 
 * @author Gage Miller
 */

#include "../include/GenerateUUID.h"

// The generator method generates a UUID
string GenerateUUID::generator() {
    // Create a random device
    random_device rd;

    // Seed the Mersenne Twister pseudo-random generator of 64-bit numbers with the random device
    mt19937_64 gen(rd());

    // Create a uniform distribution of 64-bit unsigned integers
    uniform_int_distribution<uint64_t> dis(0, UINT64_MAX);

    // Generate two random 64-bit numbers
    uint64_t section_1 = dis(gen);
    uint64_t section_2 = dis(gen);

    // Create a string stream
    stringstream ss;

    // Set the stream to output hexadecimal numbers, and fill unused spaces with zeros
    ss << hex << setfill('0');

    // Write the two random numbers to the stream, separated by a dash
    ss << setw(16) << section_1 << "-";
    ss << setw(16) << section_2;

    // Return the UUID as a string
    return ss.str();    
}