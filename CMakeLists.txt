cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(Flint VERSION 0.0 LANGUAGES CXX)

set(CURSES_NEED_NCURSES TRUE)
find_package(Curses REQUIRED)

if(NOT CURSES_FOUND)
    message(FATAL_ERROR "NCurses has not been found on your system.")
else()
    message(STATUS "NCurses has been found on your system.")
endif()

set(
    SRC_FILES
    src/app/main.cpp
    src/app/App.cpp
    src/editor/motions/Motions.cpp
    src/editor/buffer/Buffer.cpp
    src/editor/modes/InsertMode.cpp
    src/editor/modes/NormalMode.cpp
    src/editor/modes/VisualMode.cpp
    src/editor/Editor.cpp
    src/persistence/FileHandler.cpp
    src/tui/Screen.cpp
)

add_executable(
    ${PROJECT_NAME}
    ${SRC_FILES}
)

target_include_directories(
    ${PROJECT_NAME}
    PRIVATE
    ${PROJECT_SOURCE_DIR}/src
    ${CURSES_INCLUDE_DIRS}
)

# enable_testing()
# add_subdirectory(tests)
 
target_link_libraries(${PROJECT_NAME} PRIVATE ${CURSES_LIBRARIES})
