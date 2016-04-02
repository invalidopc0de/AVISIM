#include <stdio.h>
#include <stdlib.h>
#include "devicelib.h"

/* This program will wrap around the deployment algorithm
    and feed simulated data from stdin
    
    Could have an option to act on 'realtime' fed data?
*/

DeviceSpec* create_device_spec()
{
    DeviceSpec* spec = NULL;
    spec = malloc(sizeof(DeviceSpec));
    
    if (spec == NULL)
    {
        printf("Could not allocate device spec!");
        return NULL;
    }
    
    spec->get_time = NULL;
    spec->get_altitude = NULL;
    spec->fireCharge = NULL;
}

int main(int argc, char** argv)
{
    printf("AVISIM V1.0 By Mark Saunders\n");
    
    // Assuming stdin unless another file is specified
    
    
    return 0;
}