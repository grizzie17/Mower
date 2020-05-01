#include "CVector.hpp"

#include "gtest/gtest.h"


TEST( CVector, empty )
{
	Yogi::Graphics::CVector v;

	ASSERT_DOUBLE_EQ( 1.0, v.getX() );
	ASSERT_DOUBLE_EQ( 0.0, v.getY() );
	ASSERT_DOUBLE_EQ( 0.0, v.getZ() );
}


TEST( CVector, initializeCPoint )
{
	Yogi::Graphics::CPoint  vp( 1.0, 1.0, 0.0 );
	Yogi::Graphics::CVector v = vp;

	ASSERT_DOUBLE_EQ( 1.0, v.getX() );
	ASSERT_DOUBLE_EQ( 1.0, v.getY() );
	ASSERT_DOUBLE_EQ( 0.0, v.getZ() );
}

TEST( CVector, compareEquals )
{
	Yogi::Graphics::CVector v1( 1.0, 1.0, 1.0 );
	Yogi::Graphics::CVector v2( 1.0, 1.0, 1.0 );

	ASSERT_TRUE( v1 == v2 );
}
