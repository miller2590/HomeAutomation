#include "../include/Television.h"
#include <iostream>

using namespace std;

Television::Television(int id, string name) : SmartDevice(id, name) {};

//This will return int
void Television::getChannel() {
    cout << "Getting Channel..." << endl;
}

void Television::setChannel() {
    cout << "Set Channel..." << endl;
}
