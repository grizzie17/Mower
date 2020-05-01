//=========================================================
///	@file: Simulator.hpp
//=========================================================


#ifndef HPP_Simulator
#define HPP_Simulator

#define WIN32_LEAN_AND_MEAN

#include "Draw.hpp"
#include "Environment.hpp"

#include <string>
#include <windows.h>

#define YMAX 700
#define XMAX ( YMAX * 3 / 2 )

namespace Yogi { namespace Simulator {

class Simulator
{
	// class lifecycle  -------------------------
public:
	Simulator( HINSTANCE hInstCurr, HINSTANCE hInstPrev, LPCSTR sCmdLine, int nCmdShow );
	virtual ~Simulator();

public:
	// public types  ----------------------------

	// public functions  ------------------------

	int
	setup( LPCSTR sAppName );

	int
	run();

	// bool
	// initInstance( HINSTANCE hInst, LPSTR sAppName );

protected:
	// protected types  -------------------------

	// protected functions  ---------------------

	//-- Windows Processors
	static LRESULT CALLBACK
	WndProcGlue( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam );
	LRESULT
	WndProc( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam );

	void
	onCreate( HWND hWnd, WPARAM wParam, LPARAM lParam );

	void
	onPaint();

	void
	onSize( UINT nType, int cx, int cy );


	HWND
	windowCreate( LPCSTR sTitle, int x, int y, int width, int height, int type, int flags );

	HWND
	createOpenGLWindow(
			const char* sTitle, int x, int y, int nWidth, int nHeight, BYTE type, DWORD flags );

	// protected data  --------------------------

	HINSTANCE   m_hInstance;
	HDC         m_hDC;
	HWND        m_hWnd;
	std::string m_sTitle;
	std::string m_sCmdLine;
	int         m_nCmdShow;

	OpenGLDraw*  m_pDraw;
	Environment* m_pEnvironment;
};

}}    // namespace Yogi::Simulator

#endif    // HPP_Simulator
