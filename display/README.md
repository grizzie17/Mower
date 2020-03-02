# Display #

This subsystem will use OpenGL for its rendering engine. This will most likely run in its own thread.

The `Display` subsystem will need to have access to two sets of data.  The `Environment` will serve up a mesh that represents the ground and information about the obstacles.  The `Base-Station` will need to serve up information about the derived terrain, obstacles, boundaries, mowers and their progress.


Active sensors may be added to the display to provide visual feedback of what the `mower`s are 'seeing'.


The `Display` subsystem will run in its own thread/process.

I guess there will need to be a couple of different components for `Display`. One that manages the rendering component(s) and the rendering component(s) themselves.

## Processing ##

`Display` will have no special knowledge about the formats of the different subsystems that will feed the display.  We will treat `Display` as a simple renderer that can handle OpenGL symbology and simple data types such as meshes, triangles, vector lists, etc.  It will also need to handle pushing and popping transformation matrices.

# Thoughts / Questions #

How do we trigger the `Display` to recalculate?

The `Display` should never cause a modification of any data stored in other subsystems.

Can OpenGL be driven/fed by multiple threads running simultaneously?
