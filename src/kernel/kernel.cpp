#include <drivers/driver_manager.h>
#include <drivers/memory_manager_driver.h>
#include <drivers/tty_driver.h>
#include <kernel.h>
#include <string/string.h>

// The entry point for the kernel after it has been loaded by the bootloader
void kernel_main()
{
    MemoryManagerDriver<1024> memoryManager(kernel_end);

    // TtyDriver* tty = new TtyDriver();

    // DriverManager::installDriver(tty);

    // uint32_t n = 45;

    // std::string s = std::string("Hi there");

    // tty->Write("DwfAwfF");

    // Driver* ttyDriver = DriverManager::getDriver("tty");

    // if (ttyDriver == nullptr) {
    //     tty->Write("Driver not found");
    // } else {
    //     tty->Write(ttyDriver->getDescription());
    // }

    // delete tty;
}
