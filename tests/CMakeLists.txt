include(${CMAKE_BINARY_DIR}/conan_toolchain.cmake)
find_package(GTest REQUIRED)

add_executable(FileTests FileTests.cpp)
add_executable(CoreTests CoreTests.cpp)
add_executable(UserTests UserTests.cpp)

target_link_libraries(FileTests PRIVATE 
	file 
	GTest::gtest_main
    GTest::GTest
    GTest::gmock
    GTest::gmock_main
)
target_link_libraries(CoreTests PRIVATE 
	core
	GTest::gtest_main
    GTest::GTest
    GTest::gmock
    GTest::gmock_main
)
target_link_libraries(UserTests PRIVATE 
	user 
	GTest::gtest_main
    GTest::GTest
    GTest::gmock
    GTest::gmock_main
)


add_test(NAME FileTests COMMAND FileTests)
add_test(NAME CoreTests COMMAND CoreTests)
add_test(NAME UserTests COMMAND UserTests)

