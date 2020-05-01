
add_library(
	utilities
	CMsgQueue.hpp
	CMsgQueue.cpp
	Interface.hpp
)

target_include_directories(utilities PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
