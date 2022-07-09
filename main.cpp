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
    PwmPins* pwm = new PwmPins(); 
    pwm->initPin();
    cout << "test programu, periond " << endl;
    write_to_file("/sys/class/pwm/pwmchip0/pwm0/period", PERIOD_INIT_VAL);
    write_to_file("/sys/class/pwm/pwmchip0/pwm0/duty_cycle", DUTY_CYCLE_INIT_VAL);
     write_to_file("/sys/class/pwm/pwmchip0/pwm0/enable", 1);
    return 0;
}
