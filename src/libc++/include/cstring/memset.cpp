#include <cstring/cstring.h>

void* memset(void* ptr, int value, size_t num)
{
  if (ptr == NULL) {
    return NULL;
  }

  uint8_t* char_ptr = (uint8_t*) ptr;

  for (size_t i = 0; i < num; i++) {
    *char_ptr++ = value;
  }

  return ptr;
}
