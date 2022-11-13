#include <cstdlib/cstdlib.h>
#include <string/string.h>

std::string std::to_string(int value)
{
  // 32 bit integers have a max value of 4 294 967 296, leading to
  // a maximum string length of 10 (plus 1 for the null byte)
  char* s = new char[11];

  s[10] = '\0';

  itoa(value, s, 10);

  std::string str(s);

  delete[] s;

  return str;
}
