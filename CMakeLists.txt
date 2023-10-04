cmake_minimum_required(VERSION 3.22)
project(COMP345_Warzone_Project)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(player)

add_executable(COMP345_Warzone_Project
        player/Player.cpp
        player/Player.h player/PlayerDriver.cpp)
