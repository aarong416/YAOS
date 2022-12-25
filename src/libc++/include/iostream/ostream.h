#ifndef _OSTREAM_H
#define _OSTREAM_H

#define BUFFER_SIZE 128

#include <cstddef.h>
#include <string/string.h>

namespace std
{
  class ostream
  {
  public:
    ostream(const char* path);

    std::ostream& write(const char* s);

    std::ostream& operator<<(const char* s); // and other overloads: ints etc
    std::ostream& operator<<(const std::string str);
    std::ostream& operator<<(const char c);

  private:
    const char* m_path;
  };
} // namespace std

#endif