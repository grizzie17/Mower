#include "CMatrix4x4.hpp"
#include "CUnitVector.hpp"
#include "math_helper.hpp"
#include <glm/mat4x4.hpp>

#include "gtest/gtest.h"

#include <cmath>


using namespace Yogi::Graphics;
using namespace Yogi::Utilities;


TEST( CMatrix4x4, initial )
{
    CMatrix4x4 myMat;
    CMatrix4x4 t(          //
            1, 0, 0, 0,    //
            0, 1, 0, 0,    //
            0, 0, 1, 0,    //
            0, 0, 0, 1     //
    );

    ASSERT_TRUE( t == myMat );
}

TEST( CMatrix4x4, initializeUsingGLM )
{
    glm::mat4x4 g( 2 );
    g[0][0] = 2;
    g[1][1] = 2;
    g[2][2] = 2;
    g[3][3] = 1;
    CMatrix4x4 m2( 2 );
    CMatrix4x4 m( g );

    ASSERT_TRUE( m == m2 );
}

TEST( CMatrix4x4, copy )
{
    CMatrix4x4 m( 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 );
    CMatrix4x4 c( m );

    ASSERT_TRUE( m.equals( c ) );
    ASSERT_TRUE( m == c );
}

TEST( CMatrix4x4, getElement )
{
    CMatrix4x4 m(             //
            0, 1, 2, 3,       //
            4, 5, 6, 7,       //
            8, 9, 10, 11,     //
            12, 13, 14, 15    //
    );

    ASSERT_DOUBLE_EQ( 0, m[0][0] );
    ASSERT_DOUBLE_EQ( 2, m[0][2] );
    ASSERT_DOUBLE_EQ( 3, m[0][3] );
    ASSERT_DOUBLE_EQ( 5, m[1][1] );
    ASSERT_DOUBLE_EQ( 8, m[2][0] );
    ASSERT_DOUBLE_EQ( 10, m[2][2] );
    ASSERT_DOUBLE_EQ( 15, m[3][3] );
}

TEST( CMatrix4x4, setElement )
{
    CMatrix4x4 m;
    m[2][2] = 10;

    ASSERT_DOUBLE_EQ( 1, m[0][0] );
    ASSERT_DOUBLE_EQ( 1, m[1][1] );
    ASSERT_DOUBLE_EQ( 10, m[2][2] );
    ASSERT_DOUBLE_EQ( 1, m[3][3] );
}

TEST( CMatrix4x4, getMat4x4 )
{
    CMatrix4x4  m(                //
            0, 1, 2, 3,          //
            4, 5, 6, 7,          //
            8, 9, 10, 11,        //
            12, 13, 14, 15 );    //
    glm::mat4x4 g = m.getMat4x4();

    ASSERT_DOUBLE_EQ( 0, m[0][0] );
    ASSERT_DOUBLE_EQ( 2, m[0][2] );
    ASSERT_DOUBLE_EQ( 3, m[0][3] );
    ASSERT_DOUBLE_EQ( 5, m[1][1] );
    ASSERT_DOUBLE_EQ( 8, m[2][0] );
    ASSERT_DOUBLE_EQ( 10, m[2][2] );
    ASSERT_DOUBLE_EQ( 15, m[3][3] );
}

TEST( CMatrix4x4, transpose )
{
    CMatrix4x4 m(                //
            0, 1, 2, 3,          //
            4, 5, 6, 7,          //
            8, 9, 10, 11,        //
            12, 13, 14, 15 );    //
    CMatrix4x4 t(                //
            0, 4, 8, 12,         //
            1, 5, 9, 13,         //
            2, 6, 10, 14,        //
            3, 7, 11, 15         //
    );
    CMatrix4x4 c = m.transpose();

    ASSERT_TRUE( t.equals( c ) );
}

TEST( CMatrix4x4, determinant )
{
    CMatrix4x4 m(                //
            0, 1, 2, 3,          //
            4, 5, 6, 7,          //
            8, 9, 10, 11,        //
            12, 13, 14, 15 );    //
    double     d = m.determinant();

    ASSERT_DOUBLE_EQ( -1048, d );
}

