
add_library(
	display
	Draw.cpp
	Draw.hpp
	VDraw.hpp
)

target_include_directories(display PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
