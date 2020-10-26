
#include "CUnitVector.hpp"
#include "math_helper.hpp"

#include "gtest/gtest.h"


using namespace Yogi::Graphics;
using namespace Yogi::Utilities;


TEST( CUnitVector, initializeEmpty )
{
    CUnitVector v;

    ASSERT_FLOAT_EQ( 1.0, v.getX() );
    ASSERT_FLOAT_EQ( 0.0, v.getY() );
    ASSERT_FLOAT_EQ( 0.0, v.getZ() );
}

TEST( CUnitVector, angle45 )
{
    CVector v( 1.0, 1.0, 0.0 );

    ASSERT_FLOAT_EQ( v.getX(), v.getY() );
}

TEST( CUnitVector, compareEquals )
{
    CUnitVector v1( 1.0, 1.0, 1.0 );
    CUnitVector v2( 1.0, 1.0, 1.0 );

    ASSERT_TRUE( v1 == v2 );
}

TEST( CUnitVector, normalize )
{
    CUnitVector v( 5.0, 0.0, 0.0 );

    ASSERT_FLOAT_EQ( 1.0, v.getX() );
    ASSERT_FLOAT_EQ( 0.0, v.getY() );
    ASSERT_FLOAT_EQ( 0.0, v.getZ() );
}

TEST( CUnitVector, multiply )
{
    CUnitVector u( 1.0, 0.0, 0.0 );
    CVector     v = u * 5.0;

    ASSERT_FLOAT_EQ( 5.0, v.getX() );

    u.set( 1.0, 1.0, 0.0 );
    v = u * 10.0;

    ASSERT_FLOAT_EQ( v.getLength(), 10.0 );
}

TEST( CUnitVector, buildFromPitchAndYaw )
{
    float fPitch = radiansFromDegrees( 45.0 );
    float fYaw = radiansFromDegrees( 45.0 );

    CUnitVector u = CUnitVector::buildFromPitchAndYaw( fPitch, fYaw );

    CUnitVector a( 1, 1, 1 );

    ASSERT_TRUE( u == a );
}
