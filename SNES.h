#ifndef SNES_h
#define SNES_h

#include <inttypes.h>

class SNESClass {
    private:
        uint8_t _clockPin, _strobePin, _dataPin;
        uint16_t _state;
    public:
        void begin(uint8_t, uint8_t, uint8_t);
        void update();
        uint16_t getState();
};

extern SNESClass SNES;

#endif
