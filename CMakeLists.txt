cmake_minimum_required(VERSION 3.12)
project(cpp_project)

# CppUTest
include(FetchContent)
FetchContent_Declare(
    CppUTest
    GIT_REPOSITORY https://github.com/cpputest/cpputest.git
    GIT_TAG        master # or use release tag, eg. v4.0
)
# Set this to ON if you want to have the CppUTests in your project as well.
set(TESTS OFF CACHE BOOL "Switch off CppUTest Test build")
FetchContent_MakeAvailable(CppUTest)

set(HEADERS source/VanillaOption.h)
set(SOURCES tests/AllTests.cpp tests/EuropeanVanillaOptionTest.cpp source/VanillaOption.cpp)

add_executable(tests ${SOURCES} ${HEADERS})
target_include_directories(tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/source)

target_link_libraries(tests PRIVATE
    CppUTest::CppUTest
    CppUTest::CppUTestExt)