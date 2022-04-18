#ifndef LOGGING_H
#define LGGING_H

#ifndef LOGGING_H
#define LOGGING_H

#define VIDEO_MEMORY 0xB8000;

#include <helpers/vga_helper.h>
#include <string/string.h>

class Logger
{
public:
  Logger();

  void setColor(enum VgaColor fg, enum VgaColor bg);

  void clearScreen();
  static void log(const char* s);

private:
  static void writeChar(const char c);

  static uint32_t m_width;
  static uint32_t m_height;
  static uint32_t m_cursor_x;
  static uint32_t m_cursor_y;
  static uint32_t m_color;
};

#endif

#endif
