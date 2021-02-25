#include <kernel.h>
#include <driver_manager.h>
#include <tty_driver.h>

// The entry point for the kernel after it has been loaded by the bootloader
void kernel_main()
{
    char c = 'H';

    // Install the TTY driver for writing text to the screen
    DriverManager::InstallDriver(); // pass the TtyDriver instance (child of Driver)
    TtyDriver tty;

    tty.Write(c);
}
