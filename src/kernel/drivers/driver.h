#ifndef _DRIVER_H
#define _DRIVER_H

class Driver
{
public:
    Driver(int type);

private:
    int m_id;
    int m_type; // TODO: should be enum?
};

#endif
