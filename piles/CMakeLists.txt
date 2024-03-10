cmake_minimum_required(VERSION 3.16)
project(piles C)

set(CMAKE_C_STANDARD 11)

add_executable(piles main.c
        stack.c
        element.c
        element.h
        queue.c
        queue.h)