TEST( CMatrix4x4, transformPoint )
{
    CMatrix4x4 m(           //
            1, 0, 0, 10,    //
            0, 1, 0, 0,     //
            0, 0, 1, 0,     //
            0, 0, 0, 1      //
    );
    CPoint     p( 0, 0, 0 );
    CPoint     result = m * p;
    CPoint     expected( 10, 0, 0 );

    ASSERT_TRUE( result == expected );
}

TEST( CMatrix4x4, multiplyMatrix )
{
    CMatrix4x4 m( 1.0 );    // identity
    m[0][3] = 10;

    CMatrix4x4 h( 2.0 );
    h[1][3] = 5;

    CMatrix4x4 result = h * m;

    ASSERT_DOUBLE_EQ( 20, result[0][3] );    // remember: second matrix has 2 on its diagonal
    ASSERT_DOUBLE_EQ( 5, result[1][3] );
}

TEST( CMatrix4x4, multiplyMatrix2 )
{
    CMatrix4x4 a(          //
            5, 2, 6, 1,    //
            0, 6, 2, 0,    //
            3, 8, 1, 4,    //
            1, 8, 5, 6     //
    );
    CMatrix4x4 b(          //
            7, 5, 8, 0,    //
            1, 8, 2, 6,    //
            9, 4, 3, 8,    //
            5, 3, 7, 9     //
    );
    CMatrix4x4 t(               //
            96, 68, 69, 69,     //
            24, 56, 18, 52,     //
            58, 95, 71, 92,     //
            90, 107, 81, 142    //
    );
    CMatrix4x4 r = a * b;

    ASSERT_TRUE( t == r );
}

TEST( CMatrix4x4, translate )
{
    CMatrix4x4 m( 1 );
    CVector    v( 10, 0, 0 );

    m += v;

    ASSERT_DOUBLE_EQ( 10, m[0][3] );
}

TEST( CMatrix4x4, buildTranslate )
{
    CMatrix4x4 m = CMatrix4x4::buildTranslate( 10, 5, 1 );
    ASSERT_DOUBLE_EQ( 10, m[0][3] );
    ASSERT_DOUBLE_EQ( 5, m[1][3] );
    ASSERT_DOUBLE_EQ( 1, m[2][3] );
    ASSERT_DOUBLE_EQ( 1, m[0][0] );
    ASSERT_DOUBLE_EQ( 1, m[1][1] );
    ASSERT_DOUBLE_EQ( 1, m[2][2] );
    ASSERT_DOUBLE_EQ( 1, m[3][3] );

    CPoint p = m * CPoint( 0, 0, 0 );
    ASSERT_DOUBLE_EQ( 10, p.x );
    ASSERT_DOUBLE_EQ( 5, p.y );
    ASSERT_DOUBLE_EQ( 1, p.z );
}

TEST( CMatrix4x4, buildTranslateViaVector )
{
    CMatrix4x4 m = CMatrix4x4::buildTranslate( CVector( 10, 5, 1 ) );
    ASSERT_DOUBLE_EQ( 10, m[0][3] );
    ASSERT_DOUBLE_EQ( 5, m[1][3] );
    ASSERT_DOUBLE_EQ( 1, m[2][3] );
    ASSERT_DOUBLE_EQ( 1, m[0][0] );
    ASSERT_DOUBLE_EQ( 1, m[1][1] );
    ASSERT_DOUBLE_EQ( 1, m[2][2] );
    ASSERT_DOUBLE_EQ( 1, m[3][3] );

    CPoint p = m * CPoint( 0, 0, 0 );
    ASSERT_DOUBLE_EQ( 10, p.x );
    ASSERT_DOUBLE_EQ( 5, p.y );
    ASSERT_DOUBLE_EQ( 1, p.z );
}


TEST( CMatrix4x4, buildRotateAroundXAxis )
{
    double     rads = radiansFromDegrees( 90.0f );
    CMatrix4x4 m = CMatrix4x4::buildRotateAroundXAxis( rads );
    ASSERT_DOUBLE_EQ( 0, m[1][1] );
    ASSERT_DOUBLE_EQ( -1, m[1][2] );
    ASSERT_DOUBLE_EQ( 1, m[2][1] );
    ASSERT_DOUBLE_EQ( 0, m[2][2] );

    CPoint p = m * CPoint( 0, 1, 0 );

    ASSERT_DOUBLE_EQ( 0, p.x );
    ASSERT_DOUBLE_EQ( 0, p.y );
    ASSERT_DOUBLE_EQ( 1, p.z );
}

