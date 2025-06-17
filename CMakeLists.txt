cmake_minimum_required(VERSION 3.0)

project(HELLO)

set(CMAKE_C_COMPILER gcc)

set (SOURCE main.c)

add_executable(hello ${SOURCE})
