/*
 * Television.h
 * 
 * This file declares the Television class, which is a subclass of the SmartDevice class.
 * The Television class represents a smart television device in a home automation system.
 * It includes a constructor, and methods for getting and setting the television channel.
 * 
 * @author Gage Miller
 */

#ifndef TELEVISION_H
#define TELEVISION_H

#include "SmartDevice.h"

// Television class declaration
class Television : public SmartDevice {

    // Declare private data members
    private:
        int channel;

    public:
        // Constructor for Television class
        Television(string id, string name, string deviceType);
        int getChannel();
        void setChannel();
};

#endif