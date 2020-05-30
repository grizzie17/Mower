
#include "arduino.hpp"

#include "gtest/gtest.h"


TEST( arduino, aaaaaa )
{
	unsigned long uMillis = millis();
	unsigned long uMicros = micros();
}


TEST( arduino, delay )
{
	unsigned long uStart = millis();
	delay( 100 );
	unsigned long uEnd = millis();

	ASSERT_LT( 0, uEnd );
	ASSERT_LE( 100, uEnd - uStart );
}

TEST( arduino, delayMicroseconds )
{
	unsigned long uStart = micros();
	delayMicroseconds( 500 );
	unsigned long uEnd = micros();

	ASSERT_LT( 0, uEnd );
	ASSERT_LE( 500, uEnd - uStart );
}