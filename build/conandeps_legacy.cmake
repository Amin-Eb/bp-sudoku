message(STATUS "Conan: Using CMakeDeps conandeps_legacy.cmake aggregator via include()")
message(STATUS "Conan: It is recommended to use explicit find_package() per dependency instead")

find_package(gsl-lite)
find_package(GTest)

set(CONANDEPS_LEGACY  gsl::gsl-lite  gtest::gtest )