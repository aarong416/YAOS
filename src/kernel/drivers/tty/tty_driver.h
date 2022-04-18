#ifndef TTY_DRIVER_H
#define TTY_DRIVER_H

#define VIDEO_MEMORY 0xB8000;

#include <drivers/driver.h>
#include <helpers/vga_helper.h>
#include <string/string.h>

class TtyDriver : public Driver
{
  public:
  TtyDriver();

  uint32_t getTerminalColor();
  void setTerminalColor(VgaColor text_color, VgaColor background_color);

  void clearScreen();
  void writeChar(const char c);
  void write(const char* s);
  void write(const std::string& s);

  private:
  uint32_t m_width;
  uint32_t m_height;
  uint32_t m_cursor_x;
  uint32_t m_cursor_y;
  uint32_t m_terminal_color;
};

#endif
