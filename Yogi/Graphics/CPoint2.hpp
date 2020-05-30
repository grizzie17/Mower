#ifndef HPP_CPOINT2
#define HPP_CPOINT2

namespace Yogi { namespace Graphics {

class CPoint2
{
public:
	int x;
	int y;

	CPoint2();
	CPoint2( int x_, int y_ );
	CPoint2( const CPoint2& r );

	const CPoint2&
	operator=( const CPoint2& p );

	CPoint2
	operator-( const CPoint2& r ) const;
};

inline CPoint2::CPoint2()
		: x( 0 )
		, y( 0 )
{}
inline CPoint2::CPoint2( int x_, int y_ )
		: x( x_ )
		, y( y_ )
{}
inline CPoint2::CPoint2( const CPoint2& r )
		: x( r.x )
		, y( r.y )
{}

inline const CPoint2&
CPoint2::operator=( const CPoint2& p )
{
	x = p.x;
	y = p.y;
	return *this;
}

inline CPoint2
CPoint2::operator-( const CPoint2& r ) const
{
	return CPoint2( x - r.x, y - r.y );
}


}}    // namespace Yogi::Graphics

#endif    // HPP_CPOINT2
