cmake_minimum_required(VERSION 3.29)
project(ConjGrad_solver)

set(CMAKE_CXX_STANDARD 17)

add_executable(ConjGrad_solver main.cpp
        utils.cpp
        utils.h
        solver.cpp
        solver.h
        matrix_io.cpp
        matrix_io.h
)
