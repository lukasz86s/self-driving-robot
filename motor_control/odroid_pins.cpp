#include "odroid_pins.hpp"
#include <fstream>
#include <iostream>
#include <string>
// wariadic func : #include <cstdarg>

using namespace std;
//TODO: add zed debug macroc

//TODO: capture error from ofstream 
void Pins::writePinFile(const char* path, unsigned int value){
    ofstream pinFile(path);
    if(pinFile.good()){
        pinFile << value << endl;
        pinFile.close();
        return;    
    }
    cout<< "cannot read file"<< path << endl;
    pinFile.close();
    
}

void Pins::writePinFile(const char* path, const char* str_cmd){
    ofstream pinFile(path);
    if(pinFile.good()){
        pinFile << str_cmd << endl;
        pinFile.close();
        return;
    }
     cout<< "cannot read file"<< path << endl;
     pinFile.close();

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
}

void GpioPins::initPin(){
    const string export_ = "export";
    string tempPath = PATH_TO_GPIO + export_;
    cout << "gpio init "<< tempPath<< endl;
    for(const auto& [key, value]: gpios_enabled_list){
        writePinFile(tempPath.c_str(), value);    //enable correct pin
        cout<<value<<endl;
    }


}
// TODO: create init gpio pins () and hi low function. next move class with  go forward backward left right