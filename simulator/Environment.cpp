//=========================================================
///	@file: Environment.cpp
//=========================================================

#include "Environment.hpp"

#define DTM_ROWS 5
#define DTM_COLS 5

namespace Yogi { namespace Simulator {

Environment::Environment()
		: m_tOrigin()             //! < 0,0,0 origin
		, m_dRowSpacing( 1.0 )    //! < one meter spacing
		, m_dColSpacing( 1.0 )    //! < one meter spacing
		, m_nRows( DTM_ROWS )
		, m_nCols( DTM_COLS )
{
	for ( int i = 0; i < DTM_ROWS; ++i )
	{
		for ( int j = 0; j < DTM_COLS; ++j )
			m_aDTM[i][j] = 0.0;
	}
}

Environment::~Environment()
{}

void
Environment::display( VDrawPtr pDraw )
{
	// double x = m_tOrigin.x;
	// double x1 = m_tOrigin.x + m_dRowSpacing;
	// double y = m_tOrigin.y;
	// double y1 = m_tOrigin.y + m_dRowSpacing;
	// for ( int i = 0; i < DTM_ROWS - 1; ++i )
	// {
	// 	pDraw->setColor( 0, 0.80, 0 );
	// 	pDraw->beginTriangleStrip();
	// 	for ( int j = 1; j < DTM_COLS; ++j )
	// 	{
	// 		pDraw->polypoint( x, y, m_aDTM[i][j - 1] );
	// 		pDraw->polypoint( x, y1, m_aDTM[i][j] );
	// 	}
	// 	y = y1;
	// 	y1 += m_dRowSpacing;
	// 	pDraw->endTriangleStrip();
	// }
	pDraw->beginTriangles();

#define TOP                     \
	pDraw->setColor( 1, 0, 0 ); \
	pDraw->polypoint( 0, 1, 0 )
#define FR                      \
	pDraw->setColor( 0, 1, 0 ); \
	pDraw->polypoint( 1, -1, 1 )
#define FL                      \
	pDraw->setColor( 0, 0, 1 ); \
	pDraw->polypoint( -1, -1, 1 )
#define BR                      \
	pDraw->setColor( 0, 0, 1 ); \
	pDraw->polypoint( 1, -1, -1 )
#define BL                      \
	pDraw->setColor( 0, 1, 0 ); \
	pDraw->polypoint( -1, -1, -1 )

	TOP;
	FL;
	FR;
	TOP;
	FR;
	BR;
	TOP;
	BR;
	BL;
	TOP;
	BL;
	FL;
	FR;
	FL;
	BL;
	BL;
	BR;
	FR;

	// pDraw->setColor( 1.0, 0, 0 );    // 1
	// pDraw->polypoint( 0, 1, 0 );
	// pDraw->setColor( 0, 1.0, 0 );    // 2
	// pDraw->polypoint( -1, -1 );
	// pDraw->setColor( 0, 0, 1.0 );    // 3
	// pDraw->polypoint( 1, -1, 0 );
	pDraw->endTriangles();
}

}}    // namespace Yogi::Simulator
