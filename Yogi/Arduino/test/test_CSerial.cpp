
#include "CSerial.hpp"
#include "arduino.hpp"

#include "gtest/gtest.h"


TEST( CSerial, string )
{
	Serial.begin( 9600 );
	Serial.print( "Sample String" );

	std::string s( Serial.to_str() );

	ASSERT_STREQ( s.c_str(), "Sample String" );
}

TEST( CSerial, integer )
{
	Serial.begin( 9600 );
	Serial.print( 1234 );

	std::string s( Serial.to_str() );

	ASSERT_STREQ( s.c_str(), "1234" );
}