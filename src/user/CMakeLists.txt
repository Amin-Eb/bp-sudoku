add_library(user STATIC User.cpp)

target_include_directories(user PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
