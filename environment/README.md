# Environment #

Subsystem for storing and providing input to the sensors for the `Mower`.

The Environment is also used for input for the `display`.

## Components ##

Digital Terrain Elevation Model. Matrix of elevation numbers.  All elevations are based on psuedo GPS elevations.

Permanent obstacles:

* buildings
* trees
* shrubs
* flower gardens
* barrier walls

Temporary obstacles:

* toys
* equipment
* pets
* children
* cars
* trash/recycle bins

Mower Parts:

* mowers
* base-station

## Processing ##

As a `mower` position is updated, the environment identifies what inputs need to be provided into the virtual sensors.

The Mower Parts would not actually be stored as part of the persistent environments, but would be treated as logical parts for while the simulation is running.
