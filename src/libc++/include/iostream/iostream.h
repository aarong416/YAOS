#ifndef _IO_STREAM_H
#define _IO_STREAM_H

#include <drivers/driver_manager.h>
#include <drivers/tty/tty_driver.h>
#include <iostream/ostream.h>

namespace std
{
  static std::ostream cout("/dev/stdin");
} // namespace std

#endif
