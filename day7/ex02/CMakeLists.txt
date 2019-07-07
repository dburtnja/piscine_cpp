cmake_minimum_required(VERSION 3.14)
project(ex02)

set(CMAKE_CXX_STANDARD 17)

add_executable(ex02 main.cpp Array.hpp)

target_compile_options(ex02 PRIVATE -Wall -Wextra -Werror)
