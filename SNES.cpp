/*********************************************
 *  Created by Álvaro Justen aka Turicas     *
 * Contact: alvarojusten@gmail.com           *
 * License: GPLv2                            *
 *********************************************/


#include <WProgram.h>
#include "SNES.h"


void SNESClass::begin(uint8_t clockPin, uint8_t strobePin, uint8_t dataPin) {
    _clockPin = clockPin;
    _strobePin = strobePin;
    _dataPin = dataPin;
    _state = 0x00;
    
    pinMode(strobePin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    pinMode(dataPin, INPUT_PULLUP);
}


void SNESClass::update() {
    /*
       Mapping from http://www.gamesx.com/controldata/snesdat.htm
       Keys: | B Y Select Start Up Down Left Right A X  L  R N/A N/A N/A N/A |
       Bits: | 0 1   2      3    4   5    6    7   8 9 10 11  12  13  14  15 |
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
