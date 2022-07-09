#ifndef ODROID_PINS_H
#define ODROID_PINS_H

#define PERIOD_INIT_VAL 1000000
#define DUTY_CYCLE_INIT_VAL 300000

class Pins{
    public:
        void writePinFile(const char* path, unsigned short value);
        void writePinFile(const char* path, const char* str_cmd);
        virtual void initPin() = 0;
};

class PwmPins: 
            public Pins{
                public:
                    void initPin();
            };

#endif