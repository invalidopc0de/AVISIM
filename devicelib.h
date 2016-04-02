#ifndef DEVICE_LIB_H
#define DEVICE_LIB_H

// Device specification is used to map the device functions to the 
// simulation during simulation and to the hardware when running 
// on the device
typedef struct device_spec_t {
    int (*get_time)();
    int (*get_altitude)();
    
    void (*fire_charge)(int);
} DeviceSpec;


extern int getTimeMS(DeviceSpec* device);

extern int getAltitudeSensorValue(DeviceSpec* device);

extern void fireCharge(DeviceSpec* device, int chargeNumber);

#endif