cmake_minimum_required(VERSION 3.5)
project(JINP_1_horror)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")

set(SOURCE_FILES
    citizen.h
    horror_example.cc
    monster.h
    README.md)

add_executable(JINP_1_horror ${SOURCE_FILES})