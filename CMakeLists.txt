cmake_minimum_required(VERSION 3.22)

project(task01)

set(CMAKE_CXX_STANDARD 23)

add_executable (${CMAKE_PROJECT_NAME} src/main.cpp src/Vector.cpp include/Vector.h src/Stack.cpp include/Stack.h)

add_subdirectory (include)
add_subdirectory (src)
