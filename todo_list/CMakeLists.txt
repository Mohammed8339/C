cmake_minimum_required(VERSION 3.28)
project(todo_list)

set(CMAKE_CXX_STANDARD 17)

add_executable(todo_list
        main.c
        linkedList.h
        linkedList.c)
