cmake_minimum_required(VERSION 3.5)

project(constexpr LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(constexpr constexpr.cpp)
target_compile_options(constexpr PRIVATE "-fconstexpr-steps=999999999")

add_executable(runtime runtime.cpp)
