#ifndef DEVICE_LIB_H
#define DEVICE_LIB_H

// Device specification is used to map the device functions to the 
// simulation during simulation and to the hardware when running 
// on the device
typedef struct device_spec_t {
    int (*get_time)();
    int (*get_altitude)();
    
    int (*get_accel_x)();
    int (*get_accel_y)();
    int (*get_accel_z)();
    
    void (*fire_charge)(int);
} DeviceSpec;


extern int getTimeMS(DeviceSpec* device);

extern int getAltitude(DeviceSpec* device);

extern int getAccelX(DeviceSpec* device);

extern int getAccelY(DeviceSpec* device);

extern int getAccelZ(DeviceSpec* device);

extern void fireCharge(DeviceSpec* device, int chargeNumber);

#endif