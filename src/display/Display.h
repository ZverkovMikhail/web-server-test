#ifndef Display_h
#define Display_h
#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>


typedef u8g2_uint_t u8g_uint_t;

class Display{
  public:
  enum Line{FIRST=1, SECOND=2, THIRD=3, FOURTH=4};
  Display();
  void init();
  void clear();
  Display* setLine(Line line, const char *s);
  void print();
  protected:
  U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2;
  const char* _line1;
  const char* _line2;
  const char* _line3;
  const char* _line4;
  #define SECONDS 10
  uint8_t flip_color = 0;
  uint8_t draw_color = 1;
};

extern Display DisPlay;

#endif