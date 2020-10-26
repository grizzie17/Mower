#ifndef HPP_CMATRIX4X4
#define HPP_CMATRIX4X4

#include "CPoint.hpp"
#include "CVector.hpp"


//#include <glm/mat4x4.hpp>
// #include <glm/vec3.hpp>


namespace Yogi { namespace Graphics {


/*
	Definition

	x0  x1  x2  x3
	y0  y1  y2  y3
	z0  z1  z2  z3
	w0  w1  w2  w3

	Scale

	x0  0   0   0
	0   y1  0   0
	0   0   z2  0
	0   0   0   1

	Rotation

	r00 r01 r02 0
	r10 r11 r12 0
	r20 r21 r22 0
	0   0   0   1

	Translation

	1   0   0   t0
	0   1   0   t1
	0   0   1   t2
	0   0   0   1
*/


class CMatrix4x4
{
    // class lifecycle --------------------------
public:
    CMatrix4x4();
    CMatrix4x4( const CMatrix4x4& r );
    CMatrix4x4( double m0, double m1, double m2, double m3,  //
            double m4, double m5, double m6, double m7,      //
            double m8, double m9, double m10, double m11,    //
            double m12, double m13, double m14, double m15 );
    CMatrix4x4( double diag );
    //CMatrix4x4( const glm::mat4x4& m );
    ~CMatrix4x4();

public:
    // public types -----------------------------

    // allow for double indexing: matrix[row][col]
    class Row
    {
    public:
        Row( CMatrix4x4& mat, unsigned row );

        double&
        operator[]( unsigned col );
        double
        operator[]( unsigned col ) const;

        CMatrix4x4& m_that;
        unsigned    m_row;
    };
    class ConstRow
    {
    public:
        ConstRow( const CMatrix4x4& mat, unsigned index );

        double
        operator[]( unsigned col ) const;

        const CMatrix4x4& m_that;
        unsigned          m_row;
    };

    Row
    operator[]( unsigned row );

    ConstRow
    operator[]( unsigned row ) const;


    // public functions -------------------------

    const CMatrix4x4&
    set( const CMatrix4x4& r );
    const CMatrix4x4&
    operator=( const CMatrix4x4& r );

    double
    getValue( unsigned row, unsigned col ) const;
    double&
    getRef( unsigned row, unsigned col );

    glm::mat4x4
    getMat4x4() const;

    bool
    equals( const CMatrix4x4& r ) const;
    bool
    operator==( const CMatrix4x4& r ) const;

    /// adjust matrix to shift/translate
    void
    translate( const CVector& r );
    void
    operator+=( const CVector& r );

    /*
	[ 01 02 03 04 ] Transpose:	[ 01 05 09 13 ]
	[ 05 06 07 08 ]				[ 02 06 10 14 ]
	[ 09 10 11 12 ]				[ 03 07 11 15 ]
	[ 13 14 15 16 ]				[ 04 08 12 16 ]
	*/
    CMatrix4x4
    transpose() const;

    double
    determinant() const;

    CPoint
    transformPoint( const CPoint& p ) const;
    CPoint
    operator*( const CPoint& p ) const;

    CMatrix4x4
    multiplyMatrix( const CMatrix4x4& m ) const;
    CMatrix4x4
    operator*( const CMatrix4x4& m ) const;

    void
    multiplyToSelf( const CMatrix4x4& m );
    void
    operator*=( const CMatrix4x4& m );

    static CMatrix4x4
    buildScale( double x, double y, double z );
    static CMatrix4x4
    buildScale( double scale );

    static CMatrix4x4
    buildTranslate( double x, double y, double z );
    static CMatrix4x4
    buildTranslate( const CVector& r );

    static CMatrix4x4
    buildRotateAroundXAxis( double angle );

    static CMatrix4x4
    buildRotateAroundYAxis( double angle );

    static CMatrix4x4
    buildRotateAroundZAxis( double angle );

    static CMatrix4x4
    buildFromPitchAndYaw( double pitch, double yaw );


protected:
    double m_m[4][4];  // [row][col]

private:
    // private types ----------------------------
    //typedef glm::mat4x4 inherited;
};


inline CMatrix4x4::Row::Row( CMatrix4x4& mat, unsigned row )
        : m_that( mat )
        , m_row( row )
{}

inline double&
CMatrix4x4::Row::operator[]( unsigned col )
{
    return m_that.getRef( m_row, col );
}
inline double
CMatrix4x4::Row::operator[]( unsigned col ) const
{
    return m_that.getValue( m_row, col );
}


inline CMatrix4x4::ConstRow::ConstRow( const CMatrix4x4& mat, unsigned index )
        : m_that( mat )
        , m_row( index )
{}

inline double
CMatrix4x4::ConstRow::operator[]( unsigned col ) const
{
    return m_that.getValue( m_row, col );
}

inline CMatrix4x4::Row
CMatrix4x4::operator[]( unsigned row )
{
    return Row( *this, row );
}

inline CMatrix4x4::ConstRow
CMatrix4x4::operator[]( unsigned row ) const
{
    return ConstRow( *this, row );
}


inline const CMatrix4x4&
CMatrix4x4::operator=( const CMatrix4x4& r )
{
    return set( r );
}

inline bool
CMatrix4x4::operator==( const CMatrix4x4& r ) const
{
    return equals( r );
}

inline CPoint
CMatrix4x4::operator*( const CPoint& p ) const
{
    return transformPoint( p );
}

inline CMatrix4x4
CMatrix4x4::operator*( const CMatrix4x4& m ) const
{
    return multiplyMatrix( m );
}

inline void
CMatrix4x4::operator*=( const CMatrix4x4& m )
{
    multiplyToSelf( m );
}

inline void
CMatrix4x4::operator+=( const CVector& r )
{
    translate( r );
}


}}  // namespace Yogi::Graphics


#endif  // HPP_CMATRIX4X4
