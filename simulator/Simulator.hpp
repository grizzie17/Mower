

#ifndef _HPP_Simulator_
#define _HPP_Simulator_

#include "Draw.hpp"
#include "Environment.hpp"

#define YMAX 700
#define XMAX ( YMAX * 3 / 2 )

namespace Yogi { namespace Simulator {

class Simulator
{
public:
	Simulator();
	virtual ~Simulator();

public:
	int
	main( int argc, char** argv );

protected:
	// GLUT callbacks

	static void
	callbackDisplay();
	static void
	callbackResize( int w, int h );

	static OpenGLDraw* g_pDraw;
	static Environment* g_pEnvironment;
	static HDC g_hDC;
};

}} // namespace Yogi::Simulator

#endif // _HPP_Simulator_