# Cutter System #

The `cutter` system consists of several different components, each with its own unique contributions and computing needs.

## Yard Profiles ##

We will need to define a set of data for a `yard profile`.  The data will include:

* coordinate lists of yard boundaries and user-defined obstacles
  * all coordinates are relative to the `yard-anchor`
* discovered terrain models
* mower device IDs that are paired to the `cutter-system`
* last known statuses of mower devices

Yard profiles can be saved and restored as needed.  A yard profile is a key enabler to using the `cutter` system in a multi-yard commercial business.

## Yard-Anchor ##

Provides an *anchor* for the *yard* coordinate system.  To make the system more universal and more accurate, each yard will have a relative coordinate system where the `yard-anchor` is located at coordinate 0,0,0.  Its primary job is to provide information to all other units to assure the local coordinate system.

The station should be powered by batteries (we may also provide solar recharge at some point). The station will contain a GPS receiver and a WiFi (or Bluetooth) transmitter.

The processing is extremely simple:

* When first powered on; the `yard-anchor` records the current GPS position.
  * That position is used to create an initial *correction* vector.
* From then on, anytime an there is a change (drift) regarding the GPS, a new correction vector is calculated.

## Hardware ##

The `cutter` system is made up of several different hardware units.

### Base-Station ##

Provides an *anchor* for the yard coordinate system.  The `yard-anchor` will use a GPS receiver and a WiFi transmitter. The processing will most likely be hosted on an Arduino.  The station should be powered by batteries.  The station simply reads the GPS receiver and calculates a correction vector that is then sent to the `mower`s and the *phone app*.  The station must be rain-water proof.  It does not need to be completely water proof (it will NEVER be submersed under water).

The initial implementation will most likely be a sealed box mounted on a tripod (that can be centered of a yard monument).

### Mowers ###

These units are the actual devices that travel around the yard and cut/trim the grass.

* The mowers should be as simple as we can make them.  Basically:
  * some batteries 
  * couple of stepper motors for the driving wheels
  * motor for cutting blades
  * and some sensors
  * All other logic will be processed by the `mower-manager`.
  * Two-way communication to the `mower-manager`.
  * Most likely use Arduino for the onboard computing
* There are several different onboard sensors
  * GPS
  * Proximity sensors both in front and to the sides of the unit.
  * Bump sensors on all four sides
  * Pitch, Yaw and Roll sensors
  * Compass?
  * Battery Voltage
* By keeping the cost down on the `mower`s we can possibly use *swarming* by multiple `mower`s to cut the yard.
* We should also be able to handle multiple differently sized `mower`s.

### Mower-Manager ###

The manager is actually the heart of the `cutter` system.  The `mower-manager` will most likely be hosted on a Raspberry PI.

### Phone app ###

Initially we will write the *app* to run on *Android*.


## Software Architecture ##

### Yard-Anchor ###

The `yard-anchor` will most likely be powered by an Arduino.  Its main job is to record an initial GPS position following power-up.  And then detect GPS drift and calculate a vector that brings the `yard-anchor` to the 0,0,0 coordinate.  That calculated vector is transmitted to all *bound* mower-units as well as the `phone app`.  This is the only job of the `yard-anchor`.

### Mowers ###

### Mower Manager ###

### Phone App ###