

#ifndef codingnow_richshield_h
#define codingnow_richshield_h

#include <Arduino.h>

#define CLK 10
#define DIO 11


#define RECV_PIN 2


void init_RichShiled_cg(void);
int get_ir_data(void);
unsigned char get_read_button(unsigned char idex, unsigned char force =0, unsigned int press_time = 100);
#endif