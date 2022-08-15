# I2C-shift-registers

## Note: current development - build may be unstable / not working

## #define

### _#define_ __dir__ 0bdddddddd

 - __0__ INPUT
 - __1__ OUTPUT
 - default __0b11110000__

### _#define_ __addr__ 0xaddr
 - I2C Address
 - default __0x8__


## Pin Mapping

    PORTC
        0: NC
        1: NC
        2: NC
        3: NC
        4: SDA
        5: SCL
        6: /RESET

    PORTD
        0: 0b00000001 (1 << 0)
        1: 0b00000010 (1 << 1)
        2: 0b00000100 (1 << 2)
        3: 0b00001000 (1 << 3)
        4: 0b00010000 (1 << 4)
        5: 0b00100000 (1 << 5)
        6: 0b01000000 (1 << 6)
        7: 0b10000000 (1 << 7)

    PORTB
        0: CLK
        1: STORE + /LOAD
        2: Interrupt
        3: MOSI (ISCP)
        4: MISO (ISCP)
        5: SCK (ISCP)
        6: XTAL1
        7: XTAL2