TEST( CMatrix4x4, buildRotateAroundYAxis )
{
    double     rads = radiansFromDegrees( 90.0f );
    CMatrix4x4 m = CMatrix4x4::buildRotateAroundYAxis( rads );
    ASSERT_DOUBLE_EQ( 0, m[0][0] );
    ASSERT_DOUBLE_EQ( 1, m[0][2] );
    ASSERT_DOUBLE_EQ( -1, m[2][0] );
    ASSERT_DOUBLE_EQ( 0, m[2][2] );

    CPoint p = m * CPoint( 0, 0, 1 );

    ASSERT_DOUBLE_EQ( 1, p.x );
    ASSERT_DOUBLE_EQ( 0, p.y );
    ASSERT_DOUBLE_EQ( 0, p.z );
}

TEST( CMatrix4x4, buildRotateAroundZAxis )
{
    double     rads = radiansFromDegrees( 90.0f );
    CMatrix4x4 m = CMatrix4x4::buildRotateAroundZAxis( rads );
    ASSERT_DOUBLE_EQ( 0, m[0][0] );
    ASSERT_DOUBLE_EQ( -1, m[0][1] );
    ASSERT_DOUBLE_EQ( 1, m[1][0] );
    ASSERT_DOUBLE_EQ( 0, m[1][1] );

    CPoint p = m * CPoint( 1, 0, 0 );

    ASSERT_DOUBLE_EQ( 0, p.x );
    ASSERT_DOUBLE_EQ( 1, p.y );
    ASSERT_DOUBLE_EQ( 0, p.z );
}

TEST( CMatrix4x4, rotateByPitchAndYaw )
{
    float      rPitch = radiansFromDegrees( 45.0f );
    float      rYaw = radiansFromDegrees( 45.0f );
    CMatrix4x4 m = CMatrix4x4::buildFromPitchAndYaw( rPitch, rYaw );

    CVector     vNorm( 1, 0, 0 );
    CVector     vResult = m * vNorm;
    CUnitVector a = vResult;
    CUnitVector t( 1, 1, 1 );

    ASSERT_DOUBLE_EQ( a.x, t.x );
    ASSERT_DOUBLE_EQ( a.y, t.y );
    ASSERT_DOUBLE_EQ( a.z, a.z );
}

// TEST( CMatrix4x4, rotateByPitchAndYaw2 )
// {
// 	double     fPitch = radiansFromDegrees( 45.0f );
// 	double     fYaw = radiansFromDegrees( 45.0f );
// 	CMatrix4x4 mPitch = CMatrix4x4::buildRotateAroundYAxis( -fPitch );
// 	CMatrix4x4 mYaw = CMatrix4x4::buildRotateAroundZAxis( fYaw );
// 	CMatrix4x4 m = mPitch * mYaw;
// 	CMatrix4x4 mYP = CMatrix4x4::buildFromPitchAndYaw( fPitch, fYaw );

// 	ASSERT_TRUE( m == mYP );

// 	CVector v( 1, 0, 0 );

// 	// assure that each matrix works
// 	CVector rP = mPitch * v;
// 	ASSERT_DOUBLE_EQ( 0.0f, rP.y );
// 	ASSERT_DOUBLE_EQ( rP.x, rP.z );

// 	CVector rY = mYaw * v;
// 	ASSERT_DOUBLE_EQ( 0.0f, rY.z );
// 	ASSERT_DOUBLE_EQ( rY.x, rY.y );

// 	CUnitVector t( 1, 1, 1 );
// 	CUnitVector u = rY + rP;
// 	ASSERT_DOUBLE_EQ( u.x, t.x );
// 	ASSERT_DOUBLE_EQ( u.y, t.y );
// 	ASSERT_DOUBLE_EQ( u.z, t.z );

// 	CVector     r = m * v;
// 	CUnitVector a = r;
// 	//CUnitVector r = m * v;

// 	ASSERT_DOUBLE_EQ( a.x, t.x );
// 	ASSERT_DOUBLE_EQ( a.y, t.y );
// 	ASSERT_DOUBLE_EQ( a.z, t.z );

// 	ASSERT_TRUE( t == a );
// }
