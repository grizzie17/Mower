//=========================================================
///	@file: WinMain.cpp
//=========================================================
#define WIN32_LEAN_AND_MEAN
#include "Simulator.hpp"

#include <iostream>
#include <stdio.h>
#include <windows.h>


const char APPLICATION_NAME[] = "Mower";

using namespace Yogi::Simulator;

static Simulator* g_pApplication = NULL;


int APIENTRY
WinMain(
		HINSTANCE hInstCurr, HINSTANCE hInstPrev, LPSTR sCmdLine, int nCmdShow )
{
	int result = 0;

	try
	{
		g_pApplication
				= new Simulator( hInstCurr, hInstPrev, sCmdLine, nCmdShow );
		if ( ! g_pApplication )
			return 1;

		g_pApplication->setup( APPLICATION_NAME );

		result = g_pApplication->run();

		delete g_pApplication;
	}
	catch ( const std::exception& e )
	{
		std::cerr << e.what() << std::endl;
	}
	return result;
}
