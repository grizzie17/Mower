//=====================================
///	@file: CCamera.cpp
//=====================================

#include "CCamera.hpp"
#include "math_helper.hpp"

#include <GL/gl.h>
#include <GL/glu.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>

// #include <glm/gtc/matrix_transform.hpp>

using namespace Yogi::Utilities;

namespace Yogi { namespace Graphics {

// must be less that 90 to avoid gimbal lock
static const float k_maxVerticalAngle = 85.0f;


CCamera::CCamera()
        : m_tPosition( 0.0, 0.0, 1.0 )
        , m_dPitch( -45.0 )
        , m_dYaw( 0.0 )
        , m_dRoll( 0.0 )
        , m_dScale( 1.0 )
        //, m_tTarget( 0.0, 0.0, 0.0 )
        //, m_tUpWorld( 0.0, 1.0, 0.0 )
        , m_dClippingNear( 0.01 )
        , m_dClippingFar( 2000.0 )
        , m_dFieldOfView( 30.0 )
        , m_tViewDimensions( 800, 800 * 3 / 4 )
{
    double  pitch;
    double  yaw;
    CVector look = m_tPosition - m_tTarget;
    look.getPitchAndYaw( &pitch, &yaw );
    m_dPitch = degreesFromRadians( pitch );
    m_dYaw = degreesFromRadians( yaw );
    m_dRoll = 0.0;
}

CCamera::CCamera( const CPoint& pos, const CPoint& tgt, const CUnitVector& up )
        : m_tPosition( pos )
        , m_tTarget( tgt )
        , m_tUpWorld( up )
        , m_dScale( 1.0 )
        , m_dClippingNear( 0.01 )
        , m_dClippingFar( 1000.0 )
        , m_dFieldOfView( 60.0 )
        , m_tViewDimensions( 800, 800 * 3 / 4 )
{
    double  pitch;
    double  yaw;
    CVector look = m_tPosition - tgt;
    look.getPitchAndYaw( &pitch, &yaw );
    m_dPitch = degreesFromRadians( pitch );
    m_dYaw = degreesFromRadians( yaw );
    // NEEDS_WORK: add calculation for 'm_dRoll'
}

// pitch, yaw, and roll are specified in degrees
CCamera::CCamera( const CPoint& pos, double pitch, double yaw, double roll )
        : m_tPosition( pos )
        , m_dPitch( pitch )
        , m_dYaw( yaw )
        , m_dRoll( roll )
        , m_dScale( 1.0 )
        , m_dClippingNear( 0.01 )
        , m_dClippingFar( 1000.0 )
        , m_dFieldOfView( 60.0 )
        , m_tViewDimensions( 800, 800 * 3 / 4 )
        , m_tUpWorld( 0, 0, 1 )
{
    CUnitVector uv = CUnitVector::buildFromPitchAndYaw( pitch, yaw );
    m_tTarget = m_tPosition + uv;
}

CCamera::~CCamera()
{}


void
CCamera::setViewDimensions( unsigned x, unsigned y )
{
    m_tViewDimensions.x = x;
    m_tViewDimensions.y = y;
}

void
CCamera::setViewDimensions( const CPoint2& dim )
{
    m_tViewDimensions = dim;
}


const CPoint&
CCamera::getPosition() const
{
    return m_tPosition;
}

void
CCamera::setPosition( const CPoint& pos )
{
    m_tPosition = pos;
}

void
CCamera::offsetPosition( const CVector& offset )
{
    m_tPosition += offset;
}

const CPoint&
CCamera::getTarget() const
{
    return m_tTarget;
}

void
CCamera::setTarget( const CPoint& look )
{
    m_tTarget = look;
}

void
CCamera::offsetTarget( const CVector& offset )
{
    m_tTarget += offset;
}


const CUnitVector&
CCamera::getUpWorld() const
{
    return m_tUpWorld;
}

void
CCamera::setUpWorld( const CUnitVector& up )
{
    m_tUpWorld = up;
}

double
CCamera::getClippingNear() const
{
    return m_dClippingNear;
}

double
CCamera::getClippingFar() const
{
    return m_dClippingFar;
}

void
CCamera::setClippingNear( double d )
{
    m_dClippingNear = d;
}

void
CCamera::setClippingFar( double d )
{
    m_dClippingFar = d;
}

void
CCamera::setClipping( double dNear, double dFar )
{
    m_dClippingNear = dNear;
    m_dClippingFar = dFar;
}

double
CCamera::getFieldOfView() const
{
    return m_dFieldOfView;
}

void
CCamera::setFieldOfView( double fov )
{
    m_dFieldOfView = fov;
}


void
CCamera::rotate( double pitch, double yaw, double roll )
{
    m_dPitch = pitch;
    m_dYaw = yaw;
    m_dRoll = roll;
}


void
CCamera::setRoll( double d )
{
    m_dRoll = d;
}

void
CCamera::setPitch( double d )
{
    m_dPitch = d;
}

void
CCamera::setYaw( double d )
{
    m_dYaw = d;
}

void
CCamera::setScale( double d )
{
    m_dScale = d;
}


// CMatrix4x4
// CCamera::getViewMatrix() const
// {
// 	CMatrix4x4 m;
//
// 	return m;
// }


void
CCamera::viewRender()
{
    //calculateFrustum();

    glViewport( 0, 0, m_tViewDimensions.x, m_tViewDimensions.y );
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();

    double dAspect;
    if ( 0 < m_tViewDimensions.y )
        dAspect = m_tViewDimensions.x / m_tViewDimensions.y;
    else
        dAspect = 1.0;
    gluPerspective( m_dFieldOfView, dAspect, m_dClippingNear, m_dClippingFar );

    glMatrixMode( GL_MODELVIEW );

    glLoadIdentity();

    gluLookAt(                                            //
            m_tPosition.x, m_tPosition.y, m_tPosition.z,  // eye
            m_tTarget.x, m_tTarget.y, m_tTarget.z,        // target
            m_tUpWorld.x, m_tUpWorld.y, m_tUpWorld.z      // up
    );


    // glScaled( m_dScale, m_dScale, m_dScale );
    // glTranslated( -m_tPosition.x, -m_tPosition.y, -m_tPosition.z );
    // glRotated( -m_dRoll, 1, 0, 0 );           // +degrees = roll clockwise
    // glRotated( 90.0 - m_dYaw, 0, 0, 1 );      // +degrees = yaw to right
    // glRotated( 90.0 - m_dPitch, 0, 1, 0 );    // +degrees = pitch up
    // glTranslated( -m_tPosition.x, -m_tPosition.y, -m_tPosition.z );
    //glRotated( 90.0 - m_dPitch, 0, -1, 0 );    // pitch
    // glRotated( 90.0 - m_dYaw, 0, 0, -1 );    // yaw
}

}}  // namespace Yogi::Graphics
