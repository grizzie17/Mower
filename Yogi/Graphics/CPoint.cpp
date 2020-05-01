
#include "CPoint.hpp"

namespace Yogi { namespace Graphics {

CPoint::CPoint( double x, double y, double z )
		: m_x( x )
		, m_y( y )
		, m_z( z )
{}

CPoint::CPoint( CPoint& r )
		: m_x( r.m_x )
		, m_y( r.m_y )
		, m_z( r.m_z )
{}

CPoint::CPoint()
		: m_x( 0.0 )
		, m_y( 0.0 )
		, m_z( 0.0 )
{}

CPoint::~CPoint()
{}

void
CPoint::set( double x, double y, double z )
{
	m_x = x;
	m_y = y;
	m_z = z;
}

void
CPoint::setX( double x )
{
	m_x = x;
}

void
CPoint::setY( double y )
{
	m_y = y;
}

void
CPoint::setZ( double z )
{
	m_z = z;
}

bool
CPoint::operator==( const CPoint& r ) const
{
	return m_x == r.m_x && m_y == r.m_y && m_z == r.m_z;
}


}}    // namespace Yogi::Graphics
