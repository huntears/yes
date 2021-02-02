cmake_minimum_required(VERSION 3.17)
project(libyes)

set(CMAKE_CXX_STANDARD 14)

add_executable(libyes main.cpp Vec2.hpp Vec3.hpp Vec4.hpp Mat.hpp Vec.hpp)