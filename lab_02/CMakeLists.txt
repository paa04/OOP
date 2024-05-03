cmake_minimum_required(VERSION 3.27)
project(lab_02)

set(CMAKE_CXX_STANDARD 23)

add_executable(lab_02 main.cpp
        base_container.h
        list_item.hpp
        list_node.h
        list.h
        list.hpp
        list_iterator.h
        list_iterator.hpp)
