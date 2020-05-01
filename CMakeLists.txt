cmake_minimum_required(VERSION 3.15.0)
project(Mower
		VERSION 0.1.0
		LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
	include(CTest)
endif()

include_directories(simulator)
include_directories(Yogi/Graphics)
include_directories(Yogi/Arduino)

add_subdirectory(Yogi/Graphics)
add_subdirectory(Yogi/Arduino)
add_subdirectory(simulator)
add_subdirectory(base-station)


# test
add_subdirectory(googletest)
add_subdirectory(Yogi/Graphics/test)
add_subdirectory(Yogi/Arduino/test)

# set(SOURCE
# 		simulator/WinMain.cpp
# 		simulator/Simulator.cpp
# 		simulator/Environment.cpp
# 		simulator/Draw.cpp
# 		Yogi/Graphics/Point.cpp
# 		Yogi/Graphics/Vector.cpp
# 		)


# add_executable(${PROJECT_NAME} ${SOURCE})
# target_link_libraries(${PROJECT_NAME}
# 		opengl32
# 		freeglut
# 		Glu32
# 		glew32
# 		gdi32)

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)

if ( CMAKE_BUILD_TYPE MATCHES Debug)
	add_definitions(-D_DEBUG=1)
	add_definitions(-DDEBUG=1)
else()
	add_definitions(-DNDEBUG=1)
endif()
