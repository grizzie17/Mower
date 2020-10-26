
#include "CUnitVector.hpp"
#include "CMatrix4x4.hpp"
#include "math_helper.hpp"

#include <glm/glm.hpp>
// #include <limits.h>
// #include <math.h>
#include <cmath>

namespace Yogi { namespace Graphics {


CUnitVector::CUnitVector()
        : inherited()
{
    normalize();
}

CUnitVector::CUnitVector( double x, double y, double z )
        : inherited( x, y, z )
{
    normalize();
}

CUnitVector::CUnitVector( const CUnitVector& r )
        : inherited( r )
{
    normalize();
}

CUnitVector::CUnitVector( const CVector& r )
        : inherited( r )
{
    normalize();
}

CUnitVector::CUnitVector( const CPoint& r )
        : inherited( r )
{
    normalize();
}

CUnitVector::CUnitVector( const glm::vec3& r )
        : inherited( r )
{
    normalize();
}

void
CUnitVector::set( double x, double y, double z )
{
    inherited::set( x, y, z );

    normalize();
}

void
CUnitVector::normalize()
{
    double dLen = getLength();
    if ( __DBL_EPSILON__ < ::abs( dLen ) )
    {
        x /= dLen;
        y /= dLen;
        z /= dLen;
    }
    else
    {
        x = 1.0;
        y = 0.0;
        z = 0.0;
    }
}


CVector
CUnitVector::scaleVector( double magnitude ) const
{
    double x_ = this->x * magnitude;
    double y_ = this->y * magnitude;
    double z_ = this->z * magnitude;

    return CVector( x_, y_, z_ );
}

//static
CUnitVector
CUnitVector::buildFromPitchAndYaw( double fPitch, double fYaw )
{
    // float cosPitch = fCosine( fPitch );
    // float sinPitch = fSine( fPitch );
    // float cosYaw = fCosine( fYaw );
    // float sinYaw = fSine( fYaw );
    CMatrix4x4 m = CMatrix4x4::buildFromPitchAndYaw( fPitch, fYaw );
    // double cosPitch = ::cos( fPitch );
    // double sinPitch = ::sin( fPitch );
    // double cosYaw = ::cos( fYaw );
    // double sinYaw = ::sin( fYaw );
    // double cosRoll = ::cos( 0.0 );
    // double sinRoll = ::sin( 0.0 );

    // CMatrix4x4 m(                 //
    // 		cosYaw,               //
    // 		sinYaw * sinPitch,    //
    // 		sinYaw * cosPitch,    //
    // 		0,                    //

    // 		0,            //
    // 		cosPitch,     //
    // 		-sinPitch,    //
    // 		0,            //

    // 		-sinYaw,              //
    // 		cosYaw * sinPitch,    //
    // 		cosYaw * cosPitch,    //
    // 		0,                    //

    // 		0, 0, 0, 1    //
    // );

    CUnitVector u = m * CVector( 1, 0, 0 );

    //
    // CUnitVector u( -cosPitch * sinYaw, sinPitch, -cosPitch * cosYaw );
    // CUnitVector u(                                               //
    // 		-sinPitch * cosYaw - cosPitch * sinRoll * sinYaw,    //
    // 		sinPitch * sinYaw - cosPitch * sinRoll * cosYaw,     //
    // 		cosPitch * cosRoll                                   //
    // 															 // cosYaw * cosPitch, //
    // 															 // sinYaw * cosPitch, //
    // 															 // sinPitch //
    // );
    return u;
}


}}  // namespace Yogi::Graphics
