cmake_minimum_required(VERSION 3.19)
project(Tetris)

set(CMAKE_CXX_STANDARD 14)

include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/lib)
#include_directories(.)

add_executable(Tetris
        src/main.cpp
        src/Pieces.cpp
        src/Pieces.h
        src/Piece.cpp
        src/Piece.h
        src/GUI.cpp
        src/GUI.h
        src/Game.cpp
        src/Game.h
        src/GameBoard.cpp
        src/GameBoard.h
        )

target_link_libraries(Tetris SDL2)
