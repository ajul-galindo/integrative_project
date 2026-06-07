cmake_minimum_required(VERSION 4.0)
project(integrative_project)

set(CMAKE_CXX_STANDARD 26)

add_executable(integrative_project main.cpp
        Video.cpp
        Video.h
        Movies.cpp
        Movies.h
        Episodes.cpp
        Episodes.h)
