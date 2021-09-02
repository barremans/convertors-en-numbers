/**
 * Based and needed on
 * TrueRandom - A true random number generator for Arduino.
 *
 * Copyright (c) 2010 Peter Knight, Tinker.it! All rights reserved.
 */

#ifndef Numbers_h
#define Numbers_h

#include "Arduino.h"
#include "TrueRandom.h"


//long ADCrandNbr;
void randomVoltage(float min, float vol);

void randomDecimal(int min, int max);

void randomByte();

void randomBit();

void randomI(int min, int digits, int max);

void printHex(byte number);

void randomUID();

void randomNbr(int first, int last);

void bitconv(int Blength, int data);

void randomSUM(int min, int max, int startnbr);

#endif
