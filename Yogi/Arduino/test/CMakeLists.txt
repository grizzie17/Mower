set(BINARY Yogi_arduino_test)

file(GLOB TEST_SOURCES LIST_DIRECTORIES false *.cpp)
list(REMOVE_ITEM TEST_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

set(SOURCES ${TEST_SOURCES})
# add_executable(${BINARY} ${SOURCES})
# add_test(NAME ${BINARY} COMMAND ${BINARY})
# add_custom_command(
# 	TARGET ${BINARY}
# 	COMMENT "Run Tests"
# 	POST_BUILD
# 	WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
# 	COMMAND ${CMAKE_CTEST_COMMAND} -C $<CONFIGURATION> -R "^${UNIT_TEST}$" --output-on-failures
# )


foreach(file ${TEST_SOURCES})
	set(name)
	get_filename_component(name ${file} NAME_WE)
	set(tname "yogi_arduino_${name}")
	add_executable("${tname}"
			${file}
			main.cpp
			)
	add_dependencies("${tname}" Yogi_arduino_lib)
	target_link_libraries("${tname}" Yogi_arduino_lib gtest)
	add_test(NAME ${name} COMMAND "${tname}")
	# add_custom_command(
	# 	TARGET "${name}_tests"
	# 	COMMENT "Run Tests"
	# 	POST_BUILD
	# 	WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
	# 	COMMAND ${CMAKE_CTEST_COMMAND} -C $<CONFIGURATION> -R "^${UNIT_TEST}$" --output-on-failures
	# )
endforeach()
# add_custom_command(OUTPUT foo
# 		COMMAND touch foo
# 		)
# add_custom_command(
# 	TARGET foo
# 	COMMENT "Run Tests"
# 	POST_BUILD
# 	WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
# 	COMMAND ${CMAKE_CTEST_COMMAND} -C $<CONFIGURATION> --output-on-failures
# 	DEPENDS foo
# )



# target_link_libraries(${BINARY} Yogi_graphics_lib gtest)
