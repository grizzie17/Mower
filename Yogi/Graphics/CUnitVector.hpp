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
    CUnitVector( const glm::vec3& r );

public:
    // public functions -------------------------

    virtual void
    set( double x, double y, double z ) override;
    const CUnitVector&
    operator=( const CVector& r );

    CVector
    operator*( double magnitude ) const;


    CVector
    scaleVector( double magnitude ) const;

    static CUnitVector
    buildFromPitchAndYaw( double fPitch, double fYaw );

protected:
    // protected functions ----------------------

    void
    normalize();

private:
    // private types ----------------------------
    typedef CVector inherited;
};


inline const CUnitVector&
CUnitVector::operator=( const CVector& r )
{
    set( r.x, r.y, r.z );
    return *this;
}


inline CVector
CUnitVector::operator*( double magnitude ) const
{
    return scaleVector( magnitude );
}


}}  // namespace Yogi::Graphics


#endif  // HPP_CUNITVECTOR
