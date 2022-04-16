#include <cstring/cstring.h>

char* strncpy(char* destination, const char* src, size_t num)
{
  size_t n = num <= strlen(src) ? num : strlen(src);

  for (size_t i = 0; i < n; i++) {
    if (src[i] == '\0') {
      destination[i] = '\0';

      return destination;
    }

    destination[i] = src[i];
  }

  return destination;
}
