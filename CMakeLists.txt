cmake_minimum_required(VERSION 3.27)
project(TicTacToe_SFML)

set(CMAKE_CXX_STANDARD 17)

add_executable(TicTacToe_SFML main.cpp
        classes/Sprites.h
        classes/Sprites.cpp
        functions.cpp
        functions.h
        definitions.h
        classes/CircleSprite.cpp
        classes/CircleSprite.h
        classes/CrossSprite.cpp
        classes/CrossSprite.h
)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML-2.6.1/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)


target_link_libraries(TicTacToe_SFML sfml-system sfml-window sfml-graphics sfml-audio)