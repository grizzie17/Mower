
#include "CUnitVector.hpp"

#include <limits.h>
#include <math.h>

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

void
CUnitVector::set( double x, double y, double z )
{
	inherited::set( x, y, z );

	normalize();
}

void
CUnitVector::normalize()
{
	double dLen = sqrt( m_x * m_x + m_y * m_y + m_z * m_z );
	if ( __DBL_EPSILON__ < abs( dLen ) )
	{
		m_x /= dLen;
		m_y /= dLen;
		m_z /= dLen;
	}
	else
	{
		m_x = 1.0;
		m_y = 0.0;
		m_z = 0.0;
	}
}

}}    // namespace Yogi::Graphics
