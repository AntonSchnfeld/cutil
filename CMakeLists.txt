cmake_minimum_required(VERSION 3.26)
project(untitled2 C)

set(CMAKE_C_STANDARD 99)

add_executable(cutil main.c
        include/datastructures.h
        impl/linkedlist.c
        include/linkedlist.h
        include/debug.h
        include/arraylist.h
        impl/arraylist.c)
