
set(BINARY ${CMAKE_PROJECT_NAME})

include_directories(nlohmann_json/include)


set( SOURCES
		Mower.cpp
		Simulator.cpp
		Simulator.hpp
		Environment.cpp
		Environment.hpp
		)

add_executable(${BINARY} ${SOURCES})
add_dependencies(${BINARY} Yogi_graphics_lib Yogi_utilities_lib)
target_link_libraries(${PROJECT_NAME}
		Yogi_graphics_lib
		Yogi_utilities_lib
		opengl32
		freeglut
		Glu32
		glew32
		gdi32)

add_subdirectory(test)

configure_file(
	"environment.json" "environment.json" COPYONLY
)
