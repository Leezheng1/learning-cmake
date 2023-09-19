cmake_minimum_required(VERSION 3.19.0)

set(CMAKE_CXX_STANDARD 11)

# 导入库头文件目录
include_directories(${PROJECT_SOURCE_DIR}/libhello)

# 添加库文件所在的目录
link_directories(${PROJECT_BINARY_DIR}/lib)

set(LIBHELLO_SRC main.cpp)

#设置输出目录
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

add_executable(hellomain ${LIBHELLO_SRC})

target_link_libraries(hellomain hello)

