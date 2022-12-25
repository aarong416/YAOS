#include <cstring/cstring.h>
#include <logging/logging.h>

#include <drivers/driver_manager.h>
#include <drivers/tty/tty_driver.h>

/**
 * Logs to the screen
 *
 * @param s The string to write
 */
void log(const char* s, bool appendNewLine)
{
  TtyDriver* tty = (TtyDriver*) DriverManager::getDriver("tty");

  if (appendNewLine) {
    tty->writeLine(s);
  } else {
    tty->write(s);
  }
}
