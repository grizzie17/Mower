set( BINARY Yogi_utilities_lib)

set( SOURCES
		math_helper.cpp
		math_helper.hpp
		TArray2.hpp
		)

# add_executable(${BINARY}_run ${SOURCES})
add_library(${BINARY} STATIC
		${SOURCES})


add_subdirectory(test)
