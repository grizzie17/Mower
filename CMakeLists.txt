project(Mower)
cmake_minimum_required(VERSION 3.10.0)

set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_COMPILER C:\msys64\mingw64\bin\x86_64-w64-mingw32-g++.exe)

# include(CTest)
# enable_testing()

add_subdirectory( utilities )
add_subdirectory( display )


add_executable(Mower main.cpp)

target_link_libraries(Mower PRIVATE display)

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)
