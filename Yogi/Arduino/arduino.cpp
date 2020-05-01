

#include "arduino.hpp"
#include "CSerial.hpp"

#include <chrono>
#include <thread>

Yogi::Arduino::CSerial Serial;

static unsigned long long
millis_()
{
	unsigned long long milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(
			std::chrono::system_clock::now().time_since_epoch() )
											  .count();
	return milliseconds;
}

unsigned long long g_uMillisBase = 0;
unsigned long
millis()
{
	if ( 0 == g_uMillisBase )
		g_uMillisBase = millis_();
	unsigned long long u = millis_();
	return (unsigned long)( u - g_uMillisBase );
}

unsigned long long
micros_()
{
	unsigned long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(
			std::chrono::system_clock::now().time_since_epoch() )
											  .count();
	return microseconds;
}

unsigned long long g_uMicrosBase = 0;
unsigned long
micros()
{
	if ( 0 == g_uMicrosBase )
		g_uMicrosBase = micros_();
	unsigned long long u = micros_();
	return (unsigned long)( u - g_uMicrosBase );
}

void
delay( unsigned long milli )
{
	std::this_thread::sleep_for( std::chrono::milliseconds( milli ) );
}

void
delayMicroseconds( unsigned long micro )
{
	std::this_thread::sleep_for( std::chrono::microseconds( micro ) );
}
