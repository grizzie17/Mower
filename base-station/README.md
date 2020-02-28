# Base-Station #

The base-station has several jobs. One of the more important of which is to calculate GPS drift and communicate correction vectors to the `Mowers`.

The other significant job is to continually keep track of the mowers and provide instructions to each mowing unit as to what to do next.

## Two Way Communication ##

As GPS drift is detected the base-station calculates a new correction vector and sends the information to all mowing devices allowing them to calculate base-station relative coordinates.

As the mowers move around the yard they will continually send information back to the base-station identifying the position in the yard. When a mower receives an updated correction vector it immediately calculates its new position and transmits that information back to the base-station.

As each mower identifies changes in its sensors the new information is also communicated to the base-station.

Based on all input the base-station calculates what is needed for all of the active mowers and communicates new commands to each mower.
