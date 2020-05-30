//=========================================================
///	@file: Environment.cpp
//=========================================================

#include "Environment.hpp"
#include "nlohmann/json.hpp"

#include <fstream>


#define DTM_ROWS 5
#define DTM_COLS 5

using namespace Yogi::Graphics;
using namespace Yogi::Utilities;
using json = nlohmann::json;

namespace Yogi { namespace Simulator {

Environment::Environment()
        : m_tOrigin()             //! < 0,0,0 origin
        , m_dRowSpacing( 1.0 )    //! < one meter spacing
        , m_dColSpacing( 1.0 )    //! < one meter spacing
        , m_nRows( DTM_ROWS )
        , m_nCols( DTM_COLS )
        , m_aDTM()
        , m_nNumLights( 0 )
{
    ::memset( m_aLights, 0, sizeof( m_aLights ) );
}

Environment::~Environment()
{}

void
Environment::display( VDraw* pDraw )
{
    double y = m_tOrigin.y + m_dRowSpacing * m_nRows;
    double y1 = y - m_dRowSpacing;
    double x = m_tOrigin.x;
    double x1 = x + m_dColSpacing;

    if ( 0 < m_nNumLights )
    {
        pDraw->enableLights();
        for ( int i = 0; i < m_nNumLights; ++i )
        {
            pDraw->placeLight( m_aLights[i].id, m_aLights[i].position );
        }
    }

    for ( int i = 0; i < m_nRows - 1; ++i )
    {
        x = m_tOrigin.x;
        x1 = x + m_dColSpacing;
        pDraw->setColor( 0, 0.60, 0 );
        // pDraw->beginTriangleStrip();
        pDraw->beginLineStrip();
        for ( int j = 0; j < m_nCols; ++j )
        {
            pDraw->polypoint( x, y, m_aDTM[i][j] );
            pDraw->polypoint( x, y1, m_aDTM[i + 1][j] );
            x = x1;
            x1 += m_dColSpacing;
        }
        y = y1;
        y1 -= m_dRowSpacing;
        pDraw->endLineStrip();
        // pDraw->endTriangleStrip();
    }
    // double x = m_tOrigin.x;
    // double x1 = m_tOrigin.x + m_dRowSpacing;
    // double y = m_tOrigin.y;
    // double y1 = m_tOrigin.y + m_dRowSpacing;
    // for ( int i = 0; i < DTM_ROWS - 1; ++i )
    // {
    // 	pDraw->setColor( 0, 0.80, 0 );
    // 	pDraw->beginTriangleStrip();
    // 	for ( int j = 1; j < DTM_COLS; ++j )
    // 	{
    // 		pDraw->polypoint( x, y, m_aDTM[i][j - 1] );
    // 		pDraw->polypoint( x, y1, m_aDTM[i][j] );
    // 	}
    // 	y = y1;
    // 	y1 += m_dRowSpacing;
    // 	pDraw->endTriangleStrip();
    // }

    // pDraw->beginTriangles();

#define TOP                     \
    pDraw->setColor( 1, 0, 0 ); \
    pDraw->polypoint( 0, 1, 0 )
#define FR                      \
    pDraw->setColor( 0, 1, 0 ); \
    pDraw->polypoint( 1, -1, 1 )
#define FL                      \
    pDraw->setColor( 0, 0, 1 ); \
    pDraw->polypoint( -1, -1, 1 )
#define BR                      \
    pDraw->setColor( 0, 0, 1 ); \
    pDraw->polypoint( 1, -1, -1 )
#define BL                      \
    pDraw->setColor( 0, 1, 0 ); \
    pDraw->polypoint( -1, -1, -1 )

    // TOP;
    // FL;
    // FR;
    // TOP;
    // FR;
    // BR;
    // TOP;
    // BR;
    // BL;
    // TOP;
    // BL;
    // FL;
    // FR;
    // FL;
    // BL;
    // BL;
    // BR;
    // FR;

    // pDraw->setColor( 1.0, 0, 0 );    // 1
    // pDraw->polypoint( 0, 1, 0 );
    // pDraw->setColor( 0, 1.0, 0 );    // 2
    // pDraw->polypoint( -1, -1 );
    // pDraw->setColor( 0, 0, 1.0 );    // 3
    // pDraw->polypoint( 1, -1, 0 );
    // pDraw->endTriangles();
}

bool
Environment::readEnvironment( const char* sFilename )
{
    bool bResult = false;

    std::ifstream ifs( sFilename );
    if ( ifs )
    {
        json j = json::parse( ifs );
        if ( ! j.empty() )
        {
            auto const jTerrain = j["terrain"];
            if ( ! jTerrain.empty() )
            {
                m_nRows = jTerrain["rows"];
                m_nCols = jTerrain["columns"];
                m_dRowSpacing = jTerrain["rowSpacing"];
                m_dColSpacing = jTerrain["colSpacing"];

                auto const jElevations = jTerrain["elevations"];
                if ( ! jElevations.empty() )
                {
                    int nRowsSize = jElevations.size();
                    if ( nRowsSize == m_nRows )
                    {
                        m_aDTM = TArray2<double>( m_nRows, m_nCols );
                        unsigned nRowCurrent = 0;
                        for ( auto jRow = jElevations.begin(); jRow != jElevations.end();
                                ++jRow )
                        {
                            if ( jRow->is_array() )
                            {
                                unsigned nColsSize = jRow->size();
                                if ( nColsSize == m_nCols )
                                {
                                    unsigned nColCurrent = 0;
                                    for ( auto jCol = jRow->begin(); jCol != jRow->end();
                                            ++jCol )
                                    {
                                        m_aDTM[nRowCurrent][nColCurrent] = jCol.value();
                                        ++nColCurrent;
                                    }
                                }
                            }
                            ++nRowCurrent;
                        }
                    }
                }
            }

            auto const jLights = j["lights"];
            if ( ! jLights.empty() )
            {
                m_nNumLights = jLights.size();
                int nLight = 0;
                if ( 0 < m_nNumLights )
                {
                    for ( auto jLight = jLights.begin(); jLight != jLights.end(); ++jLight )
                    {
                        auto jProp = jLight.value();
                        m_aLights[nLight].id = jProp["id"];
                        CPoint pos;
                        auto   jPos = jProp["position"];
                        double x = jPos[0];
                        double y = jPos[1];
                        double z = jPos[2];
                        m_aLights[nLight].position.set( x, y, z );
                        ++nLight;
                    }
                }
            }
        }
    }
    return true;
}

}}    // namespace Yogi::Simulator
