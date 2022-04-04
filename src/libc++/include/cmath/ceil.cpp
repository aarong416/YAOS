#include <libc++/include/cmath/cmath.h>
#include <libc++/include/cstdint.h>

double std::ceil(double x)
{
  return ((long) x) + 1;
}
