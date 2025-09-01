cmake_minimum_required(VERSION 3.28)
project(4)

set(CMAKE_CXX_STANDARD 17)

add_executable(4 main.cpp
        PowerControl.cpp
        PowerControl.h
        ComfortPlate.cpp
        ComfortPlate.h
        Plate.cpp
        Plate.h)
