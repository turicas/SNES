#include <SNES.h>

void setup() {
    Serial.begin(9600);
    SNES.begin(3, 4, 5);
}

void loop() {
    int state;
    SNES.update();
    state = SNES.getState();

    Serial.print("A = ");
    Serial.print(state & SNES_A);
    Serial.print(" B = ");
    Serial.print(state & SNES_B);
    Serial.print(" X = ");
    Serial.print(state & SNES_X);
    Serial.print(" Y = ");
    Serial.println(state & SNES_Y);

    Serial.print(" L = ");
    Serial.print(state & SNES_L);
    Serial.print(" R = ");
    Serial.print(state & SNES_R);
    Serial.print(" Select = ");
    Serial.print(state & SNES_SELECT);
    Serial.print(" Start = ");
    Serial.println(state & SNES_START);

    Serial.print(" Up = ");
    Serial.print(state & SNES_UP);
    Serial.print(" Down = ");
    Serial.print(state & SNES_DOWN);
    Serial.print(" Left = ");
    Serial.print(state & SNES_LEFT);
    Serial.print(" Right = ");
    Serial.println(state & SNES_RIGHT);

    Serial.println();
    delay(100);
}
