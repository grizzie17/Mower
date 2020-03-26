# Automatic / Robotic Lawnmower(s) #

In general, a robotic lawnmower will cut/maintain the bulk of a lawn without human intervention.

There are several different makes of Robotic Lawnmowers on the market today.  They all share the feature of "maintaining" a yard instead of "cutting" a yard.  The "maintaining" is a great idea given the mower trims a little of the yard every day.  The problem with this approach is that the mowers can rarely handle large areas (many of the brands limit the area to 1/4 to 1/2 acre). Many of these brands require the customer to bury wires that identify the limits of the yard, and around obstacles (such as gardens, driveways, etc.).

## Project `Cutter` ##

Our goal is to make an automatic lawn cutting system that is scalable from relatively small and flat yards to large areas that need to be mowed (such as estates, golf courses, etc) and everything in between.

## Requirements ##

### Setup ###

Setup must be very simple.

Essentially we want the setup to be a very short two step process. First is positioning a reference antenna in the yard. Second is identifying the boundaries of the yard.  That should really be it for first setup.

#### Yard-Anchor ####

The afore mentioned *reference antenna* is known as the `yard-anchor` in the `Cutter` project.  As the name implies, the `yard-anchor` provides a logical origin (or anchor) for the `cutter`.  This station MUST be placed in a consistent position every time the `mowers` are used to cut the yard.

The `yard-anchor` should be allowed to be either permanently mounted or positioned over a yard monument.

The next step is to identify the limits of cutting.


#### Boundary Recognition ####

We do NOT want to use any form of buried wires to identify the valid cutting area for a yard.

The customer should be able to turn on the `yard-anchor` and then use a smartphone app. Walk to the key points of the yard boundary, and simply press a button on the phone.

The same technique should be valid to identify areas of the yard where the lawnmower is not allowed.  A map of the yard should be available on the smartphone app to tweak the coordinates.


### Obstruction Identification ###

The lawnmower should be able to automatically identify and record objects such as trees, shrubbery, swing-sets, yard art, etc. Other objects that are transitional should also be identified, these include: toys, pets, people, and other significant objects.

### Terrain Recognition ###

Many robotic mowers must have very flat ground on which to operate.  Our cutter units should be able to discover the terrain of the yard and whenever possible, negotiate valid paths to cut all possible areas.

As an interesting twist, it might be desirable to have the phone app identify on a map of the yard those areas where the cutters were not able to complete. This would quickly identify where manual help would be required.

### Cutting Patterns ###

The customer should be able to specify a set of one or more patterns to use in cutting the yard.

Since it may be possible that the cutter may take more than a single day to cut a yard, the current cutting pattern should be able to be resumed.

It might be possible to allow very specialized patterns that can essentially create yard-art.


### Automatic Recharging ###

Like many of the existing robotic lawnmowers, the cutter units must recognize when their batteries are getting low so they can return to the charging station.

As a different possibility, the cutter units might be scalable to have onboard gas generators so we can handle much larger areas.

### Commercial Scalability ###

All of the data for a yard should be saved and loadable on demand.  The `yard-anchor` should be designed so it can be either permanently mounted or positioned accurately over a monument.  These two features in addition to possible *swarming* and the optional *onboard gas generators* and larger mowing decks would allow commercial yard maintenance companies to use the cutter system to maintain numerous different yards.

After the initial setup (and the positioning of a monument), a company should be able to come to the client's yard, position the `yard-anchor` over the yard *monument*, load the client's yard data, select the cutting pattern and then start the `cutter` units.  While the `cutter`s are busy cutting the yard maintenance employees could do things like edging, trimming areas that are already known as beyond the capabilities of the `cutter`s.

## XXX Requirements ##

*	Accurate positioning within yard
* Steep hill recognition and negotiation

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

* Raspberry PI based computing platform
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
