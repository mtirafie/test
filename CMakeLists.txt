cmake_minimum_required(VERSION 3.12)
project(Pacman)
set(CMAKE_CXX_STANDARD 11)
set(sources
	src/main.cpp
	src/tile.cpp
	src/map.cpp
	src/wall.cpp
	src/game.cpp
	src/pacman.cpp
	src/ghost.cpp
	src/blinky.cpp)
include_directories(header)
add_executable(exe ${sources})
target_link_libraries(exe sfml-graphics sfml-window sfml-audio sfml-system)