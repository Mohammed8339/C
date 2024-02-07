cmake_minimum_required(VERSION 3.28)
project(untitled C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled main.c)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})