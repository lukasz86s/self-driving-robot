#ifndef ENGINE_CONTROL_H_
#define ENGINE_CONTROL_H_

#include "odroid_pins.hpp"
#include <cstdlib>
#include <iostream>
#include <map>

class EngineControl{
    private:
        GpioPins* direction_pins = 0;
        PwmPins* power_pins = 0;
        map<string, string> engine_control_pins;
    public:
        EngineControl(const string right_a, const string right_b, const string left_a, const string left_b, const string pwmchip);
        void move_forward_test();
        void move_stop();

};
#endif