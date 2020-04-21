cmake_minimum_required(VERSION 3.10.0)
project(Mower
		VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_COMPILER C:\msys64\mingw64\bin\x86_64-w64-mingw32-g++.exe)

# include(CTest)
# enable_testing()

# add_subdirectory( utilities )
# add_subdirectory( display )

include_directories( simulator )

set(SOURCE
		simulator/WinMain.cpp
		simulator/Simulator.cpp
		simulator/Environment.cpp
		simulator/Draw.cpp)


add_executable(${PROJECT_NAME} ${SOURCE})

target_link_libraries(${PROJECT_NAME}
		opengl32
		freeglut
		Glu32
		glew32
		gdi32)

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)
