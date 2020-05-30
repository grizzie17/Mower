
#include "CPoint.hpp"
#include "CVector.hpp"


namespace Yogi { namespace Graphics {

CPoint::CPoint()
		: inherited()
{}

CPoint::CPoint( double x_, double y_, double z_ )
		: inherited( x_, y_, z_ )
{}

CPoint::CPoint( const glm::vec3& pt )
		: inherited( pt.x, pt.y, pt.z )
{}

CPoint::CPoint( const CPoint& r )
		: inherited( r )
{}


CPoint::~CPoint()
{}

void
CPoint::setX( double x_ )
{
	this->x = x_;
}

void
CPoint::setY( double y_ )
{
	this->y = y_;
}

void
CPoint::setZ( double z_ )
{
	this->z = z_;
}

void
CPoint::addVector( const CVector& r )
{
	this->x += r.x;
	this->y += r.y;
	this->z += r.z;
}

void
CPoint::subtractVector( const CVector& r )
{
	this->x -= r.x;
	this->y -= r.y;
	this->z -= r.z;
}

const CPoint&
CPoint::operator+=( const CVector& r )
{
	addVector( r );
	return *this;
}

CPoint
CPoint::operator+( const CVector& r ) const
{
	CPoint p( *this );
	p.addVector( r );
	return p;
}

const CPoint&
CPoint::operator-=( const CVector& r )
{
	subtractVector( r );
	return *this;
}

CPoint
CPoint::operator-( const CVector& r ) const
{
	CPoint p( *this );
	p.subtractVector( r );
	return p;
}

const CPoint&
CPoint::operator+=( double c )
{
	this->x += c;
	this->y += c;
	this->z += c;
	return *this;
}

CVector
CPoint::operator-( const CPoint& r ) const
{
	return CVector( this->x - r.x, this->y - r.y, this->z - r.z );
}

// bool
// CPoint::operator==( const CPoint& r ) const
// {
// 	return this->x == r.x && this->y == r.y && this->z == r.z;
// }


}}    // namespace Yogi::Graphics
