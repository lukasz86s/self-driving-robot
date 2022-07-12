#ifndef ODROID_PINS_H
#define ODROID_PINS_H

#define PERIOD_INIT_VAL 1000000U
#define DUTY_CYCLE_INIT_VAL 300000U

#define PATH_TO_PWM_TAB_LEN 50
#define PATH_TO_GPIO_TAB_LEN 50

#define PATH_TO_PWM "/sys/class/pwm/"
#define PATH_TO_GPIO "/sys/class/gpio"

#define SETTINGS_PWM_TAB_LEN 3
#define SETTINGS_GPIO_TAB_LEN 2




class Pins{
    public:
        void writePinFile(const char* path, unsigned int value);
        void writePinFile(const char* path, const char* str_cmd);
        virtual void initPin() = 0;
};

class PwmPins: 
            public Pins{
                private:
                    char path_to_pwmchip[PATH_TO_PWM_TAB_LEN];
                    const char* initial_settings[SETTINGS_PWM_TAB_LEN] = {"period", "duty_cycle", "enable"};
                    unsigned int initial_settings_values[SETTINGS_PWM_TAB_LEN] = {PERIOD_INIT_VAL, DUTY_CYCLE_INIT_VAL, 1};
                    enum{SETTINGS_PERIOD, SETTINGS_DUTY_CYCLE, SETTINGS_ENABLE};

                public:
                    void initPin();
                    PwmPins();
                    PwmPins(const char* pwmchip );
                    
                    
            };

class GpioPins:
            public Pins{
                private:
                    char path_to_gpio[PATH_TO_GPIO_TAB_LEN];
                    const char* inita_settings[SETTINGS_GPIO_TAB_LEN] = {"direction", "value"};
                    enum{SETTINGS_DIRECTION, SETTINGS_VALUE };
                    
                public:
                    void initPin();
                    GpioPins(const char* gpioStr);
                    


            };

#endif