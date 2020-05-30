
#include "math_helper.hpp"

#include "gtest/gtest.h"

using namespace Yogi::Utilities;

TEST( MathHelper, sinAndCosOf90degrees )
{
    double rads = radiansFromDegrees( 90.0 );
    double c = fCosine( rads );
    double s = fSine( rads );
    ASSERT_DOUBLE_EQ( 0.0, c );
    ASSERT_DOUBLE_EQ( 1.0, s );
}

TEST( MathHelper, normalizeAngle )
{
    double result = normalizeDegrees( 90.0 + 360.0 );

    ASSERT_DOUBLE_EQ( 90.0, result );

    result = normalizeDegrees( -90.0 - 360.0 );

    ASSERT_DOUBLE_EQ( -90.0, result );
}
