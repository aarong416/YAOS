#ifndef DRIVER_MANAGER_H
#define DRIVER_MANAGER_H

#define MAX_DRIVERS 256

#include "driver.h"

class DriverManager
{
public:
    static int GetNextDriverId();
    static int InstallDriver(); // TODO: Driver struct?
    static int RemoveDriver(int id);

private:
    Driver m_drivers[MAX_DRIVERS];
    static int m_current_id;
};

#endif
