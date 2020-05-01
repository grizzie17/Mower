
#include "CPoint.hpp"

#include "gtest/gtest.h"


TEST( CPoint, initializeEmpty )
{
	Yogi::Graphics::CPoint v;

	ASSERT_DOUBLE_EQ( 0.0, v.getX() );
	ASSERT_DOUBLE_EQ( 0.0, v.getY() );
	ASSERT_DOUBLE_EQ( 0.0, v.getZ() );
}

TEST( CPoint, initializeOne )
{
	Yogi::Graphics::CPoint v( 1.0, 1.0, 1.0 );

	ASSERT_DOUBLE_EQ( 1.0, v.getX() );
	ASSERT_DOUBLE_EQ( 1.0, v.getY() );
	ASSERT_DOUBLE_EQ( 1.0, v.getZ() );
}

TEST( CPoint, initializeCopy )
{
	Yogi::Graphics::CPoint v( 1.0, 1.0, 1.0 );
	Yogi::Graphics::CPoint c = v;

	ASSERT_DOUBLE_EQ( 1.0, c.getX() );
	ASSERT_DOUBLE_EQ( 1.0, c.getY() );
	ASSERT_DOUBLE_EQ( 1.0, c.getZ() );
}

TEST( CPoint, compareEquals )
{
	Yogi::Graphics::CPoint v1( 1.0, 1.0, 1.0 );
	Yogi::Graphics::CPoint v2( 1.0, 1.0, 1.0 );

	ASSERT_TRUE( v1 == v2 );
}
