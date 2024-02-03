cmake_minimum_required(VERSION 3.27)
project(TicTacToe_SFML)

set(CMAKE_CXX_STANDARD 17)

add_executable(TicTacToe_SFML main.cpp
        sprites.h
        sprites.cpp
        sprites.cpp
)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML-2.6.1/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)


include_directories(C:/Users/lucai/Documents/c/TicTacToe_SFML)
target_link_libraries(TicTacToe_SFML sfml-system sfml-window sfml-graphics sfml-audio)