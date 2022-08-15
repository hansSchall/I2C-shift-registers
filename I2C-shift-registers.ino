
// arduino_shift_I2C.ino
// Version 1.1

#include <Arduino.h>
#include <Wire.h>

#ifndef cbi
#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#endif

#ifndef sbi
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))
#endif

#define dir 0b11110000
#define addr 0x8

uint8_t states[64];
bool changed[8] = { true };

void setup() {
    DDRD = dir;
    PORTD = 0;
    // control pins
    DDRB |= 0b00000111;

    Wire.begin(addr);
    Wire.onRequest(requestHandler);
    Wire.onReceive(receiveHandler);
}

void loop() {

    uint8_t addrBB = 0;
    // [STORE + /LOAD] = 1
    PORTB |= 0b10;
    while (addrBB < 64) {
        uint8_t oldValue = states[addrBB];
        // write all outputs
        PORTD = oldValue & dir;
        // save the new input states and keep the old output stated
        states[addrBB] = (PIND & ~dir) | (oldValue & dir);
        // CLK pulse
        PORTB |= 1;
        PORTB &= ~1;
        if (states[addrBB] != oldValue) {
            // Input changed
            changed[addrBB] = true;
            PORTB |= 0b00000100;
        }
        addrBB++;
    }
    // [STORE + /LOAD] = 0
    PORTB &= ~0b10;
}

void requestHandler() {

}

void receiveHandler(int l) {

}
