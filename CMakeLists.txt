cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(Flint VERSION 1.0 LANGUAGES CXX)

set(CURSES_NEED_NCURSES TRUE)
find_package(Curses REQUIRED)

if(NOT CURSES_FOUND)
    message(FATAL_ERROR "NCurses has not been found on your system.")
else()
    message(STATUS "NCurses has been found on your system.")
endif()

add_subdirectory(src)

include(CTest)

if(BUILD_TESTING)
    add_subdirectory(tests)
endif()
