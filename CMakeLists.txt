cmake_minimum_required(VERSION 3.29)
project(OOP_v_pradin_)

set(CMAKE_CXX_STANDARD 14)


add_executable(Projektas
        header.h
        main.cpp
        Struct.cpp
        Struct.h)

add_executable(ProjektasTests
        testai/Tests.cpp
       )

find_package(GTest REQUIRED)
target_link_libraries(ProjektasTests GTest::gtest GTest::gtest_main)
enable_testing()
add_test(NAME ProjektasTests COMMAND ProjektasTests)
