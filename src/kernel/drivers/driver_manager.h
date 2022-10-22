#ifndef DRIVER_MANAGER_H
#define DRIVER_MANAGER_H

#define MAX_DRIVERS 256
#define DRIVER_SUCCESS 0
#define DRIVER_FAILURE -1
#define DRIVER_MANAGER_TOO_MANY_DRIVERS -2
#define DRIVER_MANAGER_NOT_INITIALIZED -3

#include <cstdint.h>
#include <drivers/driver.h>
#include <string/string.h>

/**
 * Manage drivers
 */
class DriverManager
{
  friend class Driver;

public:
  DriverManager();

  uint32_t installDriver(Driver* driver);
  uint32_t removeDriver(const char* name);

  Driver* getDriver(const char* name);
  inline Driver** getAllDrivers() { return m_drivers; };
  inline uint32_t getDriverCount() { return m_driver_count; };

private:
  Driver* m_drivers[MAX_DRIVERS];
  uint16_t m_index;
  uint16_t m_driver_count;
};

#endif
