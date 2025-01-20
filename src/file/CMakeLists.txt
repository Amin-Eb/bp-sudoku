add_library(file STATIC File.cpp)

target_include_directories(file PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
