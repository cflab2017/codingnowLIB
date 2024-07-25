

#ifndef _codingnow_neopixel_h
#define _codingnow_neopixel_h

#include <Arduino.h>

// char rgb_arry[RGB_LED_MAX] = {
// 0,1,2,3,4,5,6,7,
// (8+(8*0)+7),
// (8+(8*1)+7),
// (8+(8*2)+7),
// (8+(8*3)+7),
// (8+(8*4)+7),
// (8+(8*5)+7),
// 63,62,61,60,59,58,57,56,
// (8+(8*5)+0),
// (8+(8*4)+0),
// (8+(8*3)+0),
// (8+(8*2)+0),
// (8+(8*1)+0),
// (8+(8*0)+0),
// };

// char rgb_arry[RGB_LED_MAX] = {
// 0,1,2,3,4,5,6,7,
// 15,23,31,39,47,55,
// 63,62,61,60,59,58,57,56,
// 48,40,32,24,16,8,
// };

#define NEO_PIN     A1
#define NUMPIXELS   8

void init_nenopixel_cg(unsigned char pin, unsigned char num,unsigned char brightness);
void rgb_off(void);
void rgb_set(int idex, unsigned char *rgb, unsigned char isShow=1);
unsigned char* color(unsigned char r, unsigned char g, unsigned char b);
void ex_cycle(void);
void rgb_clear();
void rgb_show();
#endif