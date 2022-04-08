cmake_minimum_required(VERSION 3.10)

project(super_tetris)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_COMPILER /usr/bin/g++)
set(CMAKE_CXX_FLAGS "-Wall -Werror -Wextra")
set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SRC src/*)

add_executable(tetris ${SRC})
