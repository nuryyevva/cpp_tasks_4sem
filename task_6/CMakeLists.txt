cmake_minimum_required(VERSION 3.5)

project(task_6 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(task_6 main.cpp
                      checkpoint.h
                      checkpoint.cpp
                      checkpointbuilders.h
                      checkpointbuilders.cpp
                      checkpointmanager.h
                      checkpointmanager.cpp
                      trackbuilder.h
                      trackbuilder.cpp)

install(TARGETS task_6
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
