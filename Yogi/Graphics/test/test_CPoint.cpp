
#include "CPoint.hpp"
#include "CVector.hpp"

#include "gtest/gtest.h"

using namespace Yogi::Graphics;

TEST( TPoint, initializeEmpty )
{
	TPoint t;

	ASSERT_DOUBLE_EQ( 0.0, t.x );
	ASSERT_DOUBLE_EQ( 0.0, t.y );
	ASSERT_DOUBLE_EQ( 0.0, t.z );
}

TEST( TPoint, assignArray )
{
	TPoint t;
	t[0] = 0;
	t[1] = 1;
	t[2] = 2;

	ASSERT_DOUBLE_EQ( 0, t[0] );
	ASSERT_DOUBLE_EQ( 1, t[1] );
	ASSERT_DOUBLE_EQ( 2, t[2] );

	ASSERT_DOUBLE_EQ( 0, t.x );
	ASSERT_DOUBLE_EQ( 1, t.y );
	ASSERT_DOUBLE_EQ( 2, t.z );
}

TEST( TPoint, equality )
{
	TPoint t( 0, 1, 2 );
	TPoint x;
	x[0] = 0;
	x[1] = 1;
	x[2] = 2;

	ASSERT_TRUE( t.equals( x ) );
	ASSERT_TRUE( t == x );
}

TEST( CPoint, initializeEmpty )
{
	CPoint v;

	ASSERT_DOUBLE_EQ( 0.0, v.x );
	ASSERT_DOUBLE_EQ( 0.0, v.y );
	ASSERT_DOUBLE_EQ( 0.0, v.z );
}

TEST( CPoint, initializeOne )
{
	CPoint v( 1.0, 1.0, 1.0 );

	ASSERT_DOUBLE_EQ( 1.0, v.getX() );
	ASSERT_DOUBLE_EQ( 1.0, v.getY() );
	ASSERT_DOUBLE_EQ( 1.0, v.getZ() );
}

TEST( CPoint, initializeCopy )
{
	CPoint v( 1.0, 1.0, 1.0 );
	CPoint c = v;

	ASSERT_DOUBLE_EQ( 1.0, c.getX() );
	ASSERT_DOUBLE_EQ( 1.0, c.getY() );
	ASSERT_DOUBLE_EQ( 1.0, c.getZ() );
}

TEST( CPoint, compareEquals )
{
	CPoint v1( 1.0, 1.0, 1.0 );
	CPoint v2( 1.0, 1.0, 1.0 );

	ASSERT_TRUE( v1 == v2 );
}

TEST( CPoint, deriveVector )
{
	CPoint p1( 1.0, 1.0, 0.0 );
	CPoint p2( 0.5, 0.5, 0.0 );

	CVector v = p1 - p2;

	ASSERT_DOUBLE_EQ( 0.5, v.x );
	ASSERT_DOUBLE_EQ( 0.5, v.y );
}
