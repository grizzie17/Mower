//=========================================================
/// @file: Draw.hpp
///
/// Class for drawing to OpenGL
//=========================================================

#ifndef _HPP_Draw_
#define _HPP_Draw_

#include <GL/gl.h>
#include <GL/glu.h>
#include <errno.h>

#include "VDraw.hpp"

namespace Yogi { namespace Simulator {

class OpenGLDraw : public VDraw
{
public:
	OpenGLDraw();
	virtual ~OpenGLDraw();

public:
	errno_t
	initialize();

	//! bind DC and Window to draw object
	bool
	setHDC( HDC hDC, HWND hWindow );

	//!	start drawing to window
	bool
	beginDraw();

	//! complete drawing to window
	bool
	endDraw();

public: // VDraw
	//! add point/vertex to draw buffer
	//! must be bracketed by beginPolygon or similar
	virtual void
	polypoint( double x, //!< [in] x
		double y,        //!< [in] y
		double z         //!< [in] z
	);

	virtual void
	beginPolygon();
	virtual void
	endPolygon();

	virtual void
	beginTriangleStrip();
	virtual void
	endTriangleStrip();

protected:
	HDC m_hDC;   //!< MS-Windows DC
	HWND m_hWND; //!< MS-Windows Window Handle
	HGLRC m_hRC; //!< OpenGL Resource Context

private:
};

}} // namespace Yogi::Simulator

#endif // _HPP_Draw_
