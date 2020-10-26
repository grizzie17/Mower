#ifndef HPP_CPOINT
#define HPP_CPOINT

// #include <glm/glm.hpp>
//#include <glm/vec3.hpp>
#include <limits>

namespace Yogi { namespace Graphics {


// forward declaration
class CVector;


typedef struct TPoint
{
    union
    {
        struct
        {
            double x;
            double y;
            double z;
        };
        struct
        {
            double array[3];
        };
    };


    TPoint()
            : x( 0 )
            , y( 0 )
            , z( 0 )
    {}
    TPoint( double x_, double y_, double z_ )
            : x( x_ )
            , y( y_ )
            , z( z_ )
    {}
    TPoint( const TPoint& r )
            : TPoint( r.x, r.y, r.z )
    {}

    // assignment
    virtual void
    set( double x, double y, double z )
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    const TPoint&
    operator=( const TPoint& r )
    {
        set( r.x, r.y, r.z );
        return *this;
    }

    // equality
    bool
    equals( const TPoint& r ) const
    {
        return this->x == r.x && this->y == r.y && this->z == r.z;
    }
    bool
    operator==( const TPoint& r ) const
    {
        return equals( r );
    }

    // index
    double
    operator[]( unsigned n ) const
    {
        return array[n];
    }
    double&
    operator[]( unsigned n )
    {
        return this->getRef( n );
    }
    double&
    getRef( unsigned n )
    {
        return array[n];
    }

    // fetch an OpenGL glm::vec3
    // glm::vec3
    // getVec3() const
    // {
    //     return glm::vec3( this->x, this->y, this->z );
    // }
} TPoint;


class CPoint : public TPoint
{
public:
    CPoint();
    CPoint( double x, double y, double z );
    CPoint( const CPoint& r );
    //CPoint( const glm::vec3& r );
    ~CPoint();

public:
    virtual void
    setX( double x );

    virtual void
    setY( double y );

    virtual void
    setZ( double y );

    double
    getX() const;

    double
    getY() const;

    double
    getZ() const;

    void
    addVector( const CVector& r );
    void
    subtractVector( const CVector& r );

    const CPoint&
    operator+=( const CVector& r );

    CPoint
    operator+( const CVector& r ) const;

    const CPoint&
    operator-=( const CVector& r );
    CPoint
    operator-( const CVector& r ) const;

    const CPoint&
    operator+=( double c );

    CVector
    operator-( const CPoint& r ) const;


protected:
    //glm::vec3 m_tCoordinate;
    // double m_x;
    // double m_y;
    // double m_z;
private:
    typedef TPoint inherited;
};


inline double
CPoint::getX() const
{
    return this->x;
    //return m_x;
}

inline double
CPoint::getY() const
{
    return this->y;
    //return m_y;
}

inline double
CPoint::getZ() const
{
    return this->z;
    //return m_z;
}


}}  // namespace Yogi::Graphics


#endif  // HPP_CPOINT
