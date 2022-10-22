#ifndef _DRIVER_H
#define _DRIVER_H

#include <string/string.h>

enum DriverType { Io, Keyboard, MemoryManager, Tty };

/**
 * A driver managed by the kernel.
 */
class Driver
{
  friend class DriverManager;

public:
  Driver(const char* name, const char* description, DriverType type);

  const char* getName();
  const char* getDescription();
  DriverType getType();
  bool isInstalled();

private:
  const char* m_name;
  const char* m_description;
  DriverType m_type;
  bool m_installed;

  void setInstalled(bool installed);
};

#endif
