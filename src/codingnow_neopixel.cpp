#include "codingnow_neopixel.h"
#include "NeoPixel/NeoPixel.h"


Adafruit_NeoPixel pixels(NUMPIXELS, NEO_PIN, NEO_GRB + NEO_KHZ800);


void init_nenopixel_cg(unsigned char pin, unsigned char num,unsigned char brightness)
{

  pixels.begin();
  pixels.setPin(pin);
  pixels.updateLength(num);
  pixels.updateType(NEO_GRB + NEO_KHZ800);

  pixels.setBrightness(brightness);
  pixels.clear();
  pixels.show();
}

void rgb_off(void)
{
  pixels.clear();
  pixels.show();
}

unsigned char* color(unsigned char r, unsigned char g, unsigned char b)
{
  static unsigned char ret_color[3];
  ret_color[0] = r;
  ret_color[1] = g;
  ret_color[2] = b;
  return ret_color;
}


void rgb_set(int idex, unsigned char *rgb)
{
  pixels.setPixelColor(idex, pixels.Color(rgb[0], rgb[1], rgb[2]));
  pixels.show();
}
