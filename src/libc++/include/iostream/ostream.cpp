#include <cmath/cmath.h>
#include <cstddef.h>
#include <cstring/cstring.h>
#include <drivers/driver_manager.h>
#include <drivers/tty/tty_driver.h>
#include <string/string.h>

#include "ostream.h"
#include <iostream/ostream.h>

std::ostream::ostream(const char* path)
  : m_path(path)
{
}

std::ostream& std::ostream::write(const char* s)
{
  TtyDriver* tty = (TtyDriver*) DriverManager::getDriver("tty");

  tty->write(s);

  return *this;
}

std::ostream& std::ostream::operator<<(const char* s)
{
  return this->write(s);
}

std::ostream& std::ostream::operator<<(const std::string str)
{
  return this->write(str.c_str());
}

std::ostream& std::ostream::operator<<(const char c)
{
  return this->write(&c);
}
