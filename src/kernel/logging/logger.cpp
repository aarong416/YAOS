#include <cstring/cstring.h>
#include <logging/logger.h>

#include <drivers/driver_manager.h>
#include <drivers/tty/tty_driver.h>

/**
 * Logs to the screen
 *
 * @param s The string to write
 */
void Logger::log(const char* s)
{
  // TtyDriver* tty = (TtyDriver*) DriverManager::getDriver("tty");

  // tty->writeChar('c');
}
