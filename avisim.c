#include <stdio.h>
#include <stdlib.h>
#include "devicelib.h"
#include "algorithm.h"

/* This program will wrap around the deployment algorithm
    and feed simulated data from stdin
    
    Could have an option to act on 'realtime' fed data?
*/

struct {
    int time_ms;
    int altitude;
} current_values;

int sim_get_time(DeviceSpec* device)
{
    return current_values.time_ms += 1; // Just so simulated time isn't always the same
}

int sim_get_altitude(DeviceSpec* device)
{
    return current_values.altitude;
}

void sim_fire_charge(DeviceSpec* device)
{
    printf("Charge fired!\n");
}

DeviceSpec* create_device_spec()
{
    DeviceSpec* spec = NULL;
    spec = calloc(1, sizeof(DeviceSpec));
    
    if (spec == NULL)
    {
        printf("Could not allocate device spec!");
        return NULL;
    }
    
    spec->get_time = sim_get_time;
    spec->get_altitude = sim_get_altitude;
    spec->fire_charge = sim_fire_charge;
    
    return spec;
}

int main(int argc, char** argv)
{
    DeviceSpec* spec = NULL;
    
    printf("AVISIM V1.0 By Mark Saunders\n");
    
    // Assuming stdin unless another file is specified
    spec = create_device_spec();
    
    init_algorithm(spec);
    
    
    return 0;
}