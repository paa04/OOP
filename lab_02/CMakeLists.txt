cmake_minimum_required(VERSION 3.28)
project(lab_02)

set(CMAKE_CXX_STANDARD 20)

include_directories(${CMAKE_SOURCE_DIR})

add_executable(lab_02 main.cpp
        list.hpp
        base_container.hpp
        list.h
        list_node.h
        list_node.hpp
        iterator.h
        iterator.hpp
        const_iterator.h
        const_iterator.hpp)