cmake_minimum_required(VERSION 3.26)
project(dataStruct C)

set(CMAKE_C_STANDARD 11)

add_executable(dataStruct main.c
        LinkList.h
        cmake-build-debug/SqList.cpp
        SqList.h
        Stack.h
        Strings.h
)
