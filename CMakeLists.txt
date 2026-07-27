cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(Flint VERSION 0.0 LANGUAGES CXX)

find_package(Curses REQUIRED)

set(
    SRC_FILES
    src/app/main.cpp
    src/app/App.cpp
    src/editor/buffer/Buffer.cpp
    src/editor/modes/InsertMode.cpp
    src/editor/modes/NormalMode.cpp
    src/editor/modes/VisualMode.cpp
    src/editor/navigation/INavigatable.cpp
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
target_link_libraries(${PROJECT_NAME} PRIVATE ${CURSES_LIBRARIES})
