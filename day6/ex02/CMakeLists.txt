cmake_minimum_required(VERSION 3.14)
project(ex02)

set(CMAKE_CXX_STANDARD 17)

add_executable(ex02 main.cpp A.cpp A.hpp Base.cpp Base.hpp B.cpp B.hpp C.cpp C.hpp)