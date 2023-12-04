#include "../include/Vacuum.h"
#include <iostream>

using namespace std;

Vacuum::Vacuum(){};

//This will return bool
void Vacuum::getBinIsFull() {
    cout << "Bin is Full..." << endl;
}

void Vacuum::setBinIsFull() {
    cout << "Setting Bin to Full..." << endl;
}
