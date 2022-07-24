#include "odroid_pins.hpp"
#include <fstream>
#include <iostream>
#include <string>
// wariadic func : #include <cstdarg>

using namespace std;
//TODO: add zed debug macroc

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
    char path[PATH_TAB_LEN+10];
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

void GpioPins::initPin(){
    char path[PATH_TAB_LEN];
    sprintf(path, "%s%s", PATH_TO_GPIO, "export");

}
//TODO: create variadic variable to initialize seweral gpios
// GpioPins::GpioPins(const T&... pins){
//     // char **gpio_tab = new(char* , len(variadic))
//     // for (char &tab : gpio_tab){ tab = variadic[0], tab = variadic[1]...
//     int vars = *(&gpioStr + 1) - gpioStr;
//     cout<< "vars :" <<vars<<endl;
//     for(int i = 0; i < vars; i++){


//     }
// }