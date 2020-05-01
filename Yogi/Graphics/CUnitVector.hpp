#ifndef HPP_CUNITVECTOR
#define HPP_CUNITVECTOR

#include "CVector.hpp"

namespace Yogi { namespace Graphics {

class CUnitVector : public CVector
{
public:
	// class lifecycle --------------------------
	CUnitVector();
	CUnitVector( double x, double y, double z );
	CUnitVector( const CUnitVector& r );
	CUnitVector( const CVector& r );
	CUnitVector( const CPoint& r );

public:
	// public functions -------------------------

	virtual void
	set( double x, double y, double z );

protected:
	// protected functions ----------------------

	void
	normalize();

private:
	// private types ----------------------------
	typedef CVector inherited;
};

}}    // namespace Yogi::Graphics


#endif    // HPP_CUNITVECTOR
