set( BINARY Yogi_graphics_lib)

set( SOURCES
		VDraw.hpp
		Draw.cpp
		Draw.hpp
		CPoint.cpp
		CPoint.hpp
		CPoint2.hpp
		CVector.cpp
		CVector.hpp
		CUnitVector.cpp
		CUnitVector.hpp
		CMatrix4x4.cpp
		CMatrix4x4.hpp
		CCamera.cpp
		CCamera.hpp
		)

# add_executable(${BINARY}_run ${SOURCES})
add_library(${BINARY} STATIC
		${SOURCES})


add_subdirectory(test)
