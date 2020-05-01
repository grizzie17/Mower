#define SIMULATOR

#include "basestation.ino"


int
main( int argc, char** argv )
{
	setup();

	while ( true )
	{
		loop();
		delay( 20 );
	}

	return 0;
}
