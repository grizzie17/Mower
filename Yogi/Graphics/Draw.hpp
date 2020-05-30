//=========================================================
/// @file: Draw.hpp
///
/// Class for drawing to OpenGL
//=========================================================

#ifndef _HPP_Draw_
#define _HPP_Draw_

#include "CCamera.hpp"
#include "CPoint2.hpp"
#include "VDraw.hpp"

#include <GL/glu.h>
#include <errno.h>

namespace Yogi { namespace Graphics {


class OpenGLDraw : public VDraw
{
public:
    // class lifecycle  -------------------------
    OpenGLDraw( HINSTANCE hInstance );
    virtual ~OpenGLDraw();

public:
    // public types  ----------------------------

    // public functions  ------------------------

    // create and initialize window
    bool
    initialize( HWND hWnd, HDC hDC );

    void
    setCamera( CCamera* pCamera );


    //!	start drawing to window
    bool
    beginDraw();

    //! complete drawing to window
    bool
    endDraw();

    void
    update( int ox, int nx, int oy, int ny );

    bool
    size( int cx, int cy );

    bool
    setWindowTitle( const char* sNewTitle );

protected:
    // protected types  -------------------------

    // protected functions  ---------------------

    // protected data  --------------------------

    HINSTANCE   m_hInstance;
    HDC         m_hDC;     //!< MS-Windows DC
    HWND        m_hWnd;    //!< MS-Windows Window Handle
    HGLRC       m_hRC;     //!< OpenGL Resource Context
    PAINTSTRUCT m_tPaint;
    CPoint2     m_tScreenSize;
    CCamera*    m_pCamera;
    int         m_nStackMatrix;


public:
    // VDraw Interface --------------------------

    virtual void
    pushMatrix() override;

    virtual void
    popMatrix() override;

    virtual void
    enableLights() override;

    virtual void
    placeLight( unsigned id, const CPoint& position ) override;


    //! add point/vertex to draw buffer
    //! must be bracketed by beginPolygon or similar
    virtual void
    polypoint(                //! void
            double x,         //!< [in] x
            double y,         //!< [in] y
            double z = 0.0    //!< [in] z
            ) override;


    virtual void
    beginPolygon() override;
    virtual void
    endPolygon() override;

    virtual void
    beginLineStrip() override;
    virtual void
    endLineStrip() override;

    virtual void
    beginTriangles() override;
    virtual void
    endTriangles() override;

    virtual void
    beginTriangleStrip() override;
    virtual void
    endTriangleStrip() override;

    virtual void
    beginQuadStrip() override;
    virtual void
    endQuadStrip() override;

    virtual void
    setColor( double r, double g, double b ) override;
};

}}    // namespace Yogi::Graphics

#endif    // _HPP_Draw_
