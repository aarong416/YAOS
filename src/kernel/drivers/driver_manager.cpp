#include <cstdint.h>
#include <drivers/driver.h>
#include <drivers/driver_manager.h>

// Static variables have to be initialized outside the class
std::uint16_t DriverManager::m_index = 0;
std::uint16_t DriverManager::m_driver_count = 0;
Driver* DriverManager::m_drivers[MAX_DRIVERS] = { nullptr };

/**
 * Install a driver
 * 
 * @param Driver driver The driver to install
 * 
 * @returns uint32_t Indicates whether the driver was installed successfully or not. A return value
 *                   of DRIVER_SUCCESS indicates the driver was installed successfully, an a return
 *                   value of DRIVER_FAILURE indicates the driver was not installed.
 * 
 *                   Reasons for failure:
 *                     - the maximum numbers of installed drivers has been reached
 */
std::uint32_t DriverManager::installDriver(Driver* driver)
{
    if (m_index >= MAX_DRIVERS) {
        // TODO: logging: too many drivers
        return DRIVER_FAILURE;
    }

    driver->setInstalled(true);

    m_drivers[m_index++] = driver;

    m_driver_count++;

    return DRIVER_SUCCESS;
}

// /**
//  * Remove a previously installed driver by its ID
//  * 
//  * @param int id The ID of the driver to remove
//  * 
//  * @returns int An integer indicating success or failure. A value of DRIVER_SUCCESS
//  *              indicates the the driver was successfully removed, while a value
//  *              of DRIVER_FAILURE indicates that the driver could not be removed.
//  *              
//  *              Reasons for failure:
//  *                  - the driver by the specified ID does not exist
//  */
// std::uint32_t DriverManager::removeDriver(std::string name)
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
Driver* DriverManager::getDriver(std::string name)
{
  // TODO: change compare() to ==
  for (std::uint16_t i = 0; i <= MAX_DRIVERS; i++) {
    Driver* driver = m_drivers[i];

    if (driver != nullptr) {
      return m_drivers[i];
    }
  }

  return nullptr;
}
