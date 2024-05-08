cmake_minimum_required(VERSION 3.27)
project(lab_02)

set(CMAKE_CXX_STANDARD 23)

add_compile_options(-Wall -Werror -Wextra)

add_executable(lab_02 main.cpp
        base_container.h
        list_node.hpp
        list_node.h
        list.h
        list.hpp
        list_iterator.h
        list_iterator.hpp
        const_list_iterator.h
        const_list_iterator.hpp
        concepts.h
        errors.h)
