#include "../include/Lights.h"
#include <iostream>

using namespace std;

Lights::Lights(string id, string name, string deviceType) : SmartDevice(id, name, deviceType){}

void Lights::testMessage() {
    cout << "Testing Lights Connection..." << endl;
}