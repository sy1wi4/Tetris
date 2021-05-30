cmake_minimum_required(VERSION 3.19)
project(Tetris)

set(CMAKE_CXX_STANDARD 14)

include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/lib)
#include_directories(.)

add_executable(Tetris
        main.cpp
        Pieces.cpp
        Pieces.h
        Piece.cpp
        Piece.h
        GUI.cpp
        GUI.h
        )

target_link_libraries(Tetris SDL2)
