#include "CVector.hpp"
#include "math_helper.hpp"

#include "gtest/gtest.h"

using namespace Yogi::Graphics;
using namespace Yogi::Utilities;


TEST( CVector, empty )
{
    CVector v;

    ASSERT_DOUBLE_EQ( 1.0, v.getX() );
    ASSERT_DOUBLE_EQ( 0.0, v.getY() );
    ASSERT_DOUBLE_EQ( 0.0, v.getZ() );
}


TEST( CVector, initializeCPoint )
{
    CPoint  vp( 1.0, 1.0, 0.0 );
    CVector v = vp;

    ASSERT_DOUBLE_EQ( 1.0, v.getX() );
    ASSERT_DOUBLE_EQ( 1.0, v.getY() );
    ASSERT_DOUBLE_EQ( 0.0, v.getZ() );
}

TEST( CVector, compareEquals )
{
    CVector v1( 1.0, 1.0, 1.0 );
    CVector v2( 1.0, 1.0, 1.0 );

    ASSERT_TRUE( v1 == v2 );
}

TEST( CVector, vectorAddition )
{
    CPoint  p1;
    CVector v2( 0.0, 1.0, 1.0 );
    CVector v3( 1.0, 1.0, 0.0 );
    CVector v;
    CVector vTest( 1.0, 2.0, 1.0 );
    v = p1 + v2 + v3;

    ASSERT_TRUE( v == vTest );
    ASSERT_DOUBLE_EQ( 1.0, v.getX() );
    ASSERT_DOUBLE_EQ( 2.0, v.getY() );
    ASSERT_DOUBLE_EQ( 1.0, v.getZ() );
}

TEST( CVector, vectorSubtraction )
{
    CVector v1( 0.0, 1.0, 1.0 );
    CVector v2( 1.0, 1.0, 0.0 );
    CVector v;
    CVector vTest( -1.0, 0.0, 1.0 );
    v = v1 - v2;

    ASSERT_TRUE( vTest == v );
    ASSERT_DOUBLE_EQ( -1.0, v.x );
    ASSERT_DOUBLE_EQ( 0.0, v.y );
    ASSERT_DOUBLE_EQ( 1.0, v.z );
}

TEST( CVector, vectorNegation )
{
    CVector v( 1.0, 1.0, 0.0 );
    CVector r = -v;

    ASSERT_DOUBLE_EQ( -1.0f, r.x );
    ASSERT_DOUBLE_EQ( -1.0f, r.y );
    ASSERT_DOUBLE_EQ( 0.0f, r.z );
}


TEST( CVector, addVectorToPoint )
{
    CPoint  p1( 1.0, 1.0, 1.0 );
    CVector v( -1.0, -1.0, -1.0 );

    // glm::vec3 gv = v.getVec();
    // glm::vec3 gp = p1.getVec();

    // gp += gv;

    p1 += v;

    ASSERT_DOUBLE_EQ( 0.0, p1.x );
    ASSERT_DOUBLE_EQ( 0.0, p1.y );
    ASSERT_DOUBLE_EQ( 0.0, p1.z );
}

TEST( CVector, lengthVector )
{
    CVector v( 1.0, 0.0, 0.0 );

    ASSERT_DOUBLE_EQ( v.getLength(), 1.0 );
}

TEST( CVector, getAngleBetween )
{
    CVector v1( 1, 1, 0 );
    CVector v2( 1, 0, 0 );
    double  ang = v1.getAngleBetween( v2 );
    double  deg = degreesFromRadians( ang );

    ASSERT_DOUBLE_EQ( 45.0f, deg );
}

TEST( CVector, getAngleBetweenOpposing )
{
    CVector v1( 1, 0, 0 );
    CVector v2( -1, 0, 0 );
    double  ang = v1.getAngleBetween( v2 );

    ASSERT_DOUBLE_EQ( ang, radiansFromDegrees( 180.0f ) );
}

TEST( CVector, getAngleBetweenZeroVector )
{
    CVector v1( 0, 0, 0 );
    CVector v2( 1, 0, 0 );
    double  ang = v1.getAngleBetween( v2 );

    ASSERT_LT( ang, radiansFromDegrees( -360.0f ) );
}

TEST( CVector, getAngleBetween2 )
{
    CVector v1( 1, 1, 1 );
    CVector v2( 1, 0, 0 );
    double  ang = v1.getAngleBetween( v2 );
    double  deg = degreesFromRadians( ang );

    ASSERT_DOUBLE_EQ( 54.735610317245346, deg );
}

TEST( CVector, getPitchAndYaw )
{
    CVector v1( 1, 1, 1 );
    double  fPitch = 0;
    double  fYaw = 0;
    v1.getPitchAndYaw( &fPitch, &fYaw );

    ASSERT_DOUBLE_EQ( fPitch, radiansFromDegrees( 45.0f ) );
    ASSERT_DOUBLE_EQ( fYaw, radiansFromDegrees( 45.0f ) );
}


// TEST( CVector, get2AnglesBetween )
// {
// 	CVector v1( 1, 1, 1 );
// 	CVector v2( 1, 0, 0 );
// 	double  pitch;
// 	double  yaw;

// 	v1.get2AnglesBetween( v2, &pitch, &yaw );

// 	ASSERT_DOUBLE_EQ( 45.0f, degreesFromRadians( pitch ) );
// 	ASSERT_DOUBLE_EQ( 45.0f, degreesFromRadians( yaw ) );
// }
