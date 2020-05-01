//=========================================================
///	@file: Simulator.cpp
//=========================================================

#define WIN32_LEAN_AND_MEAN
#include "Simulator.hpp"

#include "Draw.hpp"
#include "Environment.hpp"

//#include <GL/glew.h>    // needs to be first of the GL headers

#include <GL/gl.h>     // OpenGL
#include <GL/glu.h>    // OpenGL utilities
//#include <GL/glut.h>

#include <iostream>
#include <sstream>
#include <stdio.h>
#include <windows.h>

namespace Yogi { namespace Simulator {


//===============================================
// Class Lifecycle
//===============================================
Simulator::Simulator( HINSTANCE hInstCurr, HINSTANCE hInstPrev, LPCSTR sCmdLine, int nCmdShow )
		: m_hInstance( hInstCurr )
		, m_hDC( 0 )
		, m_hWnd( 0 )
		, m_sTitle()
		, m_sCmdLine( sCmdLine )
		, m_nCmdShow( nCmdShow )
		, m_pDraw( 0 )
		, m_pEnvironment( 0 )
{}

Simulator::~Simulator()
{
	delete m_pDraw;
	delete m_pEnvironment;
	if ( m_hDC )
		ReleaseDC( m_hWnd, m_hDC );
	DestroyWindow( m_hWnd );
}

//===============================================
// Public Functions
//===============================================
int
Simulator::setup( LPCSTR sAppName )
{
	int result = 0;

	m_sTitle = sAppName;

	HWND hWnd = windowCreate( m_sTitle.c_str(), 0, 0, 600, 600 * 3 / 4, PFD_TYPE_RGBA, 0 );
	if ( hWnd )
	{
		m_hWnd = hWnd;
		m_hDC = GetDC( m_hWnd );
		m_pDraw = new OpenGLDraw( m_hInstance );
		if ( m_pDraw )
		{
			m_pDraw->initialize( m_hWnd, m_hDC );
		}
		ShowWindow( m_hWnd, m_nCmdShow );
		std::stringstream ss;
		ss << m_sTitle << ": " << glGetString( GL_RENDERER ) << " : "
		   << glGetString( GL_VERSION );
		m_pDraw->setWindowTitle( ss.str().c_str() );

		m_pEnvironment = new Environment;
	}

	return result;
}

int
Simulator::run()
{
	int result = 0;

	if ( m_hWnd )
	{
		HACCEL hAccelTable = NULL;
		MSG    msg = { 0 };

		LoadAccelerators( m_hInstance, "MowerAccel" );

		while ( TRUE == ::GetMessage( &msg, m_hWnd, 0, 0 ) )
		{
			if ( ! ::TranslateAccelerator( msg.hwnd, hAccelTable, &msg ) )
			{
				::TranslateMessage( &msg );
				::DispatchMessage( &msg );
			}
		}
		if ( hAccelTable )
			::DestroyAcceleratorTable( hAccelTable );

		// ::DestroyWindow( m_hWnd );
	}
	return result;
}

//===============================================
// Protected Functions
//===============================================

//static
LRESULT CALLBACK
Simulator::WndProcGlue( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam )
{
	Simulator* pThis = 0;

	switch ( message )
	{
	case WM_CREATE:
#if defined( WM_NCCREATE )
	case WM_NCCREATE:
#endif

		// this message is sent when a new window has just been
		// created. We associate its handle with its Simulator
		// instance.
		::SetWindowLongPtr(
				hWnd, GWLP_USERDATA, ( LONG_PTR )( LPCREATESTRUCT( lParam ) )->lpCreateParams );
		break;
	default:
		break;
	}
	pThis = (Simulator*)::GetWindowLongPtr( hWnd, GWLP_USERDATA );
	if ( pThis )
		return pThis->WndProc( hWnd, message, wParam, lParam );
	else
		return ::DefWindowProc( hWnd, message, wParam, lParam );
}

LRESULT
Simulator::WndProc( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam )
{
	LRESULT result = TRUE;
	int     x;
	int     y;

	static PAINTSTRUCT paint = { 0 };

	try
	{
		switch ( message )
		{
		case WM_CREATE:
#if defined( WM_NCCREATE )
		case WM_NCCREATE:
#endif
			onCreate( hWnd, wParam, lParam );
			break;
		case WM_DESTROY:
#if defined( WM_NCDESTROY )
		case WM_NCDESTROY:
#endif
		case WM_CLOSE:
			PostQuitMessage( 0 );
			break;
		case WM_PAINT:
			onPaint();
			// BeginPaint( hWnd, &paint );
			// EndPaint( hWnd, &paint );
			break;

		case WM_SIZE:
			onSize( (UINT)wParam, LOWORD( lParam ), HIWORD( lParam ) );
			PostMessage( hWnd, WM_PAINT, 0, 0 );
			break;

		case WM_CHAR:
			switch ( wParam )
			{
			case VK_ESCAPE:
				PostQuitMessage( 0 );
				break;
			}
			return 0;

		case WM_LBUTTONDOWN:
		case WM_RBUTTONDOWN:
			SetCapture( hWnd );
			x = LOWORD( lParam );
			y = HIWORD( lParam );
			// TODO: set state for PAN or ROTATE
			break;

		case WM_LBUTTONUP:
		case WM_RBUTTONUP:
			ReleaseCapture();
			// TODO: clear movement state
			break;

		case WM_MOUSEMOVE:
			break;

		default:
			break;
		}
		result = ::DefWindowProc( hWnd, message, wParam, lParam );
	}
	catch ( const std::exception& e )
	{
		std::cerr << e.what() << '\n';
	}

	return result;
}

// create window that will be passed to
// draw objects.
HWND
Simulator::windowCreate(
		LPCSTR sTitle, int x, int y, int width, int height, int type, int flags )
{
	HWND hWnd = 0;

	if ( m_hInstance )
	{
		WNDCLASS wc = { 0 };

		wc.style = CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
		wc.lpfnWndProc = (WNDPROC)WndProcGlue;
		wc.hInstance = m_hInstance;
		wc.hIcon = LoadIcon( NULL, IDI_WINLOGO );
		wc.hCursor = LoadCursor( NULL, IDC_ARROW );
		wc.lpszClassName = "OpenGL";

		DWORD dwStyle
				= WS_OVERLAPPEDWINDOW | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_MINIMIZEBOX;

		if ( RegisterClass( &wc ) )
		{
			RECT r = { x, y, width, height };
			AdjustWindowRect( &r, dwStyle, FALSE );
			width = r.right - r.left;
			height = r.bottom - r.top;
			x = GetSystemMetrics( SM_CXSCREEN ) / 2 - width / 2;
			y = GetSystemMetrics( SM_CYSCREEN ) / 2 - height / 2;
			hWnd = CreateWindowA( "OpenGL", sTitle, dwStyle, x, y, width, height, NULL, NULL,
					m_hInstance, this );
			if ( hWnd )
			{
				m_hWnd = hWnd;
				m_hDC = GetDC( hWnd );
				if ( m_hDC )
				{
					int                   pf;
					PIXELFORMATDESCRIPTOR pfd = { 0 };

					pfd.nSize = sizeof( pfd );
					pfd.nVersion = 1;
					pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER
							| flags;
					pfd.iPixelType = type;
					pfd.cColorBits = 32;
					pfd.cDepthBits = 24;
					pfd.cStencilBits = 8;

					pf = ChoosePixelFormat( m_hDC, &pfd );
					if ( pf )
					{
						SetPixelFormat( m_hDC, pf, &pfd );
						DescribePixelFormat( m_hDC, pf, sizeof( pfd ), &pfd );
					}
				}
			}
		}
	}

	return hWnd;
}

HWND
Simulator::createOpenGLWindow(
		LPCSTR sTitle, int x, int y, int nWidth, int nHeight, BYTE type, DWORD flags )
{
	HWND     hWnd = 0;
	WNDCLASS wc = { 0 };
	// int                   pf = 0;
	// PIXELFORMATDESCRIPTOR pfd = { 0 };
	if ( m_hInstance )
	{
		wc.style = CS_OWNDC;
		wc.lpfnWndProc = &Simulator::WndProcGlue;
		wc.cbClsExtra = 0;
		wc.cbWndExtra = 0;
		wc.hInstance = m_hInstance;
		wc.hIcon = LoadIcon( NULL, IDI_WINLOGO );
		wc.hCursor = NULL;
		wc.hbrBackground = ( HBRUSH )::GetStockObject( NULL_BRUSH );
		wc.lpszMenuName = 0;
		wc.lpszClassName = "OpenGL";

		if ( ! RegisterClass( &wc ) )
			return 0;

		hWnd = ::CreateWindow( "OpenGL", m_sTitle.c_str(),
				WS_OVERLAPPEDWINDOW | WS_CLIPSIBLINGS | WS_CLIPCHILDREN, x, y, nWidth, nHeight,
				NULL, NULL, m_hInstance, NULL );
		if ( ! hWnd )
			return 0;

		m_hWnd = hWnd;
		m_hDC = ::GetDC( hWnd );

		// pfd.nSize = sizeof( pfd );
		// pfd.nVersion = 1;
		// pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | flags;
		// pfd.iPixelType = type;
		// pfd.cColorBits = 32;

		// pf = ::ChoosePixelFormat( m_hDC, &pfd );
		// if ( 0 == pf )
		// 	return 0;

		// if ( FALSE == ::SetPixelFormat( m_hDC, pf, &pfd ) )
		// 	return 0;

		// ::DescribePixelFormat( m_hDC, pf, sizeof( pfd ), &pfd );
	}
	return hWnd;
}

void
Simulator::onPaint()
{
	if ( m_pDraw && m_pEnvironment )
	{
		if ( m_pDraw->beginDraw() )
		{
			m_pEnvironment->display( m_pDraw );
			m_pDraw->endDraw();
		}
	}
}

void
Simulator::onCreate( HWND hWnd, WPARAM wParam, LPARAM lParam )
{}

void
Simulator::onSize( UINT nType, int cx, int cy )
{
	if ( m_pDraw )
		m_pDraw->size( cx, cy );
	PostMessage( m_hWnd, WM_PAINT, 0, 0 );
}

//===============================================
// disabled Functions
//===============================================

#if 0     // disable
int
Simulator::main( int argc, char** argv )
{
	g_pEnvironment = new Environment;

	// init GLUT and create window
	glutInit( &argc, argv );
	glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH );
	glutInitWindowSize( XMAX, YMAX );
	glutCreateWindow( "MOWER Simulator" );

	if ( ! g_hDC )
	{
		g_hDC = wglGetCurrentDC();
		if ( ! g_hDC )
		{
			std::cerr << "Unable to retrieve current DC" << std::endl;
			return 1;
		}
	}

	if ( ! g_pDraw )
	{
		g_pDraw = new OpenGLDraw;
		if ( ! g_pDraw )
		{
			std::cerr << "Problem creating Draw Object" << std::endl;
			return 1;
		}
		g_pDraw->setHDC( g_hDC, 0 );
		g_pDraw->initialize();
	}

	glEnable( GL_DEPTH_TEST );

	// register callbacks
	glutDisplayFunc( callbackDisplay );
	glutReshapeFunc( callbackResize );

	// GLUT event cycle
	glutMainLoop();

	return 0;
}
#endif    // disable


}}    // namespace Yogi::Simulator
