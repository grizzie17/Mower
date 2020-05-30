//=========================================================
/// @file: VDraw.hpp
///
/// Interface for drawing to OpenGL
//=========================================================

#ifndef _HPP_VDraw_
#define _HPP_VDraw_

#include "CPoint.hpp"

//#include "Interface.hpp"

namespace Yogi { namespace Graphics {


//! interface
struct VDraw
{
    virtual void
    pushMatrix()
            = 0;

    virtual void
    popMatrix()
            = 0;


    virtual void
    update( int ox, int nx, int oy, int ny )
            = 0;

    virtual void
    enableLights()
            = 0;

    virtual void
    placeLight( unsigned id, const CPoint& position )
            = 0;

    virtual void
    normal( const CUnitVector& uv )
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
    beginLineStrip()
            = 0;
    virtual void
    endLineStrip()
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

}}    // namespace Yogi::Graphics

#endif    //_HPP_VDraw_
