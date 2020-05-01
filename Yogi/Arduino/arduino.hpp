
#ifndef HPP_ARDUINO
#define HPP_ARDUINO

#include "CSerial.hpp"

#include <iostream>
#include <stdint.h>
#include <unistd.h>

#define INPUT  0x00
#define OUTOUT 0x01

#define LOW  0x00
#define HIGH 0x01

typedef uint8_t byte;

extern Yogi::Arduino::CSerial Serial;

// primary Arduino entry points
void
setup();

void
loop();

void
delay( unsigned long milli );

void
delayMicroseconds( unsigned long micro );

unsigned long
millis();

unsigned long
micros();


void
pinMode( uint8_t pin, uint8_t mode );


void
digitalWrite( uint8_t pin, int val );

void
analogWrite( uint8_t pin, int val );

unsigned long
pulseIn( uint8_t pin, uint8_t state, unsigned long timeout = 1000000UL );

#endif    // HPP_ARDUINO
