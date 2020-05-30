#ifndef HPP_MATH_HELPER
#define HPP_MATH_HELPER

#define _USE_MATH_DEFINES
#include <math.h>

#ifndef M_PI
template <typename T>
constexpr T = M_PI( 3.14159265358979323846 );
#endif


namespace Yogi { namespace Utilities {

double
normalizeDegrees( double degrees );

double
radiansFromDegrees( double degrees );

double
degreesFromRadians( double rads );

double
fCosine( double rads );

double
fSine( double rads );


template <typename T>
T
max( T a, T b )
{
    return a < b ? b : a;
}


}}    // namespace Yogi::Utilities


#endif    // HPP_MATH_HELPER
