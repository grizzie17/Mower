//=========================================================
///	@file: Environment.cpp
//=========================================================

#include "Environment.hpp"

#define DTM_ROWS 5
#define DTM_COLS 5

namespace Yogi { namespace Simulator {

Environment::Environment()
	: m_tOrigin()          //! < 0,0,0 origin
	, m_dRowSpacing( 1.0 ) //! < one meter spacing
	, m_dColSpacing( 1.0 ) //! < one meter spacing
	, m_nRows( DTM_ROWS )
	, m_nCols( DTM_COLS )
{
	m_aDTM[0][0] = 0.0;
	m_aDTM[0][1] = 0.0;
	m_aDTM[0][2] = 0.0;
	m_aDTM[0][3] = 0.0;
	m_aDTM[0][4] = 0.0;

	m_aDTM[1][0] = 0.0;
	m_aDTM[1][1] = 0.0;
	m_aDTM[1][2] = 0.0;
	m_aDTM[1][3] = 0.0;
	m_aDTM[1][4] = 0.0;

	m_aDTM[2][0] = 0.0;
	m_aDTM[2][1] = 0.0;
	m_aDTM[2][2] = 0.0;
	m_aDTM[2][3] = 0.0;
	m_aDTM[2][4] = 0.0;

	m_aDTM[3][0] = 0.0;
	m_aDTM[3][1] = 0.0;
	m_aDTM[3][2] = 0.0;
	m_aDTM[3][3] = 0.0;
	m_aDTM[3][4] = 0.0;

	m_aDTM[4][0] = 0.0;
	m_aDTM[4][1] = 0.0;
	m_aDTM[4][2] = 0.0;
	m_aDTM[4][3] = 0.0;
	m_aDTM[4][4] = 0.0;
}

Environment::~Environment()
{}

void
Environment::display( VDrawPtr pDraw )
{
	double x = m_tOrigin.x;
	double x1 = m_tOrigin.x + m_dRowSpacing;
	double y = m_tOrigin.y;
	double y1 = m_tOrigin.y + m_dRowSpacing;
	for ( int i = 0; i < DTM_ROWS - 1; ++i )
	{
		pDraw->setFillColors( 0, 200, 0 );
		pDraw->beginTriangleStrip();
		for ( int j = 1; j < DTM_COLS; ++j )
		{
			pDraw->polypoint( x, y, m_aDTM[i][j - 1] );
			pDraw->polypoint( x, y1, m_aDTM[i][j] );
		}
		y = y1;
		y1 += m_dRowSpacing;
		pDraw->endTriangleStrip();
	}
}

}} // namespace Yogi::Simulator
