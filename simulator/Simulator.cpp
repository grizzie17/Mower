
#include "Simulator.hpp"
#include "Environment.hpp"

#include <GL/glut.h>
#include <iostream>

namespace Yogi { namespace Simulator {

OpenGLDraw* Simulator::g_pDraw = 0;
Environment* Simulator::g_pEnvironment = 0;
HDC Simulator::g_hDC = 0;

Simulator::Simulator()
{}

Simulator::~Simulator()
{}

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

//=========================================================
// static GLUT callback functions
//=========================================================
void
Simulator::callbackDisplay()
{
	if ( ! g_pDraw )
	{
		std::cerr << "Unable to process display call; no draw object available" << std::endl;
		return;
	}

	g_pDraw->beginDraw();
	g_pEnvironment->display( g_pDraw );
	g_pDraw->endDraw();
}

void
Simulator::callbackResize( int w, int h )
{
	if ( 0 == h )
		h = 1;
	float fRatio = 1.0 * w / h;
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();

	glViewport( 0, 0, w, h );

	gluPerspective( 45, fRatio, 1, 1000 );
	glMatrixMode( GL_MODELVIEW );
}

}} // namespace Yogi::Simulator