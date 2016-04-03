# AVISIM

A simulator for simulating things

[![Build Status](https://travis-ci.org/mscoolnerd/AVISIM.svg?branch=master)](https://travis-ci.org/mscoolnerd/AVISIM)

# Update format

The simulated telemetry updates are formatted as:

<message type char> <message data>

The message data is provided in JSON format on a single line. 

## Message Types

### Telemetry Update Message

Message Char: 't'

The telemetry update data consists of a JSON-formatted set of sensor values and a current timestamp.  

Note that the time_ms is always required. 

{ "time_ms" : 5, "altitude" : 4234 }

### Quit Message

Message Char: 'q'

Pretty obvious... quits the simulation
