cmake_minimum_required(VERSION 3.21)
project(TEST)

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(lib)

add_compile_options(-Wall -Wextra -pedantic)
find_package(Threads)

add_executable(TEST main.cpp)
target_link_libraries(TEST container pthread)
