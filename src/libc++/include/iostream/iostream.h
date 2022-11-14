#ifndef _IO_STREAM_H
#define _IO_STREAM_H

#include <iostream/ostream.h>
#include <drivers/driver_manager.h>
#include <drivers/tty/tty_driver.h>

namespace std {
  static std::ostream cout(DriverManager::getDriver("tty"));
}

#endif
