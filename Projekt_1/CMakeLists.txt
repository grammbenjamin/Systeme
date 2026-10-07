cmake_minimum_required(VERSION 4.3)
project(Projekt_1 C)

set(CMAKE_C_STANDARD 99)

add_executable(Projekt_1 main.c linkedlist.c
        doublelinkedlist.c
        doublelinkedlist.h)
