
#include "codingnow_neopixel_ex.h"

/*-----------------------------------------------------------*/
#define RGB_ARR_MAX 8
unsigned char rgb_arr_heart[RGB_ARR_MAX] = {
B00000000,
B01100110,
B10011001,
B10000001,
B10000001,
B01000010,
B00100100,
B00011000,
};
unsigned char rgb_arr_side[RGB_ARR_MAX] = {
B11111111,
B10000001,
B10000001,
B10000001,
B10000001,
B10000001,
B10000001,
B11111111,
};
unsigned char rgb_arr_x[RGB_ARR_MAX] = {
B10000001,
B01000010,
B00100100,
B00011000,
B00011000,
B00100100,
B01000010,
B10000001,
};
unsigned char rgb_arr_o[RGB_ARR_MAX] = {
B00011000,
B00100100,
B01000010,
B10000001,
B10000001,
B01000010,
B00100100,
B00011000,
};

unsigned char rgb_arr_0[RGB_ARR_MAX] = {
B00000000,
B00000000,
B00111100,
B00100100,
B00100100,
B00100100,
B00111100,
B00000000,
};
unsigned char rgb_arr_1[RGB_ARR_MAX] = {
B00000000,
B00000000,
B00001000,
B00011000,
B00001000,
B00001000,
B00011100,
B00000000,
};

unsigned char rgb_arr_2[RGB_ARR_MAX] = {
B00000000,
B00000000,
B00111100,
B00000100,
B00111100,
B00100000,
B00111100,
B00000000,
};
unsigned char rgb_arr_3[RGB_ARR_MAX] = {
B00000000,
B00000000,
B00111100,
B00000100,
B00111100,
B00000100,
B00111100,
B00000000,
};
unsigned char rgb_arr_4[RGB_ARR_MAX] = {
B00000000,
B00000000,
B00101000,
B00101000,
B00111100,
B00001000,
B00001000,
B00000000,
};
unsigned char rgb_arr_5[RGB_ARR_MAX] = {
B00000000,
B00000000,
B00111100,
B00100000,
B00111100,
B00000100,
B00111100,
B00000000,
};
unsigned char rgb_arr_6[RGB_ARR_MAX] = {
B00000000,
B00000000,
B00111100,
B00100000,
B00111100,
B00100100,
B00111100,
B00000000,
};
unsigned char rgb_arr_7[RGB_ARR_MAX] = {
B00000000,
B00000000,
B00111100,
B00100100,
B00000100,
B00000100,
B00000100,
B00000000,
};
unsigned char rgb_arr_8[RGB_ARR_MAX] = {
B00000000,
B00000000,
B00111100,
B00100100,
B00111100,
B00100100,
B00111100,
B00000000,
};
unsigned char rgb_arr_9[RGB_ARR_MAX] = {
B00000000,
B00000000,
B00111100,
B00100100,
B00111100,
B00000100,
B00000100,
B00000000,
};

#define RGB_LED_MAX_HEART_01 18
char rgb_arry_heart01[RGB_LED_MAX_HEART_01] = {
9,10,13,14,16,19,20,23,24,31,
32,39,41,46,50,53,59,60,
};

#define RGB_LED_MAX_HEART_02 14
char rgb_arry__heart02[RGB_LED_MAX_HEART_02] = {
17,18,21,22,25,27,28,30,33,38,
42,45,51,52,
};
#define RGB_LED_MAX_HEART_03 8
char rgb_arry__heart03[RGB_LED_MAX_HEART_03] = {
26,29,34,35,36,37,43,44,
};


#define RGB_LED_MAX_MAN_01 17
char rgb_arry_man01[RGB_LED_MAX_MAN_01] = {
3,10,12,19,24,25,26,27,28,29,30,
35,43,50,52,57,61,
};

#define RGB_LED_MAX_MAN_02 17
char rgb_arry_man02[RGB_LED_MAX_MAN_02] = {
3,8,10,12,14,17,19,21,26,27,28,
35,43,50,52,57,61,
};

#define RGB_LED_MAX_MAN_03 17
char rgb_arry_man03[RGB_LED_MAX_MAN_03] = {
3,10,12,19,26,27,28,33,35,37,
40,43,46,50,52,57,61,
};

void draw_arry(unsigned char idex,unsigned char r, unsigned char g, unsigned char b)
{
    unsigned char* buff;
    switch(idex)
    {
        default:
        case 0:{buff = rgb_arr_0;break;}
        case 1:{buff = rgb_arr_1;break;}
        case 2:{buff = rgb_arr_2;break;}
        case 3:{buff = rgb_arr_3;break;}
        case 4:{buff = rgb_arr_4;break;}
        case 5:{buff = rgb_arr_5;break;}
        case 6:{buff = rgb_arr_6;break;}
        case 7:{buff = rgb_arr_7;break;}
        case 8:{buff = rgb_arr_8;break;}
        case 9:{buff = rgb_arr_9;break;}

        case 10:{buff = rgb_arr_side;break;}
        case 11:{buff = rgb_arr_x;break;}
        case 12:{buff = rgb_arr_o;break;}
        case 13:{buff = rgb_arr_heart;break;}
    }
    rgb_clear();
    for(int i=0; i<RGB_ARR_MAX; i++)
    {
        for(int k=7; k>-1; k--)
        {
            if(buff[i]&(0x01<<k)){
                rgb_set((i*8)+(7-k),   color(r, g,b), 0);
            }
        }      
    }
    rgb_show();
}

/*-----------------------------------------------------------*/
#define RGB_LED_SIDE_MAX 28

char rgb_arry_side[RGB_LED_SIDE_MAX] = {
0,1,2,3,4,5,6,7,
15,23,31,39,47,55,
63,62,61,60,59,58,57,56,
48,40,32,24,16,8,
};
void ex_cycle_off(void)
{   
    for(int i=0; i< RGB_LED_SIDE_MAX;i++)
    {
      rgb_set(rgb_arry_side[i],   color(0,  0,  0));
      delay(100);
    }  
}
void ex_cycle_on(void)
{
    rgb_off();
    for(int i=0; i< RGB_LED_SIDE_MAX;i++)
    {
      rgb_set(rgb_arry_side[i],   color(0,  150,  150));
      delay(100);
    }    
}

/*-----------------------------------------------------------*/