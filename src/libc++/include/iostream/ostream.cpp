#include <cstddef.h>
#include <string/string.h>

#include <iostream/ostream.h>

std::ostream::ostream(void* (*callback)(const char* s))
  : m_callback(callback)
{
}

std::ostream std::ostream::write(const char* s, size_t n)
{
  // TODO: add to the buffer here

  // m_callback(s);

  return *this;
}
