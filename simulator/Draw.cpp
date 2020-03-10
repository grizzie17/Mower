
#include "Draw.hpp"

#include <GL/gl.h>

namespace Yogi { namespace Simulator {

OpenGLDraw::OpenGLDraw()
	: m_hDC( 0 )  //!< Window DC
	, m_hWND( 0 ) //!< Window Handle
	, m_hRC( 0 )  //!< GL resource handle
{}

OpenGLDraw::~OpenGLDraw()
{
	if ( m_hRC )
		wglDeleteContext( m_hRC );
	m_hRC = 0;
}

errno_t
OpenGLDraw::initialize()
{}

bool
OpenGLDraw::setHDC( HDC hDC, HWND hWindow )
{
	m_hDC = hDC;
	m_hWND = hWindow;

	PIXELFORMATDESCRIPTOR pfd, *ppfd;
	int pixelformat;

	ppfd = &pfd;

	ppfd->nSize = sizeof( PIXELFORMATDESCRIPTOR );
	ppfd->nVersion = 1;
	ppfd->dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	// ppfd->dwLayerMask = PFD_MAIN_PLANE;
	ppfd->iPixelType = PFD_TYPE_RGBA;
	ppfd->cColorBits = 24;
	ppfd->cDepthBits = 16;
	ppfd->cAccumBits = 0;
	ppfd->cStencilBits = 0;
	ppfd->iLayerType = PFD_MAIN_PLANE;

	pixelformat = ChoosePixelFormat( m_hDC, ppfd );
	if ( pixelformat )
		SetPixelFormat( m_hDC, pixelformat, ppfd );
	if ( ! m_hRC )
		m_hRC = wglCreateContext( m_hDC );
}

bool
OpenGLDraw::beginDraw()
{
	glClear( GL_COLOR_BUFFER_BIT );
	return true;
}

bool
OpenGLDraw::endDraw()
{
	glFlush();
	return true;
}

//=========================================================
//	VDraw
//=========================================================

void
OpenGLDraw::beginPolygon()
{
	glBegin( GL_POLYGON );
}

void
OpenGLDraw::endPolygon()
{
	glEnd();
}

void
OpenGLDraw::polypoint( double x, double y, double z )
{
	glVertex3d( (GLdouble)x, (GLdouble)y, (GLdouble)z );
}

void
OpenGLDraw::beginTriangleStrip()
{
	glBegin( GL_TRIANGLE_STRIP );
}

void
OpenGLDraw::endTriangleStrip()
{
	glEnd();
}

}} // namespace Yogi::Simulator
