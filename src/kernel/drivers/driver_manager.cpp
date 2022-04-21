#include <cstdint.h>
#include <cstring/cstring.h>
#include <drivers/driver.h>
#include <drivers/driver_manager.h>
#include <drivers/tty/tty_driver.h>

// Static variables have to be initialized outside the class
uint16_t DriverManager::m_index = 0;
uint16_t DriverManager::m_driver_count = 0;
Driver** DriverManager::m_drivers = nullptr;
bool DriverManager::m_is_initialized = false;

/**
 * Initialized the driver manager by setting where the drivers will be stored
 *
 * @param start       The address in memory at which drivers will be stored
 * @param root_driver A driver that needs to be installed before all other drivers are installed
 * @param drivers     The drivers to install
 */
uint32_t DriverManager::initialize(uint8_t* start, Driver* root_driver, Driver drivers[])
{
  m_is_initialized = true;

  memset(start, 0, sizeof(Driver) * MAX_DRIVERS); // PROBLEM: all drivers are bigger than Driver

  installDriver(root_driver);

  m_drivers = (Driver**) start;

  // TtyDriver* tty = (TtyDriver*) DriverManager::getDriver("tty");

  // tty->write("Installing drivers: ");

  // uint32_t driver_count = sizeof(drivers);

  // for (uint32_t i = 0; i < driver_count; i++) {
  //   Driver driver = drivers[i];

  //   tty->write(driver.getName());

  //   if (i != driver_count) {
  //     tty->write(", ");
  //   }
  // }

  return DRIVER_SUCCESS;
}

/**
 * Install a driver
 *
 * @param Driver driver The driver to install
 *
 * @returns uint32_t Indicates whether the driver was installed successfully or
 * not. A return value of DRIVER_SUCCESS indicates the driver was installed
 * successfully, an a return value of DRIVER_FAILURE indicates the driver was
 * not installed.
 *
 *                   Reasons for failure:
 *                     - the driver manager has not been initialized
 *                     - the maximum numbers of installed drivers has been reached
 *                     - the driver has already been installed
 */
uint32_t DriverManager::installDriver(Driver* driver)
{
  if (!m_is_initialized) {
    // TODO: logging: driver manager not initialized
    return DRIVER_MANAGER_NOT_INITIALIZED;
  }

  if (m_driver_count >= MAX_DRIVERS) {
    // TODO: logging: too many drivers
    return DRIVER_MANAGER_TOO_MANY_DRIVERS;
  }

  if (driver->isInstalled()) {
    // TODO: logging: driver is already installed
    return DRIVER_SUCCESS;
  }

  // Set the driver as installed so that it can be used
  driver->setInstalled(true);

  m_drivers[m_index++] = driver;
  m_driver_count++;

  return DRIVER_SUCCESS;
}

// /**
//  * Remove a previously installed driver
//  *
//  * @param int id The ID of the driver to remove
//  *
//  * @returns int An integer indicating success or failure. A value of
//  DRIVER_SUCCESS
//  *              indicates the the driver was successfully removed, while a
//  value
//  *              of DRIVER_FAILURE indicates that the driver could not be
//  removed.
//  *
//  *              Reasons for failure:
//  *                  - the driver by the specified ID does not exist
//  */
// uint32_t DriverManager::removeDriver(std::string name)
// {
//     if (id >= MAX_DRIVERS) {
//         return DRIVER_FAILURE;
//     }

//     m_drivers[index] = nullptr;
//     m_driver_count--;
//     m_index = index;

//     return DRIVER_SUCCESS;
// }

/**
 * Gets a driver by its name
 *
 * @param name The name of the driver
 *
 * @returns Driver|nullptr Returns the driver if it exists, or `nullptr`
 * otherwise
 */
Driver* DriverManager::getDriver(const char* name)
{
  return m_drivers[0];

  // TODO: compare driver name with passed in driver name
  for (uint16_t i = 0; i < MAX_DRIVERS; i++) {
    Driver* driver = m_drivers[i];

    if (driver != nullptr && strcmp(driver->getName(), name) == 0) {
      return driver;
    }
  }

  return nullptr;
}
