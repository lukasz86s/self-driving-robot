#include "engine_control.hpp"

EngineControl::EngineControl(const string right_a, const string right_b, const string left_a, const string left_b, const string pwmchip){
    power_pins = new PwmPins(pwmchip.c_str());
    direction_pins = new GpioPins(right_a, right_b, left_a, left_b);
    power_pins->initPin();
    direction_pins->initPin();
    //maping move cotrols pins, must be after init pins
    engine_control_pins["right_a"] = right_a;
    engine_control_pins["right_b"] = right_b;
    engine_control_pins["left_a"] = left_a;
    engine_control_pins["left_b"] = left_b;
    
    for(const auto& [key, value]: engine_control_pins){
        direction_pins->writeOutPin(value);
    }
 
}
void EngineControl::moveForward(){
    direction_pins->writePinHi(engine_control_pins["right_a"]);
    direction_pins->writePinHi(engine_control_pins["left_a"]);
}

void EngineControl::moveRight(){
    moveStop();
    direction_pins->writePinHi(engine_control_pins["left_a"]);
}

void EngineControl::moveLeft(){
    moveStop();
    direction_pins->writePinHi(engine_control_pins["right_a"]);
}

void EngineControl::moveStop(){
    for(const auto& [key, values]: engine_control_pins){
        direction_pins->writePinLow(values);
    }
    

}