#include <cstring/cstring.h>

#include <drivers/tty_driver.h>

/**
 * Constructors
 */
std::String::String()
: m_length(0)
{}

std::String::String(const char* s)
{
  TtyDriver driver;

  if (!s) {
    m_string = new char[0];
    m_length = 0;
  } else {
    m_length = strlen(s);
    m_string = new char[m_length + 1];
    std::strncpy(m_string, s, strlen(s));

    m_string[m_length] = '\0';

    driver.WriteChar(m_string[0]);
  }
}

/**
 * Methods
 */

size_t std::String::length()
{
  return m_length;
} 

size_t std::String::size()
{
  return m_length;
}

char& std::String::at(size_t pos)
{
  return m_string[pos];
}

/**
 * Operator overloads
 */
char& std::String::operator[](size_t pos)
{
  TtyDriver driver;

  return at(pos);
}

/**
 * Destructor
 */
std::String::~String()
{
  delete m_string;
}
