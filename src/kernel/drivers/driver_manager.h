#ifndef DRIVER_MANAGER_H
#define DRIVER_MANAGER_H

#define MAX_DRIVERS    256
#define DRIVER_SUCCESS 0
#define DRIVER_FAILURE -1

#include <drivers/driver.h>
#include <cstdint.h>
#include <string/string.h>

/**
 * Manage drivers
 */
class DriverManager
{
    public:
        static std::uint32_t installDriver(Driver* driver);
        static std::uint32_t removeDriver(std::string name);

        static Driver* getDriver(std::string name);
        inline static Driver** getAllDrivers() { return m_drivers; };
        inline static std::uint32_t getDriverCount() { return m_driver_count; };

        static Driver* m_drivers[MAX_DRIVERS];

    private:
        static std::uint16_t m_index;
        static std::uint16_t m_driver_count;
        
};

#endif
