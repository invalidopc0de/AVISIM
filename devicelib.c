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

// Device drivers 
inline void fireCharge(DeviceSpec* device, int chargeNumber)
{
    device->fire_charge(chargeNumber);
}