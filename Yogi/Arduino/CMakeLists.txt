set( BINARY Yogi_arduino_lib)

set( SOURCES
		arduino.cpp
		arduino.hpp
		CSerial.cpp
		CSerial.hpp
		)

add_library(${BINARY} STATIC
		${SOURCES})
