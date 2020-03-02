# Mower #

The `Mower` should be as simple and cheap to produce as possible.  It is essentially a battery powered mower blade that can move along a requested vector-list.  Sensors are included so it can report its position, orientation, and current progress.

## Sensors ##

* GPS receiver to calculate the position of the `Mower`.
* yaw, pitch and roll with compass
* wheel revolutions (stepper motors)
* proximity sensors to identify obstacles
* bump sensors in case we miss identify an obstacle
* remaining battery power (volts)
* ? can we sense green grass ?
* ? can we sense how tall the grass is ?
* ? can we sense the edge of a sidewalk or driveway ?

## Communication ##

We will use either WiFi or BlueTooth to communicate with the base-station and the differential-GPS.



## Processing ##

### Differential-GPS ###

When a differential-vector is received it stored for future use. As the GPS sensor provides raw position information a set of new *adjusted* coordinates are calculated based on the provided vector. A *dirty* flag is set indicating that we need to send information to the base-station.

### Commands ###

There are a small set of commands that the `Mower` will know how to handle:

* wake up / sleep
* request status
* Adjust mower blade height
* Turn on/off mower blade
* Move to a position or through a set of positions

### Response ###

A status response is sent to the base-station based on the following parameters:

* Elapsed time
* Distance traveled
* Position list exhausted
* Low Power
* Obstacle encountered

The status packet will include the following:

* ID of the `Mower`
* Time of transmission
* Position x,y,z
* Distance remaining in position list
* Orientation Yaw, pitch, roll
* Obstacle encountered
* Mower blade state (on/off, height)



## Simulator ##

The simulator will interface with proxy sensors that can be triggered via message-queues.

The simulator will interface with proxy motor controllers to turn the wheels.

The simulator will interface with proxy controllers to adjust and power the cutting blades.

The WiFi/Bluetooth interface will be proxy that hides the use of message-queues.
