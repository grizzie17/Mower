
set(ARDUINO_DIR
	../Yogi/Arduino)

set(SOURCES
	basestation.cpp
	)


add_executable(basestation
	${SOURCES})

add_dependencies(basestation Yogi_arduino_lib)
target_link_libraries(basestation Yogi_arduino_lib)
