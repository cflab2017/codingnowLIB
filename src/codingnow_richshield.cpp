#include "codingnow_richshield.h"
#include "RichShield/RichShieldIRremote.h"
#include "RichShield/RichShieldTM1637.h"
#include <Wire.h>

TM1637 disp(CLK,DIO);
IRrecv IR(RECV_PIN);

int ir_save = 0;


void init_RichShiled_cg(void)
{
  disp.init();
  IR.enableIRIn();
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
