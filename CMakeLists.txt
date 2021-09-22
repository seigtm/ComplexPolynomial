cmake_minimum_required(VERSION 3.5)
project(PolyComplex VERSION 1.0.1 LANGUAGES CXX)
message("!- Project: " ${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

add_executable(main main.cpp ut/tests.cpp)
target_include_directories(main
        PUBLIC
            ${PROJECT_SOURCE_DIR}/ut
    )

target_link_libraries(main PRIVATE CONAN_PKG::gtest CONAN_PKG::Polynomial CONAN_PKG::Complex)
