#ifndef SNES_h
#define SNES_h


#include <inttypes.h>


#define SNES_B       0b0000000000000001
#define SNES_Y       0b0000000000000010
#define SNES_SELECT  0b0000000000000100
#define SNES_START   0b0000000000001000
#define SNES_UP      0b0000000000010000
#define SNES_DOWN    0b0000000000100000
#define SNES_LEFT    0b0000000001000000
#define SNES_RIGHT   0b0000000010000000
#define SNES_A       0b0000000100000000
#define SNES_X       0b0000001000000000
#define SNES_L       0b0000010000000000
#define SNES_R       0b0000100000000000


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
