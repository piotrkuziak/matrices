cmake_minimum_required(VERSION 3.10)
project(matrices)

set(CMAKE_CXX_STANDARD 11)

add_executable(matrices main.cpp functions.h getdata.cpp creatematrix.cpp populatematrix.cpp)