cmake_minimum_required(VERSION 3.2)
project(my_first_real_strategy)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -pthread")

set(SOURCE_FILES main.cpp main_lib.h human_tree.h dark_fraction.h)
add_executable(my_first_real_strategy ${SOURCE_FILES})