//=========================================================
///	@file: Draw.cpp
//=========================================================
#define WIN32_LEAN_AND_MEAN
#include "Draw.hpp"

#include <GL/gl.h>
#include <GL/glut.h>

namespace Yogi { namespace Graphics {


OpenGLDraw::OpenGLDraw( HINSTANCE hInst )
        : m_hInstance( hInst )
        , m_hDC( 0 )     //!< Device Context
        , m_hWnd( 0 )    //!< Window Handle
        , m_hRC( 0 )     //!< GL resource handle
        , m_tScreenSize( 800, 800 * 3 / 4 )
        , m_pCamera( 0 )
        , m_nStackMatrix( 0 )
{
    ::memset( &m_tPaint, 0, sizeof( m_tPaint ) );
}

OpenGLDraw::~OpenGLDraw()
{
    wglMakeCurrent( NULL, NULL );
    if ( m_hRC )
        wglDeleteContext( m_hRC );
    m_hRC = 0;
    m_hDC = 0;
    m_pCamera = 0;
}

bool
OpenGLDraw::initialize( HWND hWnd, HDC hDC )
{
    bool bResult = false;

    if ( m_hInstance )
    {
        m_hWnd = hWnd;
        m_hDC = hDC;

        m_hRC = wglCreateContext( m_hDC );
        if ( m_hRC )
        {
            if ( TRUE == wglMakeCurrent( m_hDC, m_hRC ) )
            {
                glEnable( GL_DEPTH_TEST );
                bResult = true;
            }
        }
    }

    return bResult;
#if 0
	glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );
	glClear(
			GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT );
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();

	return 0;
#endif    // 0
}

#if 0
bool
OpenGLDraw::setHDC( HDC hDC, HWND hWindow )
{
	m_hDC = hDC;
	m_hWnd = hWindow;

	PIXELFORMATDESCRIPTOR  pfd;
	PIXELFORMATDESCRIPTOR* ppfd;
	int                    pixelformat;

	ppfd = &pfd;

	ppfd->nSize = sizeof( pfd );
	ppfd->nVersion = 1;
	ppfd->dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL;
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
	DescribePixelFormat( m_hDC, pixelformat, sizeof( pfd ), ppfd );
	if ( ! m_hRC )
		m_hRC = wglCreateContext( m_hDC );
	wglMakeCurrent( m_hDC, m_hRC );
	return true;
}
#endif    // 0

void
OpenGLDraw::setCamera( CCamera* pCamera )
{
    m_pCamera = pCamera;
}


void
OpenGLDraw::pushMatrix()
{
    glPushMatrix();
    ++m_nStackMatrix;
}

void
OpenGLDraw::popMatrix()
{
    if ( 0 < m_nStackMatrix )
    {
        glPopMatrix();
        --m_nStackMatrix;
    }
}

void
OpenGLDraw::update( int ox, int nx, int oy, int ny )
{
    int dx = ox - nx;
    int dy = oy - oy;

    // NEEDS_WORK: finish implementation
}

void
OpenGLDraw::enableLights()
{
    glEnable( GL_LIGHTING );
}

void
OpenGLDraw::placeLight( unsigned id, const CPoint& position )
{
    GLenum e;
    if ( id < 0 || 7 < id )
        id = 0;
    e = GL_LIGHT0 | id;
    GLfloat ambient[] = { 0, 1, 0, 1 };
    glLightfv( e, GL_AMBIENT, ambient );
    glLightfv( e, GL_DIFFUSE, ambient );
    GLfloat ipos[]
            = { GLfloat( position.x ), GLfloat( position.y ), GLfloat( position.z ), 0.0f };
    glLightfv( e, GL_POSITION, ipos );
    glEnable( e );
}

bool
OpenGLDraw::beginDraw()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    m_pCamera->viewRender();
    glEnable( GL_DEPTH_TEST );
    return true;
}

bool
OpenGLDraw::endDraw()
{
    glFlush();
    SwapBuffers( m_hDC );
    return true;
}

bool
OpenGLDraw::size( int cx, int cy )
{
    // m_tScreenSize.x = cx;
    // m_tScreenSize.y = cy;

    // glViewport( 0, 0, cx, cy );
    // glMatrixMode( GL_PROJECTION );
    // glLoadIdentity();
    // if ( cy < cx )
    // {
    // 	GLfloat aspect = (GLfloat)cx / (GLfloat)cy;
    // 	glFrustum( -0.5F * aspect, 0.5F * aspect, -0.5F, 0.5F, 1.0F, 3.0F );
    // }
    // else
    // {
    // 	GLfloat aspect = (GLfloat)cy / (GLfloat)cx;
    // 	glFrustum( -0.5F, 0.5F, -0.5F * aspect, 0.5F * aspect, 1.0F, 3.0F );
    // }

    // gluPerspective( 60.0, (GLdouble)cx / (GLdouble)cy, 0.001, 100.0 );
    // glMatrixMode( GL_MODELVIEW );
    // glLoadIdentity();
    // glTranslatef( 0.0f, 0.0f, -3.0f );
    return true;
}

bool
OpenGLDraw::setWindowTitle( const char* sNewTitle )
{
    return TRUE == SetWindowTextA( m_hWnd, sNewTitle );
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
OpenGLDraw::beginLineStrip()
{
    glBegin( GL_LINE_STRIP );
}

void
OpenGLDraw::endLineStrip()
{
    glEnd();
}

void
OpenGLDraw::polypoint( double x, double y, double z )
{
    glVertex3d( (GLdouble)x, (GLdouble)y, (GLdouble)z );
}

void
OpenGLDraw::beginTriangles()
{
    glBegin( GL_TRIANGLES );
}

void
OpenGLDraw::endTriangles()
{
    glEnd();
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

void
OpenGLDraw::beginQuadStrip()
{
    glBegin( GL_QUAD_STRIP );
}

void
OpenGLDraw::endQuadStrip()
{
    glEnd();
}

void
OpenGLDraw::setColor( double r, double g, double b )
{
    glColor3f( GLfloat( r ), GLfloat( g ), GLfloat( b ) );
}

}}    // namespace Yogi::Graphics
