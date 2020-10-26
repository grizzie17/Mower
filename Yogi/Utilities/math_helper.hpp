#ifndef HPP_MATH_HELPER
#define HPP_MATH_HELPER

#define _USE_MATH_DEFINES
#include <math.h>


namespace Yogi { namespace Utilities {


class constants
{
public:
    static constexpr double PI = 3.14159265358979323846;
};


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
inline T
max( T a, T b )
{
    return a < b ? b : a;
}


}}  // namespace Yogi::Utilities


#endif  // HPP_MATH_HELPER
