# cmake_minimum_required(VERSION <specify CMake version here>)
project(ex1VM)

set(CMAKE_CXX_STANDARD 17)

add_executable(ex1VM tester.cpp Vector3D.cpp Vector3D.h Matrix3D.cpp Matrix3D.h)