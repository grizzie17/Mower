
#include "Environment.hpp"

namespace Yogi { namespace Simulator {

Environment::Environment()
	: m_tOrigin()          //! < 0,0,0 origin
	, m_dRowSpacing( 1.0 ) //! < one meter spacing
	, m_dColSpacing( 1.0 ) //! < one meter spacing
	, m_nRows( 5 )
	, m_nCols( 5 )
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

}} // namespace Yogi::Simulator
