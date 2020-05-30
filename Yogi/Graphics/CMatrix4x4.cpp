
#include "CMatrix4x4.hpp"
#include "math_helper.hpp"

#define _USE_MATH_DEFINES
//#include <cmath>
#include <math.h>

//#include "glm/gtc/matrix_transform.hpp"

using namespace Yogi::Utilities;
namespace Yogi { namespace Graphics {


//===============================================
// class lifecycle
//===============================================
CMatrix4x4::CMatrix4x4()
        : m_m {
            1, 0, 0, 0,    //
            0, 1, 0, 0,    //
            0, 0, 1, 0,    //
            0, 0, 0, 1     //
        }
{}

CMatrix4x4::CMatrix4x4( const CMatrix4x4& r )
        : m_m {
            r[0][0], r[0][1], r[0][2], r[0][3],    //
            r[1][0], r[1][1], r[1][2], r[1][3],    //
            r[2][0], r[2][1], r[2][2], r[2][3],    //
            r[3][0], r[3][1], r[3][2], r[3][3]     //
        }
{}

CMatrix4x4::CMatrix4x4(                                   //
        double m0, double m1, double m2, double m3,       //
        double m4, double m5, double m6, double m7,       //
        double m8, double m9, double m10, double m11,     //
        double m12, double m13, double m14, double m15    //
        )
        : m_m {
            m0, m1, m2, m3,       //
            m4, m5, m6, m7,       //
            m8, m9, m10, m11,     //
            m12, m13, m14, m15    //
        }
{}

CMatrix4x4::CMatrix4x4( const glm::mat4x4& r )
        : m_m {
            r[0][0], r[0][1], r[0][2], r[0][3],    //
            r[1][0], r[1][1], r[1][2], r[1][3],    //
            r[2][0], r[2][1], r[2][2], r[2][3],    //
            r[3][0], r[3][1], r[3][2], r[3][3]     //
        }
{}

CMatrix4x4::CMatrix4x4( double diag )
        : m_m {
            diag, 0, 0, 0,    //
            0, diag, 0, 0,    //
            0, 0, diag, 0,    //
            0, 0, 0, 1        //
        }
{}

CMatrix4x4::~CMatrix4x4()
{}


//===============================================
// public
//===============================================
void
CMatrix4x4::set( const CMatrix4x4& r )
{
    m_m[0][0] = r.m_m[0][0];
    m_m[0][1] = r.m_m[0][1];
    m_m[0][2] = r.m_m[0][2];
    m_m[0][3] = r.m_m[0][3];

    m_m[1][0] = r.m_m[1][0];
    m_m[1][1] = r.m_m[1][1];
    m_m[1][2] = r.m_m[1][2];
    m_m[1][3] = r.m_m[1][3];

    m_m[2][0] = r.m_m[2][0];
    m_m[2][1] = r.m_m[2][1];
    m_m[2][2] = r.m_m[2][2];
    m_m[2][3] = r.m_m[2][3];

    m_m[3][0] = r.m_m[3][0];
    m_m[3][1] = r.m_m[3][1];
    m_m[3][2] = r.m_m[3][2];
    m_m[3][3] = r.m_m[3][3];
}


bool
CMatrix4x4::equals( const CMatrix4x4& r ) const
{
    // clang-format off
	return m_m[0][0] == r.m_m[0][0]    //
		&& m_m[0][1] == r.m_m[0][1]    //
		&& m_m[0][2] == r.m_m[0][2]    //
		&& m_m[0][3] == r.m_m[0][3]    //

		&& m_m[1][0] == r.m_m[1][0]    //
		&& m_m[1][1] == r.m_m[1][1]    //
		&& m_m[1][2] == r.m_m[1][2]    //
		&& m_m[1][3] == r.m_m[1][3]    //

		&& m_m[2][0] == r.m_m[2][0]    //
		&& m_m[2][1] == r.m_m[2][1]    //
		&& m_m[2][2] == r.m_m[2][2]    //
		&& m_m[2][3] == r.m_m[2][3]    //

		&& m_m[3][0] == r.m_m[3][0]    //
		&& m_m[3][1] == r.m_m[3][1]    //
		&& m_m[3][2] == r.m_m[3][2]    //
		&& m_m[3][3] == r.m_m[3][3];
    // clang-format on
}

double
CMatrix4x4::getValue( unsigned row, unsigned col ) const
{
    return m_m[row][col];
}

double&
CMatrix4x4::getRef( unsigned row, unsigned col )
{
    return m_m[row][col];
}

glm::mat4x4
CMatrix4x4::getMat4x4() const
{
    glm::mat4x4 m4(                                        //
            m_m[0][0], m_m[0][1], m_m[0][2], m_m[0][3],    //
            m_m[1][0], m_m[1][1], m_m[1][2], m_m[1][3],    //
            m_m[2][0], m_m[2][1], m_m[2][2], m_m[2][3],    //
            m_m[3][0], m_m[3][1], m_m[3][2], m_m[3][3]     //
    );
    return m4;
}

void
CMatrix4x4::translate( const CVector& r )
{
    m_m[0][3] += r.x;
    m_m[1][3] += r.y;
    m_m[2][3] += r.z;
}

CMatrix4x4
CMatrix4x4::transpose() const
{
    CMatrix4x4 m(                                          // load transpose
            m_m[0][0], m_m[1][0], m_m[2][0], m_m[3][0],    //
            m_m[0][1], m_m[1][1], m_m[2][1], m_m[3][1],    //
            m_m[0][2], m_m[1][2], m_m[2][2], m_m[3][2],    //
            m_m[0][3], m_m[1][3], m_m[2][3], m_m[3][3]     //
    );
    return m;
}

double
CMatrix4x4::determinant() const
{
    return ( ( m_m[0][0] * m_m[3][2] ) * ( m_m[2][1] * m_m[3][3] - m_m[2][3] * m_m[3][1] ) )
            + ( ( m_m[0][1] * m_m[2][3] ) * ( m_m[2][2] * m_m[3][0] - m_m[2][0] * m_m[3][2] ) )
            + ( ( m_m[0][2] * m_m[2][0] ) * ( m_m[1][3] * m_m[3][1] - m_m[2][1] * m_m[3][3] ) )
            + ( ( m_m[0][3] * m_m[2][1] ) * ( m_m[1][0] * m_m[3][2] - m_m[1][2] * m_m[3][0] ) );
}

//		r[0][0], r[0][1], r[0][2], r[0][3],    //  0,  1,  2,  3
//		r[1][0], r[1][1], r[1][2], r[1][3],    //  4,  5,  6,  7
//		r[2][0], r[2][1], r[2][2], r[2][3],    //  8,  9, 10, 11
//		r[3][0], r[3][1], r[3][2], r[3][3]     // 12, 13, 14, 15

CPoint
CMatrix4x4::transformPoint( const CPoint& p ) const
{
    float x = p.x * m_m[0][0] + p.y * m_m[0][1] + p.z * m_m[0][2] + m_m[0][3];    //
    float y = p.x * m_m[1][0] + p.y * m_m[1][1] + p.z * m_m[1][2] + m_m[1][3];    //
    float z = p.x * m_m[2][0] + p.y * m_m[2][1] + p.z * m_m[2][2] + m_m[2][3];    //
    float w = p.x * m_m[3][0] + p.y * m_m[3][1] + p.z * m_m[3][2] + m_m[3][3];

    x *= w;
    y *= w;
    z *= w;
    return CPoint( x, y, z );
}

CMatrix4x4
CMatrix4x4::multiplyMatrix( const CMatrix4x4& p ) const
{
    // clang-format off
	CMatrix4x4 r(    //
		m_m[0][0]*p[0][0] + m_m[0][1]*p[1][0] + m_m[0][2]*p[2][0] + m_m[0][3]*p[3][0],
		m_m[0][0]*p[0][1] + m_m[0][1]*p[1][1] + m_m[0][2]*p[2][1] + m_m[0][3]*p[3][1],
		m_m[0][0]*p[0][2] + m_m[0][1]*p[1][2] + m_m[0][2]*p[2][2] + m_m[0][3]*p[3][2],
		m_m[0][0]*p[0][3] + m_m[0][1]*p[1][3] + m_m[0][2]*p[2][3] + m_m[0][3]*p[3][3],

		m_m[1][0]*p[0][0] + m_m[1][1]*p[1][0] + m_m[1][2]*p[2][0] + m_m[1][3]*p[3][0],
		m_m[1][0]*p[0][1] + m_m[1][1]*p[1][1] + m_m[1][2]*p[2][1] + m_m[1][3]*p[3][1],
		m_m[1][0]*p[0][2] + m_m[1][1]*p[1][2] + m_m[1][2]*p[2][2] + m_m[1][3]*p[3][2],
		m_m[1][0]*p[0][3] + m_m[1][1]*p[1][3] + m_m[1][2]*p[2][3] + m_m[1][3]*p[3][3],

		m_m[2][0]*p[0][0] + m_m[2][1]*p[1][0] + m_m[2][2]*p[2][0] + m_m[2][3]*p[3][0],
		m_m[2][0]*p[0][1] + m_m[2][1]*p[1][1] + m_m[2][2]*p[2][1] + m_m[2][3]*p[3][1],
		m_m[2][0]*p[0][2] + m_m[2][1]*p[1][2] + m_m[2][2]*p[2][2] + m_m[2][3]*p[3][2],
		m_m[2][0]*p[0][3] + m_m[2][1]*p[1][3] + m_m[2][2]*p[2][3] + m_m[2][3]*p[3][3],

		m_m[3][0]*p[0][0] + m_m[3][1]*p[1][0] + m_m[3][2]*p[2][0] + m_m[3][3]*p[3][0],
		m_m[3][0]*p[0][1] + m_m[3][1]*p[1][1] + m_m[3][2]*p[2][1] + m_m[3][3]*p[3][1],
		m_m[3][0]*p[0][2] + m_m[3][1]*p[1][2] + m_m[3][2]*p[2][2] + m_m[3][3]*p[3][2],
		m_m[3][0]*p[0][3] + m_m[3][1]*p[1][3] + m_m[3][2]*p[2][3] + m_m[3][3]*p[3][3] );
    // clang-format on
    return r;
}

void
CMatrix4x4::multiplyToSelf( const CMatrix4x4& m )
{
    CMatrix4x4 result = multiplyMatrix( m );
    *this = result;
}


CMatrix4x4
CMatrix4x4::buildScale( double x, double y, double z )
{
    CMatrix4x4 m( 1 );
    m[0][0] = x;
    m[1][1] = y;
    m[2][2] = z;
    m[3][3] = 1.0;
    return m;
}

CMatrix4x4
CMatrix4x4::buildScale( double scale )
{
    return CMatrix4x4( scale );
}

CMatrix4x4
CMatrix4x4::buildTranslate( double x, double y, double z )
{
    CMatrix4x4 m;
    m[0][3] = x;
    m[1][3] = y;
    m[2][3] = z;
    return m;
}

CMatrix4x4
CMatrix4x4::buildTranslate( const CVector& v )
{
    return buildTranslate( v.x, v.y, v.z );
}


CMatrix4x4
CMatrix4x4::buildRotateAroundXAxis( double rads )
{
    double cos_ = fCosine( rads );
    double sin_ = fSine( rads );

    CMatrix4x4 m;
    m[1][1] = cos_;
    m[1][2] = -sin_;
    m[2][1] = sin_;
    m[2][2] = cos_;
    return m;
}

CMatrix4x4
CMatrix4x4::buildRotateAroundYAxis( double rads )
{
    double cos_ = fCosine( rads );
    double sin_ = fSine( rads );

    CMatrix4x4 m;
    m[0][0] = cos_;
    m[0][2] = sin_;
    m[2][0] = -sin_;
    m[2][2] = cos_;
    return m;
}

CMatrix4x4
CMatrix4x4::buildRotateAroundZAxis( double rads )
{
    double cos_ = fCosine( rads );
    double sin_ = fSine( rads );

    CMatrix4x4 m;
    m[0][0] = cos_;
    m[0][1] = -sin_;
    m[1][0] = sin_;
    m[1][1] = cos_;
    return m;
}

CMatrix4x4
CMatrix4x4::buildFromPitchAndYaw( double pitch, double yaw )
{
    // float cosB = fCosine( -pitch );
    // float sinB = fSine( -pitch );
    // float cosA = fCosine( yaw );
    // float sinA = fSine( yaw );
    // float cosY = fCosine( 0.0f );
    // float sinY = fSine( 0.0f );

    double cP = fCosine( -pitch );    // cosB
    double sP = fSine( -pitch );      // sinB
    double cY = fCosine( yaw );       // cosA
    double sY = fSine( yaw );         // sinA
    double cR = fCosine( 0.0 );       // cosY
    double sR = fSine( 0.0 );

    CMatrix4x4 m;
#if false
	m[0][0] = cY * cP;
	m[0][1] = -sY;
	m[0][2] = cY * sP;

	m[1][0] = sY * cP;
	m[1][1] = cY;
	m[1][2] = sY * sP;

	m[2][0] = -sP;
	m[2][1] = 0;
	m[2][2] = cP;
#elif false
    m[0][0] = cP * cY;
    m[0][1] = cP * -sY;
    m[0][2] = sP;

    m[1][0] = sY;
    m[1][1] = cY;
    m[1][2] = 0;

    m[2][0] = -sP * cY;
    m[2][1] = -sP * -sY;
    m[2][2] = cP;
#else
    m[0][0] = cP * cY;
    m[0][1] = sR * sP * cY - cR * sY;
    m[0][2] = cR * sP * cY + sR * sY;

    m[1][0] = cP * sY;
    m[1][1] = sR * sP * sY + cR * cY;
    m[1][2] = cR * sP * sY - sR * cY;

    m[2][0] = -sP;
    m[2][1] = sR * cP;
    m[2][2] = cR * cP;
#endif

    // m[0][0] = cosA * cosB;                         // cv*cw
    // m[0][1] = cosA * sinB * sinY - sinA * cosY;    // su*sv*cw - cu*sw
    // m[0][2] = cosA * sinB * cosY + sinA * sinY;    // su*sw + cu*sv*cw
    // m[1][0] = sinA * cosB;                         // cv*sw
    // m[1][1] = sinA * sinB * sinY + cosA * cosY;    // cu*cw + su*sv*sw
    // m[1][2] = sinA * sinB * cosY - cosA * sinY;    // cu*sv*sw - su*cw
    // m[2][0] = -sinB;                               // -sv
    // m[2][1] = cosB * sinY;                         // su*cv
    // m[2][2] = cosB * cosY;                         // cu*cv
    return m;
}
/*
combined rotational matrix
P = pitch
Y = yaw
c = cos
s = sin

around y axis (pitch)

cP  0   sP
0   1   0
-sP 0   cP

around z axis (Yaw)

cY  -sY 0
sY  cY  0
0   0   1

===========
cY*cP + -sY*0 + 0*-sP
cY*0  + -sY*1 + 0*0
cY*sP + -sY*0 + 0*cP

sY*cP + cY*0 + 0*-sP
sY*0  + cY*1 + 0*0
sY*sP + cY*0 + 0*cP

0*cP + 0*0 + 1*-sP
0*0  + 0*1 + 1*0
0*sP + 0*0 + 1*cP

===========
cP*cY  + 0*sY + sP*0
cP*-sY + 0*cY + sP*0
cP*0   + 0*0  + sP*1

0*cY  + 1*sY + 0*0
0*-sY + 1*cY + 0*0
0*0   + 1*0  + 0*1

-sP*cY  + 0*sY + cP*0
-sP*-sY + 0*cY + cP*0
-sP*0   + 0*0  + cP*1

*/


void
build_4x4_rotation_matrix( float x, float y, float z, float a, float* matrix )
{
    a = a * M_PI / 180.0;    // convert to radians
    float s = sin( a );
    float c = cos( a );
    float t = 1.0 - c;
    float tx = t * x;
    float ty = t * y;
    float tz = t * z;
    float sz = s * z;
    float sy = s * y;
    float sx = s * x;
    matrix[0] = tx * x + c;
    matrix[1] = tx * y + sz;
    matrix[2] = tx * z - sy;
    matrix[3] = 0;
    matrix[4] = tx * y - sz;
    matrix[5] = ty * y + c;
    matrix[6] = ty * z + sx;
    matrix[7] = 0;
    matrix[8] = tx * z + sy;
    matrix[9] = ty * z - sx;
    matrix[10] = tz * z + c;
    matrix[11] = 0;
    matrix[12] = 0;
    matrix[13] = 0;
    matrix[14] = 0;
    matrix[15] = 1;
}


//===============================================
// protected functions
//===============================================


}}    // namespace Yogi::Graphics
