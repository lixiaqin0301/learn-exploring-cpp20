cmake_minimum_required(VERSION 3.10)
project(exploring-cpp20 CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 让所有子目标能 #include 根目录下的 test.hpp
include_directories(${CMAKE_SOURCE_DIR})

# 遍历添加所有 chapXX 子目录
file(GLOB chapters RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "chap*")
foreach(chapter ${chapters})
    if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${chapter}/CMakeLists.txt")
        add_subdirectory(${chapter})
    endif()
endforeach()
