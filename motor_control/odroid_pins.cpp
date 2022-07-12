#include "odroid_pins.hpp"
#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;

//TODO: capture error from ofstream 
void Pins::writePinFile(const char* path, unsigned int value){
    ofstream pin_file(path);
    if(pin_file.good()){
        pin_file << value << endl;
        return;    
    }
    cout<< "cannot read file"<< endl;
    
}

void Pins::writePinFile(const char* path, const char* str_cmd){
    ofstream pin_file(path);
    if(pin_file.good()){
        pin_file << str_cmd << endl;
        return;
    }
     cout<< "cannot read file"<< endl;

}

void PwmPins::initPin(){
    char path[PATH_TO_PWM_TAB_LEN+10];
    cout << "implementacj init" << endl;
    //copy path to enable
    sprintf(path,"%s%s", path_to_pwmchip, "export");
    //enable pin 
    writePinFile(path, 0U);
    for(int i = 0; i < SETTINGS_PWM_TAB_LEN; i++){
            sprintf(path, "%s%s%s", path_to_pwmchip, "pwm0/", initial_settings[i]);
            writePinFile(path, initial_settings_values[i]);
            cout<< path << endl;
            
    }
        
}

PwmPins::PwmPins(){
    sprintf(path_to_pwmchip,"%s%s",PATH_TO_PWM, "pwmchip0/");
}

PwmPins::PwmPins(const char* pwmchip ){
    sprintf(path_to_pwmchip,"%s%s%c",PATH_TO_PWM, pwmchip, '/');
    cout<< path_to_pwmchip << endl;

}