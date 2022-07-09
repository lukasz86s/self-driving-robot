#include "odroid_pins.hpp"
#include <fstream>
#include <iostream>

using namespace std;

void Pins::writePinFile(const char* path, unsigned short value){
    ofstream pin_file(path);
    pin_file << value << endl;
}

void Pins::writePinFile(const char* path, const char* str_cmd){
    ofstream pin_file(path);
    pin_file << str_cmd << endl;

}

void PwmPins::initPin(){
    cout << "implementacj init" << endl;
}