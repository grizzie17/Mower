
#include "CUnitVector.hpp"

#include "gtest/gtest.h"


TEST( CUnitVector, initializeEmpty )
{
	Yogi::Graphics::CUnitVector v;

	ASSERT_DOUBLE_EQ( 1.0, v.getX() );
	ASSERT_DOUBLE_EQ( 0.0, v.getY() );
	ASSERT_DOUBLE_EQ( 0.0, v.getZ() );
}

TEST( CUnitVector, angle45 )
{
	Yogi::Graphics::CVector v( 1.0, 1.0, 0.0 );

	ASSERT_DOUBLE_EQ( v.getX(), v.getY() );
}

TEST( CUnitVector, compareEquals )
{
	Yogi::Graphics::CUnitVector v1( 1.0, 1.0, 1.0 );
	Yogi::Graphics::CUnitVector v2( 1.0, 1.0, 1.0 );

	ASSERT_TRUE( v1 == v2 );
}

TEST( CUnitVector, normalize )
{
	Yogi::Graphics::CUnitVector v( 5.0, 0.0, 0.0 );

	ASSERT_DOUBLE_EQ( 1.0, v.getX() );
	ASSERT_DOUBLE_EQ( 0.0, v.getY() );
	ASSERT_DOUBLE_EQ( 0.0, v.getZ() );
}
