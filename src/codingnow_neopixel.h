

#ifndef _codingnow_neopixel_h
#define _codingnow_neopixel_h

#include <Arduino.h>


#define NEO_PIN     A1
#define NUMPIXELS   8

void init_nenopixel_cg(unsigned char pin, unsigned char num,unsigned char brightness);
void rgb_off(void);
void rgb_set(int idex, unsigned char *rgb);
unsigned char* color(unsigned char r, unsigned char g, unsigned char b);

#endif