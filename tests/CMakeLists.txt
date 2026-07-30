cmake_minimum_required(VERSION 3.20)

set(
    TEST_SOURCES
    MotionsTest.cpp
)

include(FetchContent)
FetchContent_Declare(
    GoogleTest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.17.0
)

FetchContent_MakeAvailable(GoogleTest)

add_executable(
    FLINT_TESTS
    ${TEST_SOURCES}
)

target_link_libraries(
    FLINT_TESTS
    PRIVATE
    FLINT_CORE
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(FLINT_TESTS)
