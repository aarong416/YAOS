#include <cstdint.h>
#include <cstdlib/cstdlib.h>
#include <cstring/cstring.h>

void itoh(int n, char* s)
{
  if (n == 0) {
    s[0] = '0';
    s[1] = '0';
    s[2] = '\0';

    return;
  }

  const char* hex_chars = "0123456789ABCDEF";

  uint32_t len = 0;
  uint32_t i = 0;

  while (n != 0) {
    s[i++] = hex_chars[n % 16];

    n /= 16;
    len++;
  }

  if (len % 2 != 0) {
    s[len] = '0';
    s[len + 1] = '\0';
  } else {
    s[len] = '\0';
  }

  strrev(s);
}
