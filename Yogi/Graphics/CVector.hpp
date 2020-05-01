//===============================================
/// @file: Vector.hpp
///
/// define a class that supports a normalized
/// vector.
//===============================================

#ifndef H_VECTOR
#define H_VECTOR

#include "CPoint.hpp"

namespace Yogi { namespace Graphics {


class CVector : public CPoint
{
public:
	// class lifecycle ------------------------------
	CVector();
	CVector( double x, double y, double z );
	CVector( CVector& r );
	CVector( CPoint& r );
	~CVector();

public:
	// public functions -----------------------------

	virtual void
	set( double x, double y, double z );


protected:
	// protected functions --------------------------

	// protected data -------------------------------
	// double m_x;
	// double m_y;
	// double m_z;

private:
	typedef CPoint inherited;
};


}}    // namespace Yogi::Graphics


#endif    // H_VECTOR
