cmake_minimum_required(VERSION 3.19.0)

set(CMAKE_CXX_STANDARD 11)

#这里是自定义编译变量，通过在编译时给的值不同，来区分生成静态库还是动态库
option(BUILD_SHARED_LIBS "Specifies the type of libraries (SHARED or STATIC) to build" OFF)

# 设置源文件
set(LIBHELLO_SRC my_lib.cpp)

if (BUILD_SHARED_LIBS)
	#通过该配置设置在动态库时也导出符号，当前在my_lib.cpp 中使用_declspec(dllexport) 导出了，否则需要打开以下注释导出符号
	#set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

    add_library(hello_dynamic SHARED ${LIBHELLO_SRC})
    target_compile_definitions(hello_dynamic PUBLIC -DMY_LIB_SHARED_BUILD)
    target_compile_definitions(hello_dynamic PRIVATE -DMY_LIB_EXPORTS)
	
	#修改名称
	set_target_properties(hello_dynamic PROPERTIES OUTPUT_NAME "hello")
    set_target_properties(hello_dynamic PROPERTIES VERSION 1.2 SOVERSION 1)

else()
    add_library(hello_static STATIC ${LIBHELLO_SRC})
	set_target_properties(hello_static PROPERTIES OUTPUT_NAME "hello")
endif()

#设置输出目录
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

#install(TARGETS hello_dynamic hello_static
       # LIBRARY DESTINATION lib
       # ARCHIVE DESTINATION lib)
        
#install(FILES hello.h DESTINATION include/hello)
