#ifdef SIMULATOR
#	include "arduino.hpp"
#endif

unsigned long g_uTimePrevious = 0;
int           g_nCount = 0;

void
setup()
{
	Serial.begin( 9600 );
	g_uTimePrevious = millis();
	g_nCount = 0;
}

void
loop()
{
	unsigned long uTimeCurrent = millis();
	if ( 500 < uTimeCurrent - g_uTimePrevious )
	{
		g_uTimePrevious = uTimeCurrent;
		++g_nCount;
		Serial.println( g_nCount );
	}
}
