
#include "arduino.hpp"

#include "gtest/gtest.h"


TEST( arduino, delay )
{
	unsigned long uStart = millis();

	delay( 500 );

	unsigned long uEnd = millis();

	ASSERT_LE( 500, uEnd - uStart );
}

TEST( arduino, delayMicroseconds )
{
	unsigned long uStart = micros();
	delayMicroseconds( 1000 );
	unsigned long uEnd = micros();

	ASSERT_LE( 1000, uEnd - uStart );
}