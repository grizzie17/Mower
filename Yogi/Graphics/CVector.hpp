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
	CVector( const CVector& r );
	CVector( const CPoint& r );
	CVector( const glm::vec3& r );
	~CVector();

public:
	// public functions -----------------------------

	// virtual void
	// set( double x, double y, double z );

	/// magnitude
	double
	getLength() const;

	// void
	// addVector( const CVector& v );
	// CVector
	// operator+( const CVector& v ) const;
	// const CVector&
	// operator+=( const CVector& v );

	CVector
	operator-( const CVector& r ) const;

	// void
	// subtractVector( const CVector );

	void
	negateVector();
	CVector
	operator-() const;


	double
	dotProduct( const CVector& v ) const;

	double
	getAngleBetween( const CVector& v ) const;

	// pitch is relative to z-axis
	void
	getPitchAndYaw( double* pPitch, double* pYaw ) const;

	void
	get2AnglesBetween( const CVector& v, double* pPitch, double* pYaw ) const;


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
