#include <cstring/cstring.h>
#include <logging/logger.h>
#include <string/string.h>

uint32_t Logger::m_width = VgaHelper::getVgaWidth();
uint32_t Logger::m_height = VgaHelper::getVgaHeight();
uint32_t Logger::m_color = VgaHelper::makeColor(VgaColor::LightGray, VgaColor::Black);
uint32_t Logger::m_cursor_x = 0;
uint32_t Logger::m_cursor_y = 0;

void Logger::setColor(VgaColor text_color, VgaColor background_color)
{
  m_color = VgaHelper::makeColor(text_color, background_color);
}

/**
 * Writes a character to the screen
 *
 * @param c The character to write
 */
void Logger::writeChar(const char c)
{
  uint32_t width = VgaHelper::getVgaWidth();
  uint32_t i = m_cursor_y * width + m_cursor_x;
  uint8_t* vidmem = (uint8_t*) VIDEO_MEMORY;

  vidmem[i++] = c;
  m_cursor_x++;

  vidmem[i++] = m_color;
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
void Logger::log(const char* s)
{
  for (size_t i = 0; i < strlen(s); i++) {
    writeChar(s[i]);
  }
}
