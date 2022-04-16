#include <cmath/cmath.h>
#include <cstdint.h>

double floor(double x)
{
  uint32_t remainder = x - (uint32_t) x;

  return x - remainder;
}
