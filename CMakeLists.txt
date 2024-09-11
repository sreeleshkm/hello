cmake_minimum_required(VERSION 3.0)

project(PERSONAL_DETAILS)

if(WIN32) 
    message(STATUS ">>> Windows")
    set(CMAKE_C_COMPILER gcc)
    # linux stuff here
elseif(UNIX)
    message(STATUS ">>> Linux")
    set(CMAKE_C_COMPILER arm-linux-gnueabihf-gcc)
    # stuff that should happen not on Linux 
endif()

set (SOURCE main.c)

add_executable(${PROJECT_NAME} ${SOURCE})