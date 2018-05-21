cmake_minimum_required(VERSION 3.10)
project(Lab_5_6)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

set(CMAKE_CXX_FLAGS "-g -O0 -Wall -fprofile -ftest-coverage")
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE 1)

add_executable(Lab_5_6
        Controller.cpp
        Controller.h
        DynamicArray.cpp
        DynamicArray.h
        Filter.cpp
        Filter.h
        main.cpp
        Repo.cpp
        Repo.h
        Tutorial.cpp
        Tutorial.h
        UI.cpp
        UI.h
        Watchlist.cpp
        Watchlist.h)
