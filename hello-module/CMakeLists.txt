cmake_minimum_required(VERSION 3.19.0)

project(hello)

# Module模式下，会首先在CMAKE_MODULE_PATH路径下进行库cmake文件的搜索，如果没找到，则会采取Config模式
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

add_subdirectory(src)
