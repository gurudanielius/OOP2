cmake_minimum_required(VERSION 3.29)
project(OOP_v_pradin_)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(OOP_v_pradin_
    header.h
    main.cpp
    Struct.cpp
    Struct.h)
set(CMAKE_CXX_FLAGS "-O3") 
