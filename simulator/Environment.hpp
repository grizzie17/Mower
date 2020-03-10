//=========================================================
///	@file: Environment.hpp
//=========================================================
#ifndef _HPP_ENVIRONMENT_
#define _HPP_ENVIRONMENT_

#include "VDraw.hpp"

namespace Yogi { namespace Simulator {

class Environment
{
public:
	Environment();
	virtual ~Environment();

public:
	void
	display( VDrawPtr pDraw );

protected:
	VDraw::Point m_tOrigin;
	double m_dRowSpacing;
	double m_dColSpacing;
	int m_nRows;
	int m_nCols;
	double m_aDTM[5][5];
};

}} // namespace Yogi::Simulator

#endif // _HPP_ENVIRONMENT_
