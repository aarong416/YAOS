#ifndef DRIVER_MANAGER_H
#define DRIVER_MANAGER_H

#define MAX_DRIVERS 256
#define DRIVER_SUCCESS 0
#define DRIVER_FAILURE -1

#include <cstdint.h>
#include <drivers/driver.h>
#include <string/string.h>

/**
 * Manage drivers
 */
class DriverManager
{
  public:
  static uint32_t installDriver(Driver* driver);
  static uint32_t removeDriver(std::string name);

  static Driver* getDriver(std::string name);
  inline static Driver** getAllDrivers() { return m_drivers; };
  inline static uint32_t getDriverCount() { return m_driver_count; };

  static Driver* m_drivers[MAX_DRIVERS];

  private:
  static uint16_t m_index;
  static uint16_t m_driver_count;
};

#endif
