#include <cstring/cstring.h>
#include <drivers/tty_driver.h>
#include <io/io.h>
#include <kernel.h>

// The entry point for the kernel after it has been loaded by the bootloader
void kernel_main()
{
    // DriverManager::initializeDrivers();

    TtyDriver tty;

    // DriverManager::installDriver(tty);

    std::String s("Hello, world!");

    // tty.Write(s);

    // Driver** drivers = DriverManager::getAllDrivers();

    // for (unsigned int i = 0; i < sizeof(drivers) / sizeof(drivers[0]); i++) {
    //     tty->Write('C');
    // }
}
