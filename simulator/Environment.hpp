//=========================================================
///	@file: Environment.hpp
//=========================================================
#ifndef _HPP_ENVIRONMENT_
#define _HPP_ENVIRONMENT_

#include "CPoint2.hpp"
#include "TArray2.hpp"
#include "VDraw.hpp"

namespace Yogi { namespace Simulator {

class Environment
{
public:
    Environment();
    virtual ~Environment();

public:
    void
    display( Yogi::Graphics::VDraw* pDraw );

    bool
    readEnvironment( const char* sFilename );

protected:
    Yogi::Graphics::CPoint2          m_tOrigin;
    double                           m_dRowSpacing;
    double                           m_dColSpacing;
    int                              m_nRows;
    int                              m_nCols;
    Yogi::Utilities::TArray2<double> m_aDTM;

    class Light
    {
    public:
        int                    id;
        Yogi::Graphics::CPoint position;

        Light()
                : position()
                , id( 0 )
        {}
        Light( const Light& r )
                : id( r.id )
                , position( r.position )
        {}
        const Light&
        operator=( const Light& r )
        {
            id = r.id;
            position = r.position;
            return *this;
        }
    };
    int   m_nNumLights;
    Light m_aLights[8];
};


}}    // namespace Yogi::Simulator

#endif    // _HPP_ENVIRONMENT_
