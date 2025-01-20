cmake_minimum_required(VERSION 3.22.1)
project(sudoku)

set(cmake_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

add_subdirectory(src)
add_subdirectory(tests)

add_executable(sudoku sudoku.cpp)
target_link_libraries(sudoku PRIVATE file core user)
target_compile_options(sudoku PRIVATE -lncurces)
