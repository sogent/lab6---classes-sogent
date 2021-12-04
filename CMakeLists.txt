cmake_minimum_required(VERSION 3.20)
project(lab6---classes-sogent)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lab6---classes-sogent
        Lab06.cpp
        README.md LibraryBook.cpp LibraryBook.h)