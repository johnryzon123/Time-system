cmake_minimum_required(VERSION 4.2)
project(code_file C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(code_file
        main.c
        util.c
        util.h)
