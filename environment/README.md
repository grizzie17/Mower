# Environment #

The `Environment` subsystem identifies simulated terrain (via elevation data), obstacles such as trees, bushes, driveways, buildings, people, animals, etc.  Basically, everything that is needed to identify the real-world inputs to the simulated sensors for the `Mower`.

The Environment will need to serve up data for the `display` subsystem.

This subsystem will run in its own thread (and possibly in its own process)

## Positioning ##

The `Environment`'s coordinate system is always relative to the lower-left corner of the terrain model.

There will be a second coordinate system that is relative to the `Base-Station`.  That information will most likely stored in the base-station's data.

## Terrain ##

The terrain (elevation data) will be represented via DTM.  We will use the simplest case of storing a grid/matrix, where the grid is uniformly spaced in rows and columns.  The coordinates/positions represented in the grid are imaginary. The lower-left corner will represent 0,0,0.

The grid will include the following data.

* Spacing of the rows
* Spacing of the columns
* All rows will be assumed to be parallel to the x-axis.
* All columns will be assumed to be parallel to the y-axis.
* Each entry in the grid will contain an altitude.

In addition to the elevation grid, special coordinate lists would be used to identify things like ditches.  One might consider a ditch to be an obstacle, but depending upon the severity of the slopes and the depth, the mower might be able to traverse it.

## Base-Station ##

The base-station's 3d position will be represented relative to the Terrain's origin.

## Obstacles ##

For simplicity of placement and rendering, obstacles will also be placed relative to the Terrain's origin.

Most obstacles may have an infinite z depth and height, in other words they may only contain an x,y pair.


## Positioning ##

The environment's coordinate system 

All coordinates in the simulation (and in the real system) will be zero relative to the base-station.

## Components ##

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

# Thoughts / Questions #

Should we keep all knowledge of the `mower` out of the `Environment`?

How do we trigger a query against the `Environment` to feed the simulated sensors?

We will obviously need to convert the base-station coordinates to the environment as part of getting feedback for the mower's sensors.
