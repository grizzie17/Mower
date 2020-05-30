set(BINARY simulator_test)

file(GLOB TEST_SOURCES LIST_DIRECTORIES false *.cpp)
list(REMOVE_ITEM TEST_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

set(SOURCES ${TEST_SOURCES})
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0")


foreach(file ${TEST_SOURCES})
	set(name)
	get_filename_component(name ${file} NAME_WE)
	set(tname "simulator_${name}")
	add_executable("${tname}"
			${file}
			main.cpp
			)
	#add_dependencies("${tname}" Yogi_graphics_lib)
	target_link_libraries("${tname}" gtest)
	add_test(NAME ${name} COMMAND "${tname}")
	# add_custom_command(
	# 		TARGET ${tname}
	# 		COMMENT "Run test: ${tname}"
	# 		POST_BUILD
	# 		WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
	# 		COMMAND ${CMAKE_CTEST_COMMAND}  -R "^${tname}$" --output-on-failures
	# )
endforeach()

configure_file(
	"../environment.json" "environment.json" COPYONLY
)



# target_link_libraries(${BINARY} Yogi_graphics_lib gtest)
