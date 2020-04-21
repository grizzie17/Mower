//=========================================================
/// @file: VDraw.hpp
///
/// Interface for drawing to OpenGL
//=========================================================

#ifndef _HPP_VDraw_
#define _HPP_VDraw_

//#include "Interface.hpp"

namespace Yogi { namespace Simulator {

typedef struct VDraw* VDrawPtr;

//! interface
struct VDraw
{
	typedef struct Point
	{
		double x;
		double y;
		double z;

		Point()
				: x( 0 )
				, y( 0 )
				, z( 0 )
		{}
		Point( double _x, double _y, double _z )
				: x( _x )
				, y( _y )
				, z( _z )
		{}
	} Point;

	virtual void
	update( int ox, int nx, int oy, int ny )
			= 0;

	//!	add point/vertex to draw buffer.
	//!
	//! must be bracketed by begin/endXxxx function
	virtual void
	polypoint( double x,         //!< [in] x
			double    y,         //!< [in] y
			double    z = 0.0    //!< [in] z
			)
			= 0;

	//! begin/end polygon
	//!
	//! calling sequence:
	//!		beginPolygon();
	//!		polypoint( x, y, z );
	//!		polypoint( ... );
	//!		endPolygon();
	virtual void
	beginPolygon()
			= 0;
	virtual void
	endPolygon()
			= 0;

	virtual void
	beginTriangles()
			= 0;
	virtual void
	endTriangles()
			= 0;

	virtual void
	beginTriangleStrip()
			= 0;
	virtual void
	endTriangleStrip()
			= 0;

	virtual void
	beginQuadStrip()
			= 0;
	virtual void
	endQuadStrip()
			= 0;

	virtual void
	setColor( double r, double g, double b )
			= 0;
};

}}    // namespace Yogi::Simulator

#endif    //_HPP_VDraw_
