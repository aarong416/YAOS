#ifndef _OSTREAM_H
#define _OSTREAM_H

#include <cstddef.h>
#include <string/string.h>

namespace std
{
  class ostream
  {
  public:
    ostream(void*(const char* s));

    std::ostream write(const char* s, size_t n);

  private:
    std::string m_buffer; // TODO: this should be a char array, since the buffer is emptied
                          //       when it reaches max capacity
    void* (*m_callback)(const char* s);
  };
} // namespace std

#endif