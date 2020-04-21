//=========================================================
/// @file: Draw.hpp
///
/// Class for drawing to OpenGL
//=========================================================

#ifndef _HPP_Draw_
#define _HPP_Draw_

#include "VDraw.hpp"

#include <GL/glu.h>
#include <errno.h>

namespace Yogi { namespace Simulator {

class OpenGLDraw : public VDraw
{
public:
	// class lifecycle  -------------------------
	OpenGLDraw( HINSTANCE hInstance );
	virtual ~OpenGLDraw();

public:
	// public types  ----------------------------

	// public functions  ------------------------

	// create and initialize window
	bool
	initialize( HWND hWnd, HDC hDC );


	//!	start drawing to window
	bool
	beginDraw();

	//! complete drawing to window
	bool
	endDraw();

	void
	update( int ox, int nx, int oy, int ny );

	bool
	size( int cx, int cy );

	bool
	setWindowTitle( const char* sNewTitle );

protected:
	// protected types  -------------------------

	// protected functions  ---------------------

	// protected data  --------------------------

	HINSTANCE   m_hInstance;
	HDC         m_hDC;     //!< MS-Windows DC
	HWND        m_hWnd;    //!< MS-Windows Window Handle
	HGLRC       m_hRC;     //!< OpenGL Resource Context
	PAINTSTRUCT m_tPaint;


public:
	// VDraw Interface --------------------------

	//! add point/vertex to draw buffer
	//! must be bracketed by beginPolygon or similar
	virtual void
	polypoint(                //! void
			double x,         //!< [in] x
			double y,         //!< [in] y
			double z = 0.0    //!< [in] z
	);


	virtual void
	beginPolygon();
	virtual void
	endPolygon();

	virtual void
	beginTriangles();
	virtual void
	endTriangles();

	virtual void
	beginTriangleStrip();
	virtual void
	endTriangleStrip();

	virtual void
	beginQuadStrip();
	virtual void
	endQuadStrip();

	virtual void
	setColor( double r, double g, double b );
};

}}    // namespace Yogi::Simulator

#endif    // _HPP_Draw_
