#ifndef H_ORIENTEDPOINT
#define H_ORIENTEDPOINT

namespace Yogi { namespace Graphics {


class CPoint
{
public:
	CPoint();
	CPoint( double x, double y, double z );
	CPoint( CPoint& r );
	~CPoint();

public:
	virtual void
	set( double x, double y, double z );

	virtual void
	setX( double x );

	virtual void
	setY( double y );

	virtual void
	setZ( double y );

	double
	getX();

	double
	getY();

	double
	getZ();

	bool
	operator==( const CPoint& r ) const;

protected:
	double m_x;
	double m_y;
	double m_z;
};

inline double
CPoint::getX()
{
	return m_x;
}

inline double
CPoint::getY()
{
	return m_y;
}

inline double
CPoint::getZ()
{
	return m_z;
}

}}    // namespace Yogi::Graphics


#endif    // H_ORIENTEDPOINT
