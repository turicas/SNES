/*
   Created by Álvaro Justen aka Turicas
   Contact: alvarojusten@gmail.com
   License: GPLv2
*/

#include <WProgram.h>
#include "SNES.h"


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

void SNESClass::begin(uint8_t clockPin, uint8_t strobePin, uint8_t dataPin) {
    _clockPin = clockPin;
    _strobePin = strobePin;
    _dataPin = dataPin;
    _state = 0x00;
}


void SNESClass::update() {
    /*
       Mapping from http://www.gamesx.com/controldata/snesdat.htm
       | B | Y | Select | Start | Up | Down | Left | Right | A | X | L | R | N/A | N/A | N/A | N/A |
       */
    unsigned int fromController = 0x00;
    uint8_t i;

    //Do the strobe to start reading button values
    digitalWrite(_strobePin, HIGH);
    delayMicroseconds(12);
    digitalWrite(_strobePin, LOW);

    //Wait for controller to start sending the button values 
    delayMicroseconds(6);
    for (i = 0; i < 16; i++) {
        //read the value, shift it and store it as a bit on fromController:
        fromController |= digitalRead(_dataPin) << i;

        //More one cycle on the clock pin...
        digitalWrite(_clockPin, HIGH);
        delayMicroseconds(6);
        digitalWrite(_clockPin, LOW);
        delayMicroseconds(6);
    }

    //return the read bits (16)
    _state = ~fromController;
}


uint16_t SNESClass::getState() {
    return _state;
}

SNESClass SNES;
