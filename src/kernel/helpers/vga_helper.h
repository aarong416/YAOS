#ifndef _VGA_HELPER_H
#define _VGA_HELPER_H

#include <cstdint.h>

enum VgaColor {
  Black = 0,
  Blue = 1,
  Green = 2,
  Cyan = 3,
  Red = 4,
  Magenta = 5,
  Brown = 6,
  LightGray = 7,
  DarkGray = 8,
  LightBlue = 9,
  LightGreen = 10,
  LightCyan = 11,
  LightRed = 12,
  LightMagenta = 13,
  LightBrown = 14,
  White = 15,
};

class VgaHelper
{
public:
  static uint32_t getVgaWidth();
  static uint32_t getVgaHeight();
  static uint8_t makeColor(VgaColor text_color, VgaColor background_color);
};

#endif
