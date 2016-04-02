#ifndef DEVICE_LIB_H
#define DEVICE_LIB_H

// Device specification is used to map the device functions to the 
// simulation during simulation and to the hardware when running 
// on the device
typedef struct device_spec_t {
    int (*get_time)();
    int (*get_altitude)();
    
    void (*fireCharge)(int);
} DeviceSpec;

int getTimeMS(DeviceSpec* device);

// Sensor readings
int getAltitudeSensorValue(DeviceSpec* device);

// Device drivers 
void fireCharge(DeviceSpec* device, int chargeNumber);

#endif