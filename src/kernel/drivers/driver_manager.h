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
  public:
  static uint32_t initialize(uint8_t* start, Driver* root_driver, Driver drivers[]);
  static uint32_t installDriver(Driver* driver);
  static uint32_t removeDriver(const char* name);

  static Driver* getDriver(const char* name);
  inline static Driver** getAllDrivers() { return m_drivers; };
  inline static uint32_t getDriverCount() { return m_driver_count; };

  static Driver** m_drivers;

  private:
  static uint16_t m_index;
  static uint16_t m_driver_count;
  static bool m_is_initialized;
};

#endif
