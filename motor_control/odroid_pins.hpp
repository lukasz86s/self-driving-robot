#ifndef ODROID_PINS_H
#define ODROID_PINS_H

#include <map>
#include <iostream>
#include <array>

#define PERIOD_INIT_VAL 1000000U
#define DUTY_CYCLE_INIT_VAL 300000U

#define PATH_TAB_LEN 50

#define PATH_TO_PWM "/sys/class/pwm/"
#define PATH_TO_GPIO "/sys/class/gpio/"

#define SETTINGS_PWM_TAB_LEN 3
#define SETTINGS_GPIO_TAB_LEN 2

using namespace std;


class Pins{
    public:
        void writePinFile(const char* path, unsigned int value);
        void writePinFile(const char* path, const char* str_cmd);
        virtual void initPin() = 0;
};

class PwmPins: 
            public Pins{
                private:
                    char path_to_pwmchip[PATH_TAB_LEN];
                    const char* initial_settings[SETTINGS_PWM_TAB_LEN] = {"period", "duty_cycle", "enable"};
                    unsigned int initial_settings_values[SETTINGS_PWM_TAB_LEN] = {PERIOD_INIT_VAL, DUTY_CYCLE_INIT_VAL, 1};
                    enum{SETTINGS_PERIOD, SETTINGS_DUTY_CYCLE, SETTINGS_ENABLE};

                public:
                    void initPin();
                    PwmPins();
                    PwmPins(const char* pwmchip );
                //TODO: create function set power 
                    
            };

class GpioPins:
            public Pins{
                private:
                    // Mapping odroid M1 GPIOyx.z to connected number
                    // TODO: mayb change to enum
                    map<string, uint32_t> gpio_name_to_nr = {{"gpio0B3", 11 }, {"gpio0B4", 12 }, {"gpio0B5", 13 }, {"gpio0B6", 14 },
                                                    {"gpio3B2", 106}, {"gpio3B5", 109}, {"gpio3B6", 110}, {"gpio4B6", 142},
                                                    {"gpio0C0", 16 }, {"gpio0C1", 17 }, {"gpio3C6", 118}, {"gpio3C7", 119},
                                                    {"gpio4C1", 145},
                                                    {"gpio2D0", 88 }, {"gpio2D1", 89 }, {"gpio2D2", 90 }, {"gpio2D3", 91 },
                                                    {"gpio3D0", 120}, {"gpio3D1", 121}, {"gpio3D2", 122}, {"gpio3D3", 123},
                                                    {"gpio3D1", 124}, {"gpio3D5", 125}, {"gpio3D6", 126}, {"gpio3D7", 127} 
                                                     };
                    map<string, string> path_to_gpios;
                    unsigned int nr_of_pins ;
                    map<string, uint32_t> gpios_enabled_list;
                    char path_to_gpio[PATH_TAB_LEN];
                    const char* gpios_settings[SETTINGS_GPIO_TAB_LEN] = {"direction", "value"};
                    enum{SETTINGS_DIRECTION, SETTINGS_VALUE };
                    
                public:
                    void initPin();
                    template<typename... T>
                        GpioPins(const T&... pins){
                            nr_of_pins = sizeof...(pins);
                            string temp_path;
                            const string gpiochip = "gpio";
                            
                            for(string n: {pins...}){
                                gpios_enabled_list[n] = gpio_name_to_nr[n]; // save used pins in list
                                path_to_gpios[n] = PATH_TO_GPIO + gpiochip + to_string(gpio_name_to_nr[n]);// converts added pins to path

                            }
                            
                        };
                        // TODO: move to cpp create macro for path 
                    void writeOutPin(const string pin_name){ string gpio = "gpio"; string path = PATH_TO_GPIO + gpio + to_string(gpio_name_to_nr[pin_name]) + "/direction"; writePinFile(path.c_str(), "out");cout << path <<endl;}
                    void writePinHi(const string pin_name){ string gpio = "gpio"; string path = PATH_TO_GPIO + gpio + to_string(gpio_name_to_nr[pin_name]) + "/value"; writePinFile(path.c_str(), 1U);}
                    void writePinLow(const string pin_name){ string gpio = "gpio"; string path = PATH_TO_GPIO + gpio + to_string(gpio_name_to_nr[pin_name]) + "/value"; writePinFile(path.c_str(), 0U);}
                    


            };

#endif