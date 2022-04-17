#include <cstdint.h>
#include <drivers/driver.h>

/**
 * Create a driver with a name and a type
 *
 * @param std::string name        A unique identifier for the driver, all
 *                                lowercase and separated with underscores
 * @param std::string description The driver's description
 * @param DriverType  type        The type of the driver
 */
Driver::Driver(const char* name, const char* description, DriverType type)
  : m_name(name)
  , m_description(description)
  , m_type(type)
{
}

const char* Driver::getName()
{
  return m_name;
}

const char* Driver::getDescription()
{
  return m_description;
}

DriverType Driver::getType()
{
  return m_type;
}

bool Driver::isInstalled()
{
  return m_installed;
}

void Driver::setInstalled(bool installed)
{
  m_installed = installed;
}
