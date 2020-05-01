
#ifndef HPP_CSerial
#define HPP_CSerial

#include <iostream>
#include <sstream>


namespace Yogi { namespace Arduino {

class CSerial
{
public:
	CSerial();
	CSerial( std::ostream* ios );
	~CSerial();

public:
	typedef enum
	{
		BIN = 2,
		OCT = 8,
		DEC = 10,
		HEX = 16
	} bases;


	void
	begin( unsigned long uBaud );

	void
	end();

	void
	print( const char* sString );

	void
	print( int nVal, bases ebase = DEC );

	void
	print( unsigned int nVal, bases ebase = DEC );

	void
	print( long nVal, bases ebase = DEC );

	void
	print( unsigned long nVal, bases ebase = DEC );

	void
	print( double dVal, int nDigits = 2 );


	void
	println( void );

	void
	println( const char* sString );

	void
	println( int nVal, bases ebase = DEC );

	void
	println( unsigned int nVal, bases ebase = DEC );

	void
	println( long nVal, bases ebase = DEC );

	void
	println( unsigned long nVal, bases ebase = DEC );

	void
	println( double dVal, int nDigits = 2 );

	std::string
	to_str();

protected:
	std::stringstream m_ss;
	std::ostream*     m_pOut;
};

}}    // namespace Yogi::Arduino


#endif    // HPP_CSerial
