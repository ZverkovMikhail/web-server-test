#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>
#include "Display.h"


Display::Display() : u8g2(U8G2_R0, /* reset=*/U8X8_PIN_NONE, /* clock=*/22, /* data=*/21){
}

void Display::init(){
    clear();
    u8g2.begin();
    delay(50);
}
void Display::clear(){
  this->_line1 = "";
  this->_line2 = "";
  this->_line3 = "";
  this->_line4 = "";
}
  Display* Display::setLine(Line line, const char *s){
    switch (line)
    {
    case FIRST:
      /* code */
      this->_line1 = s;
    case SECOND:
      this->_line2 = s;
      break;
    case THIRD:
      this->_line3 = s;
      break;
    case FOURTH:
      this->_line4 = s;
      break;
    
    default:
      break;
    }
    return this;
  }

  void Display::print(){
    u8g2.setColorIndex(draw_color);
    u8g2.setFont(u8g2_font_8x13B_tf);
    u8g2.firstPage();  
    do {
      u8g2.drawStr(0,14, this->_line1);
      u8g2.drawStr(0,30, this->_line2);
      u8g2.drawStr(0,46, this->_line3);
      u8g2.drawStr(0,60, this->_line4);
    } while( u8g2.nextPage());
  }

  Display DisPlay;