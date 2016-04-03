#include "devicelib.h"

inline int getTimeMS(DeviceSpec* device) 
{
    return device->get_time();
}

// Sensor readings
inline int getAltitudeSensorValue(DeviceSpec* device)
{
    return device->get_altitude();
}

inline int getAccelX(DeviceSpec* device)
{
    return device->get_accel_x();
}

inline int getAccelY(DeviceSpec* device)
{
    return device->get_accel_y();
}

inline int getAccelZ(DeviceSpec* device)
{
    return device->get_accel_z();
}

// Device drivers 
inline void fireCharge(DeviceSpec* device, int chargeNumber)
{
    device->fire_charge(chargeNumber);
}