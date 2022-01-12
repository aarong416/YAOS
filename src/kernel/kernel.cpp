#include <kernel.h>
#include <drivers/tty_driver.h>
#include <cstdint.h>
#include <io/io.h>

// The entry point for the kernel after it has been loaded by the bootloader
void kernel_main()
{
    // DriverManager::initializeDrivers();

    TtyDriver tty;

    // DriverManager::installDriver(tty);

    tty.Write('A');
    tty.Write('A');
    tty.Write('A');

    // Driver** drivers = DriverManager::getAllDrivers();

    // for (unsigned int i = 0; i < sizeof(drivers) / sizeof(drivers[0]); i++) {
    //     tty->Write('C');
    // }
}
