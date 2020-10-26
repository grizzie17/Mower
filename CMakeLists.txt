cmake_minimum_required(VERSION 3.15.0)

set( This Mower )
project(${This}
		VERSION 0.1.0
        LANGUAGES CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)


# include(cmake/StandardProjectSettings.cmake)
include(cmake-config/StandardProjectSettings.cmake)

if ( ${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR} )
	message(FATAL_ERROR "In-Source builds not allowed. Please run CMake from a 'build' directory.")
endif()

if (NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE "Release")
endif()
if ( CMAKE_BUILD_TYPE MATCHES Debug)
	add_definitions(-D_DEBUG=1 -DDEBUG=1 -UNDEBUG)
else()
	add_definitions(-DNDEBUG=1 -UDEBUG -U_DEBUG)
endif()

#set(CMAKE_EXECUTABLE_SUFFIX .exe)

# if (DEFINED ENV{NO_COLOR})
# 	message(STATUS "NO_COLOR environment variable present, disabling color output.")
# 	if (NOT DEFINED COLOR_DEBUG_NO_COLOR)
# 		message(STATUS "NO_COLOR environment variable present, disabling color output.")
# 	endif()
# 	set(cd_no_color_default ON)
# endif()

if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
	include(CTest)
endif()

include_directories(simulator)
include_directories(Yogi/Utilities)
include_directories(Yogi/Graphics)
include_directories(Yogi/Arduino)
include_directories(nlohmann_json/include)

add_subdirectory(Yogi/Utilities)
add_subdirectory(Yogi/Graphics)
add_subdirectory(Yogi/Arduino)
add_subdirectory(simulator)
add_subdirectory(base-station)


# test
add_subdirectory(googletest)


if ( CMAKE_BUILD_TYPE MATCHES Debug)
	add_definitions(-D_DEBUG=1)
	add_definitions(-DDEBUG=1)
else()
	add_definitions(-DNDEBUG=1)
endif()
