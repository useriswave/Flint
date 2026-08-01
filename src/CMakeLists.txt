cmake_minimum_required(VERSION 3.20)

set(
    CORE_SOURCES
    editor/Cursor.cpp
    editor/motions/Motions.cpp
    editor/buffer/Buffer.cpp
    editor/modes/InsertMode.cpp
    editor/modes/NormalMode.cpp
    editor/modes/VisualMode.cpp
    editor/EditingController.cpp
    editor/Editor.cpp
    persistence/FileHandler.cpp
    tui/Screen.cpp
)

add_library(
    FLINT_CORE
    STATIC
    ${CORE_SOURCES}
)

add_executable(
    ${PROJECT_NAME}
    app/main.cpp
    app/App.cpp
)

target_include_directories(
    FLINT_CORE
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CURSES_INCLUDE_DIRS}
)

target_link_libraries(
    FLINT_CORE
    PUBLIC
    ${CURSES_LIBRARIES}
)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
    FLINT_CORE
)
