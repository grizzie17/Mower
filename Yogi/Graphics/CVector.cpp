
#include "CVector.hpp"

#include <limits.h>
#include <math.h>


namespace Yogi { namespace Graphics {

CVector::CVector()
		: inherited( 1.0, 0.0, 0.0 )
{}

CVector::CVector( double x, double y, double z )
		: inherited( x, y, z )
{}

CVector::CVector( CVector& r )
		: inherited( r.m_x, r.m_y, r.m_z )
{}

CVector::CVector( CPoint& r )
		: inherited( r )
{}

CVector::~CVector()
{}

void
CVector::set( double x, double y, double z )
{
	inherited::set( x, y, z );
}


}}    // namespace Yogi::Graphics