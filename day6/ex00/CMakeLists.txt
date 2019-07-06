cmake_minimum_required(VERSION 3.13)
project(ex00)

set(CMAKE_CXX_STANDARD 17)

add_executable(ex00 main.cpp)

target_compile_options(ex00 PRIVATE -Wall -Wextra -Werror)