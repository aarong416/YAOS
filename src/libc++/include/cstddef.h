#ifndef CSTDDEF_H
#define CSTDDEF_H

#define NULL ((void*) 0)

#include <cstdint.h>

namespace std {
  typedef unsigned long size_t;
  typedef std::uint32_t ptrdiff_t;
}

#endif