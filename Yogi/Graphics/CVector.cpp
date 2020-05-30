
#include "CVector.hpp"
#include "math_helper.hpp"

#include <limits.h>
#include <math.h>


namespace Yogi { namespace Graphics {

CVector::CVector()
		: inherited( 1.0f, 0.0f, 0.0f )
{}

CVector::CVector( double x, double y, double z )
		: inherited( x, y, z )
{}

CVector::CVector( const CVector& r )
		: inherited( r )
{}

CVector::CVector( const CPoint& r )
		: inherited( r )
{}

CVector::CVector( const glm::vec3& r )
		: inherited( r.x, r.y, r.z )
{}

CVector::~CVector()
{}

// void
// CVector::set( double x, double y, double z )
// {
// 	inherited::set( x, y, z );
// }

double
CVector::getLength() const
{
	return ::sqrt( this->x * this->x + this->y * this->y + this->z * this->z );
}

// void
// CVector::addVector( const CVector& v )
// {
// 	this->x += v.x;
// 	this->y += v.y;
// 	this->z += v.z;
// }

// CVector
// CVector::operator+( const CVector& r ) const
// {
// 	CVector v( *this );
// 	v.addVector( r );
// 	return v;
// }
// const CVector&
// CVector::operator+=( const CVector& r )
// {
// 	addVector( r );
// 	return *this;
// }

CVector
CVector::operator-( const CVector& r ) const
{
	CVector v( *this );
	v.subtractVector( r );
	return v;
}

void
CVector::negateVector()
{
	x = -x;
	y = -y;
	z = -z;
}

CVector
CVector::operator-() const
{
	CVector v( *this );
	v.negateVector();
	return v;
}


double
CVector::dotProduct( const CVector& v ) const
{
	return this->x * v.x + this->y * v.y + this->z * v.z;
}

double
CVector::getAngleBetween( const CVector& v ) const
{
	double thisLen = getLength();
	double thatLen = v.getLength();
	if ( 0.0 < thisLen && 0.0 < thatLen )
	{
		double dot = dotProduct( v );
		double mag = thisLen * thatLen;
		double a = ::acos( dot / mag );
		return a;
	}
	else
	{
		return -999;
	}
}

void
CVector::getPitchAndYaw( double* pPitch, double* pYaw ) const
{
	double len = getLength();
	if ( 0 < len )
	{
		double distance = ::sqrt( this->x * this->x + this->y * this->y );
		double fPitch = ::asin( this->z / distance );
		double fYaw = ::atan2( this->x, this->y );
		*pPitch = fPitch;
		*pYaw = fYaw;
	}
	else
	{
		*pPitch = 0;
		*pYaw = 0;
	}
}


void
CVector::get2AnglesBetween( const CVector& v, double* pPitch, double* pYaw ) const
{
	*pPitch = -999.0;
	*pYaw = -999.0;

	// double ang = getAngleBetween( v );
	// if ( -360.0 < ang )
	// {}
	// double thisLen = getLength();
	// double thatLen = v.getLength();
	// if ( 0.0 < thisLen && 0.0 < thatLen )
	// {
	// 	// get angle in the X-Y plane
	// 	CVector tXY( this->x, this->y, 0.0 );
	// 	CVector vXY( v.x, v.y, 0.0 );

	// 	double dYaw = tXY.getAngleBetween( vXY );
	// 	if ( degreesFromRadians( dYaw ) < -360.0 )
	// 		return;
	// }
}


}}    // namespace Yogi::Graphics