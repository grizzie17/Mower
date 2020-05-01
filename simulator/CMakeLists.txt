
set(BINARY ${CMAKE_PROJECT_NAME})

set( SOURCES
		WinMain.cpp
		Simulator.cpp
		Environment.cpp
		Draw.cpp
		)

add_executable(${BINARY} ${SOURCES})
target_link_libraries(${PROJECT_NAME}
		Yogi_graphics_lib
		opengl32
		freeglut
		Glu32
		glew32
		gdi32)
