#include <cstring/cstring.h>
#include <drivers/driver.h>
#include <drivers/tty/tty_driver.h>
#include <string/string.h>

TtyDriver::TtyDriver()
  : Driver("tty", "A TTY driver for writing to the screen", DriverType::Tty)
{
  m_width = VgaHelper::getVgaWidth();
  m_height = VgaHelper::getVgaHeight();
  m_terminal_color = VgaHelper::makeColor(VgaColor::LightGray, VgaColor::Black);
  m_cursor_x = 0;
  m_cursor_y = 0;
}

uint32_t TtyDriver::getTerminalColor()
{
  return m_terminal_color;
}

void TtyDriver::setTerminalColor(VgaColor text_color, VgaColor background_color)
{
  m_terminal_color = VgaHelper::makeColor(text_color, background_color);
}

/**
 * Writes a character to the screen
 *
 * @param c The character to write
 */
void TtyDriver::writeChar(const char c)
{
  // The driver needs to be installed before text can be written to the screen
  // TODO: log out that the driver has not been installed
  if (!isInstalled()) {
    return;
  }

  uint32_t width = VgaHelper::getVgaWidth();
  uint32_t i = m_cursor_y * width + m_cursor_x;
  uint8_t* vidmem = (uint8_t*) VIDEO_MEMORY;

  vidmem[i++] = c;
  m_cursor_x++;

  vidmem[i++] = m_terminal_color;
  m_cursor_x++;

  if (m_cursor_x > width) {
    m_cursor_x = 0;
    m_cursor_y += 2;
  }
}

/**
 * Writes a C string to the screen
 *
 * @param s The string to the write
 */
void TtyDriver::write(const char* s)
{
  // The driver needs to be installed before text can be written to the screen
  if (!isInstalled()) {
    return;
  }

  for (size_t i = 0; i < strlen(s); i++) {
    writeChar(s[i]);
  }
}

/**
 * Writes a C++ string to the screen
 *
 * @param s The string to write
 */
void TtyDriver::write(const std::string& str)
{
  // The driver needs to be installed before text can be written to the screen
  if (!isInstalled()) {
    return;
  }

  for (size_t i = 0; i < str.length(); i++) {
    writeChar(str[i]);
  }
}
