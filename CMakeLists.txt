cmake_minimum_required(VERSION 3.15)
project(Iteratoren)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(Source)
add_executable(Iteratoren main.cpp)

include_directories(Source)

target_link_libraries(
        Iteratoren
        PUBLIC
        Source
        )