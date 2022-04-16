#ifndef _DRIVER_H
#define _DRIVER_H

#include <string/string.h>

enum DriverType {
    Io,
    Keyboard,
    MemoryManager,
    Tty
};

/**
 * A driver managed by the kernel.
 */
class Driver
{
    public:
        Driver(std::string name, std::string description, DriverType type);

        std::string getName();
        std::string getDescription();
        DriverType getType();
        bool isInstalled();

        void setInstalled(bool installed);

    private:
        std::string m_name;
        std::string m_description;
        DriverType m_type;
        bool m_installed;
};

#endif
