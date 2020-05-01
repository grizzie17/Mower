set( BINARY Yogi_graphics_lib)

set( SOURCES
		CPoint.cpp
		CPoint.hpp
		CVector.cpp
		CVector.hpp
		CUnitVector.cpp
		CUnitVector.hpp
		)

# add_executable(${BINARY}_run ${SOURCES})
add_library(${BINARY} STATIC
		${SOURCES})
