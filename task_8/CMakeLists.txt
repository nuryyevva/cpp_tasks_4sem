cmake_minimum_required(VERSION 3.5)

project(task_8 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(task_8 main.cpp
                      expression_factory.h
                      operators.h)

install(TARGETS task_8
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
