#include <cstring/cstring.h>

void* std::memcpy(void* destination, void* source, size_t num)
{
  unsigned char* dst = (unsigned char*) destination;
  const unsigned char* src = (unsigned char*) source;

  for (size_t i = 0; i < num; i++) {
    dst[i] = src[i];
  }

  return dst;
}
