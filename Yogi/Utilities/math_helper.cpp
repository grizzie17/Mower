
#include "math_helper.hpp"

#define _USE_MATH_DEFINES
#include <cfloat>
#include <cmath>
#include <math.h>


namespace Yogi { namespace Utilities {

double
normalizeDegrees( double degrees )
{
    if ( degrees < 0.0 )
        return fmod( degrees, -360.0 );
    else
        return fmod( degrees, 360.0 );
}

double
radiansFromDegrees( double degrees )
{
    return ( normalizeDegrees( degrees ) * constants::PI ) / 180.0;
}

double
degreesFromRadians( double radians )
{
    return ( radians * 180.0 ) / constants::PI;
}

static double
fRound( double f )
{
    double v = 0.0;
    //const double denom = 100000000.0;

    if ( ::fabs( f ) <= 0.0 + DBL_EPSILON )
    {
        v = 0.0;
    }
    else
    {
        v = f;
        //v = round( f * denom ) / denom;
        // long u = (long)( f * denom + ( f < 0.0f ? -0.5f : 0.5f ) );
        // v = ( (double)u ) / denom;
    }

    return v;
}

double
fCosine( double rads )
{
    return fRound( ::cos( rads ) );
}

double
fSine( double rads )
{
    return fRound( ::sin( rads ) );
}


}}  // namespace Yogi::Utilities