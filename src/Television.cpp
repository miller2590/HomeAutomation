#include "../include/Television.h"
#include <iostream>

using namespace std;

Television::Television(int id, string name, string deviceType) : SmartDevice(id, name, deviceType) {};

//This will return int
void Television::getChannel() {
    cout << "Getting Channel..." << endl;
}

void Television::setChannel() {
    cout << "Set Channel..." << endl;
}
