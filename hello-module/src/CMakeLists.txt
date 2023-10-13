cmake_minimum_required(VERSION 2.8.4)

# 默认Module模式，会在CMAKE_MODULE_PATH 查找 FINDHELLO.cmake 文件，每一个模块都会定义以下几个变量
# <LibaryName>_FOUND
# <LibaryName>_INCLUDE_DIR or <LibaryName>_INCLUDES
# <LibaryName>_LIBRARY or <LibaryName>_LIBRARIES
find_package(HELLO)

if(HELLO_FOUND)
  add_executable(hello main.cpp)
  include_directories(${HELLO_INCLUDE_DIR})
  target_link_libraries(hello ${HELLO_LIBRARY})
else(HELLO_FOUND)
  message(FATAL_ERROR "HELLO library not found")
endif(HELLO_FOUND)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
