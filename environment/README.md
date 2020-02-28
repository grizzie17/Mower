# Environment #

The `Environment` subsystem identifies simulated terrain (via elevation data), obstacles such as trees, bushes, driveways, buildings, people, animals, etc.  Basically, everything that is needed to identify the real-world inputs to the simulated sensors for the `Mower`.

The `Environment` should also keep track of the simulated position and orientation of the `Mower`.

The Environment is also used for input for the `display`.

This subsystem will run in its own thread (and possiby in its own process)

## Positioning ##

All coordinates in the simulation (and in the real system) will be zero relative to the base-station.

## Components ##

Digital Terrain Elevation Model. Matrix of elevation numbers.  All elevations are based on psuedo GPS elevations.

Permanent obstacles:

* buildings
* trees
* shrubs
* flower gardens
* barrier walls
* yard boundaries

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
