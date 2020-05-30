//=====================================
///	@file: CCamera.hpp
//=====================================
#ifndef HPP_CCAMERA
#define HPP_CCAMERA
#pragma once

#include "CMatrix4x4.hpp"
#include "CPoint.hpp"
#include "CPoint2.hpp"
#include "CUnitVector.hpp"
#include "CVector.hpp"

// #include <glm/glm.hpp>
// #include <glm/mat4x4.hpp>
// #include <glm/vec3.hpp>

namespace Yogi { namespace Graphics {

class CCamera
{
    // class lifecycle
public:
    CCamera();
    CCamera( const CPoint& position, const CPoint& target, const CUnitVector& upWorld );
    CCamera( const CPoint& position,    //! world position
            double         pitch,       //!< degrees
            double         yaw,         //!< degrees
            double         roll         //!< degrees
    );

    ~CCamera();

public:
    void
    setViewDimensions( unsigned x, unsigned y );
    void
    setViewDimensions( const CPoint2& dim );

    // camera position
    const CPoint&
    getPosition() const;

    void
    setPosition( const CPoint& position );


    // world coordinate that we are looking at
    const CPoint&
    getTarget() const;

    void
    setTarget( const CPoint& target );

    // camera up
    const CUnitVector&
    getUpWorld() const;

    void
    setUpWorld( const CUnitVector& up );

    // field of view
    double
    getFieldOfView() const;

    void
    setFieldOfView( double f );


    // clipping
    double
    getClippingNear() const;

    double
    getClippingFar() const;

    void
    setClippingNear( double near );

    void
    setClippingFar( double far );

    void
    setClipping( double near, double far );


    // change camera position and orientation
    void
    offsetPosition( const CVector& offset );

    void
    offsetTarget( const CVector& offset );

    void
    rotate( double pitch, double yaw, double roll );

    void
    setRoll( double d );    //!< degrees

    void
    setPitch( double d );    //!< degrees

    void
    setYaw( double d );    //!< degrees

    void
    setScale( double d );


    // CMatrix4x4
    // getViewMatrix() const;

    void
    viewRender();


protected:
    CPoint      m_tPosition;          // world coordinates
    CPoint      m_tTarget;            // looking-at a world coordinate
    CUnitVector m_tUpWorld;           // vector pointing up
    CPoint2     m_tViewDimensions;    // width and height of window
    double      m_dScale;             // view scale
    double      m_dClippingNear;      // along look-at line
    double      m_dClippingFar;       // along look-at line
    double      m_dFieldOfView;       // 5 to 180 degrees

    double m_dPitch;    //!< degrees (up is positive)
    double m_dYaw;      //!< degrees (clockwise is positive)
    double m_dRoll;     //!< degrees (right is positive)

    // the following may be removed


    // glm::mat4 m_tView;
};

}}    // namespace Yogi::Graphics

#endif    // HPP_CCAMERA
