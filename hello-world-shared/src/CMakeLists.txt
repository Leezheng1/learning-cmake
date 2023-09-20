cmake_minimum_required(VERSION 3.19.0)

add_executable(main main.cpp)

include_directories(../include/hello)

find_library(HELLO_LIB NAMES hello PATHS "../lib/Debug/")

message(STATUS "Library path HELLO_LIB is " ${HELLO_LIB})

target_link_libraries(main ${HELLO_LIB})

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
