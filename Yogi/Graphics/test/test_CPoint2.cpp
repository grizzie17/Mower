#include "CPoint2.hpp"

#include "gtest/gtest.h"

using namespace Yogi::Graphics;


TEST( CPoint2, initialize )
{
	CPoint2 p1;
	ASSERT_EQ( 0, p1.x );
	ASSERT_EQ( 0, p1.y );

	CPoint2 p2( 1, 1 );
	ASSERT_EQ( 1, p2.x );
	ASSERT_EQ( 1, p2.y );

	CPoint2 p3( p2 );
	ASSERT_EQ( 1, p3.x );
	ASSERT_EQ( 1, p3.y );
}

TEST( CPoint2, assignment )
{
	CPoint2 p1( 3, 3 );
	CPoint2 p2 = p1;

	ASSERT_EQ( 3, p2.x );
	ASSERT_EQ( 3, p2.y );
}

TEST( CPoint2, diffVector )
{
	CPoint2 p1( 1, 1 );
	CPoint2 p2( 3, 3 );
	CPoint2 result = p2 - p1;

	ASSERT_EQ( 2, result.x );
	ASSERT_EQ( 2, result.y );
}
