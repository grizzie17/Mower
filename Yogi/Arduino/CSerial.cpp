
#include "CSerial.hpp"

#include <iomanip>
#include <iostream>

namespace Yogi { namespace Arduino {

CSerial::CSerial()
		: m_ss()
{}


CSerial::~CSerial()
{}

void
CSerial::begin( unsigned long uBaud )
{
	m_ss.str( std::string() );
}

void
CSerial::end()
{}

void
CSerial::print( const char* sString )
{
	m_ss << sString;
	std::cout << sString;
}

void
CSerial::print( int nVal, bases ebase )
{
	m_ss << nVal;
	std::cout << nVal;
}

void
CSerial::print( unsigned int nVal, bases ebase )
{
	m_ss << nVal;
	std::cout << nVal;
}

void
CSerial::print( long nVal, bases ebase )
{
	m_ss << nVal;
	std::cout << nVal;
}

void
CSerial::print( unsigned long nVal, bases ebase )
{
	m_ss << nVal;
	std::cout << nVal;
}

void
CSerial::print( double dVal, int nDigits )
{
	m_ss << std::setprecision( nDigits );
	m_ss << dVal;
	std::cout << std::setprecision( nDigits );
	std::cout << dVal;
}

void
CSerial::println( void )
{
	m_ss << std::endl;
	std::cout << std::endl;
}

void
CSerial::println( const char* sString )
{
	print( sString );
	println();
}

void
CSerial::println( int nVal, bases ebase )
{
	print( nVal, ebase );
	println();
}

void
CSerial::println( unsigned int nVal, bases ebase )
{
	print( nVal, ebase );
	println();
}

void
CSerial::println( long nVal, bases ebase )
{
	print( nVal, ebase );
	println();
}

void
CSerial::println( unsigned long nVal, bases ebase )
{
	print( nVal, ebase );
	println();
}

void
CSerial::println( double dVal, int nDigits )
{
	print( dVal, nDigits );
	println();
}

std::string
CSerial::to_str()
{
	std::string s = m_ss.str();
	m_ss.str( std::string() );
	return s;
}


}}    // namespace Yogi::Arduino
