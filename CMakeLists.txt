cmake_minimum_required(VERSION 3.10)
project(problem_098 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(code main.cpp)

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
  target_compile_options(code PRIVATE -O2 -Wall -Wextra -Wconversion -Wshadow -Wformat=2 -Wundef -Wcast-qual -Wnon-virtual-dtor -Woverloaded-virtual -Wno-unused-parameter)
endif()
