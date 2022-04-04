#include <cstring/cstring.h>

char* std::strcpy(char* destination, const char* src)
{
  for (size_t i = 0; i < strlen(src); i++) {
    if (src[i] == '\0') {
      destination[i] = '\0';

      return destination;
    }

    destination[i] = src[i];
  }

  return destination;
}
