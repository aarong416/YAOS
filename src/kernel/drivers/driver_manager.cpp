#include <cstdint.h>
#include <cstring/cstring.h>
#include <drivers/driver.h>
#include <drivers/driver_manager.h>
#include <drivers/tty/tty_driver.h>

DriverManager::DriverManager()
{
  // Set all drivers to null pointers initially
  for (uint32_t i = 0; i < MAX_DRIVERS; i++) {
    m_drivers[i] = nullptr;
  }
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

  // TODO: this will become a problem when drivers are removed and the index is reset
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
// TODO: this needs to reshuffle all drivers in the array so that there are no
//       empty items (nullptr's) in the array between drivers
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
 * @returns Driver|nullptr Returns the driver if it exists, or `nullptr` otherwise
 */
Driver* DriverManager::getDriver(const char* name)
{
  // TODO: compare driver name with passed in driver name
  for (uint16_t i = 0; i < MAX_DRIVERS; i++) {
    Driver* driver = m_drivers[i];

    if (driver != nullptr && strcmp(driver->getName(), name) == 0) {
      return driver;
    }
  }

  return nullptr;
}
