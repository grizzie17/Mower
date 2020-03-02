# Differential-GPS #

Differential-GPS (DGPS) is a special high-precision positioning system. Regular GPS can actually *drift* as much as 1/4 of a mile.  Obviously, the more satellites that are used the better the precision. But Differential-GPS can get the accuracy down to less than an inch.

The way this works is you have one GPS receiver that is at a known location. It is continuously reading the available GPS satellites. If they calculated position is different from the known position, a vector is calculated to provide the *difference* between the known position and the calculated position. That vector is broadcast on a special frequency. The other GPS receivers must be equipped with a receiver that is listening for the differential vector. That vector is applied to the previously calculated position.  And tada.. you have a very accurate position.

For *real* Differential-GPS you must go through lots of hoops to assure that the FCC is satisfied with your solution.

For our Differential-GPS we are going to cheat, but the result should still be very good.

Instead of having an exactly known location we are going to let our DGPS have an *anchor-station*. Once powered up, the anchor-station will record the first calculated GPS position. That will be used as our *known* location.  The calculated differential vector will make the *anchor-station* the origin (0,0,0) of the logical coordinate system for the yard.

The *anchor-station* will *broadcast* the differential vector as part of a WIFI packet or as a BlueTooth message to the receiving units.

## Simulation ##

For the simulation we will create an object to represent the GPS receiver. The receiver objects will be sent a message that represents the calculated GPS position.  We will most likely even include drift so the algorithms can be created and tested for the Differential-GPS corrections.