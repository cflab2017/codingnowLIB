#include "codingnow_richshield.h"
#include "RichShield/RichShieldIRremote.h"
#include "RichShield/RichShieldTM1637.h"
#include <Wire.h>

/*
buzzer 사용시에
RichShieldIRremoteInt.h의 line 66 수정 : buzzer timer와 겹침.
//#define IR_USE_TIMER1   // tx = pin 9
#define IR_USE_TIMER2     // tx = pin 3
#define PIN_PIEZO 3
*/

TM1637 disp(CLK,DIO);
IRrecv IR(RECV_PIN);

int ir_save = 0;

#define PIN_PIEZO 3

#define PIN_LED_RED     4
#define PIN_LED_GREEN   5
#define PIN_LED_BLUE    6
#define PIN_LED_YELLOW  7

#define PIN_BUTTON_0    8
#define PIN_BUTTON_1    9

void init_RichShiled_cg(void)
{

  disp.init();
  IR.enableIRIn();

  pinMode(PIN_LED_RED, OUTPUT);
  pinMode(PIN_LED_GREEN, OUTPUT);
  pinMode(PIN_LED_BLUE, OUTPUT);
  pinMode(PIN_LED_YELLOW, OUTPUT);

  pinMode(PIN_BUTTON_0, INPUT_PULLUP);
  pinMode(PIN_BUTTON_1, INPUT_PULLUP);

  pinMode(PIN_PIEZO, OUTPUT);
}

unsigned char btn_port[] = {PIN_BUTTON_0,PIN_BUTTON_1};
unsigned char btn_state[] = {0,0};
long btn_pressed_time[] = {0,0};

unsigned char get_read_button(unsigned char idex, unsigned char force, unsigned int press_time)
{

  if(idex > 1) return 0;

  unsigned char btn_r = digitalRead(btn_port[idex]);
  if(btn_r==0)
  {
    if(btn_state[idex]==0 || force)
    {
      btn_state[idex] = 1;
      btn_pressed_time[idex] = millis();
      return 1;
    }else{
      if(millis() - btn_pressed_time[idex] > press_time)
      {
        btn_state[idex] = 0;
      }
    }
  }else{
    btn_state[idex] = 0;
  }

  return 0;
}


int get_ir_data(void)
{
  ir_save = 0;
  if (IR.decode()) 
  {
    if(IR.isReleased())
    {
      disp.display(IR.keycode);
      ir_save = IR.keycode; 
    }
    IR.resume();
  }
  return ir_save;
}
