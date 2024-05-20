cmake_minimum_required(VERSION 3.5)

project(task_7 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(task_7 main.cpp
                      abstraction.h
                      abstraction.cpp
                      implementation.h
                      implementation.cpp)

install(TARGETS task_7
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
