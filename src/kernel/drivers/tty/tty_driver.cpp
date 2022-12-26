#include <cstring/cstring.h>
#include <drivers/driver.h>
#include <drivers/tty/tty_driver.h>
#include <io/io.h>
#include <string/string.h>

TtyDriver::TtyDriver()
  : Driver("tty", "A TTY driver for writing to the screen", DriverType::Tty)
{
}

void TtyDriver::initialize()
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
  // Go to the beginning of the next line when a new line character is encountered
  if (c == '\n') {
    m_cursor_x = 0;
    m_cursor_y += 2;

    moveCursor(m_cursor_x, m_cursor_y / 2);

    return;
  }

  if (c == '\t') {
    m_cursor_x += (2 * 2);
  }

  uint32_t width = VgaHelper::getVgaWidth();
  uint32_t i =
    (m_cursor_y * width) + (m_cursor_x * 2); // 1 byte for the character, 1 byte for color
  uint8_t* vidmem = (uint8_t*) VIDEO_MEMORY;

  vidmem[i] = c;
  vidmem[i + 1] = m_terminal_color;

  m_cursor_x++;

  moveCursor(m_cursor_x, m_cursor_y / 2);
}

/**
 * Writes a C string to the screen
 *
 * @param s The string to the write
 */
void TtyDriver::write(const char* s)
{
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
  for (size_t i = 0; i < str.length(); i++) {
    writeChar(str[i]);
  }
}

/**
 * Writes a C string to the screen, appending a newline at the end of the string
 *
 * @param s The string to the write
 */
void TtyDriver::writeLine(const char* s)
{
  write(s);
  writeChar('\n');
}

/**
 * Writes a new line character to the screen
 */
void TtyDriver::writeLine()
{
  writeChar('\n');
}

/**
 * Update the location of the hardware cursor
 *
 * @param x The x coordinate for the cursor
 * @param y The y coordinate for the cursor
 */
void TtyDriver::moveCursor(uint32_t x, uint32_t y)
{
  uint16_t pos = y * m_width + x;

  outb(PORT_VGA_COMMAND, 0x0F);
  outb(PORT_VGA_DATA, (uint16_t)(pos & 0xFF));
  outb(PORT_VGA_COMMAND, 0x0E);
  outb(PORT_VGA_DATA, (uint16_t)((pos >> 8) & 0xFF));
}
