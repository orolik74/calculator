cmake_minimum_required(VERSION 3.16)
project(calculator CXX)
set(CMAKE_CXX_STANDARD 20)
add_executable(calculator src/main.cpp
        src/calculator.cpp
        include/calculator.h)
target_include_directories(calculator PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_options(calculator PRIVATE -Wall -Wextra -Werror)