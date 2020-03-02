# Automatic / Robotic Lawnmower(s) #

In general, a robotic lawnmower will cut/maintain the bulk of a lawn without human intervention.

There are several different makes of Robotic Lawnmowers on the market today.  They all share the feature of "maintaining" a yard instead of "cutting" a yard.  The "maintaining" is a great idea given the mower trims a little of the yard every day.  The problem with this approach is that the mowers can rarely handle large areas (many of the brands limit the area to 1/4 to 1/2 acre).  Another problem is that the mower is vulnerable to theft or vandalism while cutting.

## Requirements ##

*	Boundary recognition (without using buried wires)
*	Accurate positioning within yard
*	Go / No-Go zones
*	Obstruction identification and avoidance
  * Learning permanent obstructions
*	Controllable cutting patterns
  * Continue with a single cutting pattern until it has been completed
  * This implies that we must track progress throughout the cutting
* Steep hill recognition and negotiation
* Automatic Recharging
  * Return to the charging station and automatically plugin

## Wishes ##

* Use existing commercial parts when possible
* Easy to hose off for cleaning
* Operate in inclement weather
* Sense lack of grass
  * At a minimum, turn off blades
* Scalable to allow swarming robots
* Quiet cutter
* Alarms if someone tries to pick-up unit
* Use by commercial mowing services
  * Optional onboard gas generator
  * Larger cutting deck
  * Easy save/restore for an individual client’s yard

## Challenges ##

* Obstructions
* Hill negotiation

## Assumptions ##

* Rasberry PI based computing platform
  * Utilize built-in sensors/services
    * GPS
    * Orientation
    * Compass???
    * WiFi
  * Accelerometers are not accurate enough to assist with navigation

## Positioning Systems (no boundary wires) ##

To provide for better customer acceptance, we should avoid using boundary wires to identify the limits of the yard.  The customer should be able to walk to the critical boundary positions with a smartphone or tablet.  Press a button on the screen and either add or subtract areas to/from the yard.

After investigating several alternative approaches; the technique that I settled on was Global Positioning System (GPS).

Normal GPS can drift as much as a quarter of a mile.  The only way to increase the accuracy is to use Differential GPS (DGPS). Differential GPS is normal GPS plus an additional signal that provides a vector to correct the GPS drift problem.  We can use two GPS antennas to implement our Differential GPS.  One would be identified as our "Base-GPS" and the other(s) would be the device/mower GPS.
 
The "Base-GPS" is our unit that calculates the correction vector. The key to the "Base-GPS" is that it must be stationary and constant from use to use. All coordinates will be relative to the Base-GPS. The correction vector would make the Base-GPS coordinate 0,0,0. To accomplish this, the base unit would record the first GPS coordinates that it reads after powerup.  From that point forward any time the GPS coordinates change (drift) a new vector would be calculated and broadcast (via WiFi) to the mowing units.

One suggestion is to have the charging station host the "Base-GPS".

By using this simple and "local" DGPS we can identify the boundaries, in addition to where we are located within the yard.  The "local" DGPS could be reinitialized, by positioning the base unit, and then identify two other points on the boundary.

## Obstruction detection and avoidance ##

There are two segments to the Obstruction problem; first is identifying an obstruction, second is recognize when an obstruction is permanent and needs to be learned.

Simple detection may involve multiple techniques.

## Cutting Patterns ##

To provide variety we should support user defined cutting patterns. It should even be possible to provide yard pictures and messages.

The current pattern progress will always be maintained so we can resume cutting.

## Recharging ##

Do we want to use induction charging?

## Quiet cutter ##

The cutter could be a simple disc with movable cutters along the edge.  The cutters would stick out no more than 1-1.5 inches.  The theory is that since the bulk of the cutter is a clean disc there would be little to interact with the air or the grass to make noise. It will be very important that we choose a very quiet motor.

## A swarming thought ##

We could have the mowing units be very limited in the computing capabilities.  Essentially, each mower could identify the DGPS position. Turn on and off the blade motor. Seek to a yard position. And identify when it is blocked or otherwise disabled.  This approach might make the mower unit very inexpensive so swarming a yard might become practical.  This would also allow a single processor stored off of the mower to be used to control one or many units.

## Implementation Thoughts ##

* Sensors/services
  * Android Tablet sensors
    * GPS
    * Orientation
    * WiFi or bluetooth
  * Wheel rotations
  * Power reserves
  * Obstruction detection
  * Green grass detection
  * Grass height
