#include <stdio.h>
#include <stdlib.h>

#include "devicelib.h"
#include "algorithm.h"
#include "cJSON/cJSON.h"

/* This program will wrap around the deployment algorithm
    and feed simulated data from stdin
    
    Could have an option to act on 'realtime' fed data?
*/

#define TRUE    1
#define FALSE   0

#define MAX_LINE 128

struct {
    int time_ms;
    int altitude;
} current_values;

int sim_get_time()
{
    return current_values.time_ms += 1; // Just so simulated time isn't always the same
}

int sim_get_altitude()
{
    return current_values.altitude;
}

void sim_fire_charge(int chargeNumber)
{
    printf("Charge %d fired! T:%d\n", chargeNumber, current_values.time_ms);
}

DeviceSpec* create_device_spec()
{
    DeviceSpec* spec = NULL;
    spec = calloc(1, sizeof(DeviceSpec));
    
    if (spec == NULL)
    {
        printf("Could not allocate device spec!\n");
        return NULL;
    }
    
    spec->get_time = sim_get_time;
    spec->get_altitude = sim_get_altitude;
    spec->fire_charge = sim_fire_charge;
    
    return spec;
}

void parseTelemetryUpdate(char* line)
{
    cJSON* root = cJSON_Parse(line);
    if (root == NULL)
    {
        printf("Unable to parse message!\n");
        return;
    }
    
    
    // Time element required
    cJSON* element = cJSON_GetObjectItem(root, "time_ms");
    if (element != NULL)
    {
        current_values.time_ms = element->valueint;
    } else {
        printf("time_ms element required!\n");
        return;
    }
    
    // Update altimeter value
    element = cJSON_GetObjectItem(root, "altitude");
    if (element != NULL)
    {
        current_values.altitude = element->valueint;
    }
    
    cJSON_Delete(root);
}

int main(int argc, char** argv)
{
    DeviceSpec* spec = NULL;
    char running = TRUE;
    char buffer[MAX_LINE];
    FILE* input_file = stdin;
    
    printf("AVISIM V1.0 By Mark Saunders\n");
    
    // Assuming stdin unless another file is specified
    spec = create_device_spec();
    
    init_algorithm(spec);
    
    while (running) {
        // Read line from stdin
        if (fgets(buffer, MAX_LINE, input_file) != NULL)
        {
            // Parse command type
            switch (buffer[0])
            {
            case 't':
                // TODO/MS make this safer with a max size
                parseTelemetryUpdate(&buffer[1]);
                break;
            case 'q':
                running = FALSE;
                break;
            default:
                printf("Invalid command\n");
                break;
            }
            
            // call algorithm evaluation
        } else {
            running = FALSE;
        }
    }
    return 0;
}