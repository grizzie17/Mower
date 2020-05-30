#include "CCamera.hpp"

#include "gtest/gtest.h"


using namespace Yogi::Graphics;


TEST( CCamera, initial )
{
	CCamera ourCam;

	// position and orientation
	CPoint      pos = ourCam.getPosition();
	CPoint      tgt = ourCam.getTarget();
	CUnitVector up = ourCam.getUpWorld();

	ASSERT_TRUE( pos == CPoint( 0, 0, 1 ) );
	ASSERT_TRUE( tgt == CPoint( 0, 0, 0 ) );
	ASSERT_TRUE( up == CUnitVector( 0, 1, 0 ) );

	// frustum
	double fov = ourCam.getFieldOfView();
	double clpNear = ourCam.getClippingNear();
	double clpFar = ourCam.getClippingFar();

	ASSERT_DOUBLE_EQ( 30, fov );
	ASSERT_DOUBLE_EQ( 0.01, clpNear );
	ASSERT_DOUBLE_EQ( 2000, clpFar );
}

// TEST( CCamera, getViewMatrix )
// {
// 	CPoint      pos( 1, 0, 1 );
// 	CPoint      tgt( 0, 0, 0 );
// 	CUnitVector up( 0, 0, 1 );
// 	CCamera     cam( pos, tgt, up );

// 	CMatrix4x4 m = cam.getViewMatrix();
// }

TEST( CCamera, offsets )
{
	CPoint      pos( 1, 0, 1 );
	CPoint      tgt( 0, 0, 0 );
	CUnitVector up( 0, 0, 1 );
	CCamera     cam( pos, tgt, up );

	cam.offsetPosition( CVector( 1, 1, 1 ) );
	CPoint oPos = cam.getPosition();
	ASSERT_TRUE( oPos == CPoint( 2, 1, 2 ) );

	cam.offsetTarget( CVector( -1, -1, 0 ) );
	CPoint oTgt = cam.getTarget();
	ASSERT_TRUE( oTgt == CPoint( -1, -1, 0 ) );
}
