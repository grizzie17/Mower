# Sensors #

There will be two types of sensor objects; one encapsulates/abstracts a real sensor, and the other sensor objects (which uses the same interface as the real sensors), simulate a real sensor by talking to the `Environment` object.

To clarify, there will be an abstract interface (class/struct) that will return the state of each sensor.  Then there will be an implementation of the sensor interface that will talk with a *real* sensor. Then there will be another implementation of the same interface that communicates with the `Environment` object to get its input. The rest of the non-simulator subsystems will not know to which type of `Sensor` object it is communicating.
