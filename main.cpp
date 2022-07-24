#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "motor_control/odroid_pins.hpp"

using namespace std;

void write_to_file(const char* path, int value){
    ofstream my_file(path);
    my_file << value << endl;
}

int main(int argv, char* args[]){
    PwmPins* pwm0 = new PwmPins(); 
    PwmPins* pwm1 = new PwmPins("pwmchip1");
    pwm0->initPin();
    pwm1->initPin();
    cout << "test programu, periond " << endl;
    
    GpioPins* a   = new GpioPins("raz", "dwa", "trzy");

    return 0;
}
