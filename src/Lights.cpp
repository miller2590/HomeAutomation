#include "../include/Lights.h"
#include <iostream>

using namespace std;

Lights::Lights(int id, string name, string deviceType) : SmartDevice(id, name, deviceType){}

void Lights::testMessage() {
    cout << "Testing Lights Connection..." << endl;
}