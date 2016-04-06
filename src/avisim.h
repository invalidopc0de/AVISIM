#ifndef AVISIM_H
#define AVISIM_H

#include <stdio.h>

#include "devicelib.h"

typedef struct avisim_config_t {
    void (*algorithm_init)(DeviceSpec* device);
    void (*algorithm_eval)(DeviceSpec* device);
    
    FILE* simulationFile;
} AVISIMConfig;

int avisim_run(AVISIMConfig* config);

#endif 