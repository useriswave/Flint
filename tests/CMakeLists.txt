cmake_minimum_required(VERSION 3.20)

#set(TEST_SOURCES
#    INavigatableTests.cpp
#    ${PROJECT_SOURCE_DIR}/src/app/main.cpp
#    ${PROJECT_SOURCE_DIR}/src/app/App.cpp
#    ${PROJECT_SOURCE_DIR}/src/editor/buffer/Buffer.cpp
#    ${PROJECT_SOURCE_DIR}/src/editor/modes/InsertMode.cpp
#    ${PROJECT_SOURCE_DIR}/src/editor/modes/NormalMode.cpp
#    ${PROJECT_SOURCE_DIR}/src/editor/modes/VisualMode.cpp
#    ${PROJECT_SOURCE_DIR}/src/editor/navigation/INavigatable.cpp
#    ${PROJECT_SOURCE_DIR}/src/editor/Editor.cpp
#    ${PROJECT_SOURCE_DIR}/src/persistence/FileHandler.cpp
#    ${PROJECT_SOURCE_DIR}/src/tui/Screen.cpp
#)

set(TEST_SOURCES
    INavigatableTests.cpp
    ${PROJECT_SOURCE_DIR}/src/editor/buffer/Buffer.cpp
    ${PROJECT_SOURCE_DIR}/src/editor/modes/NormalMode.cpp
    ${PROJECT_SOURCE_DIR}/src/editor/navigation/INavigatable.cpp
)


set(TEST_TARGET FlintTests)
set(TEST_SUITE GoogleTest)

include(FetchContent)
FetchContent_Declare(
    ${TEST_SUITE}
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.17.0
)

FetchContent_MakeAvailable(${TEST_SUITE})

add_executable(
    ${TEST_TARGET}
    ${TEST_SOURCES}
)

target_include_directories(${TEST_TARGET} PRIVATE ${PROJECT_SOURCE_DIR}/src)

target_link_libraries(
    ${TEST_TARGET}
    GTest::gtest
    GTest::gtest_main
)

include(${TEST_SUITE})
gtest_discover_tests(${TEST_TARGET})
