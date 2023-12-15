#include "../include/Television.h"
#include <iostream>

using namespace std;

Television::Television(string id, string name, string deviceType) : SmartDevice(id, name, deviceType) {};


void Television::getChannel() {
    cout << "Getting Channel..." << endl;
}

void Television::setChannel() {
    cout << "Set Channel..." << endl;
}
