#include "editor/Editor.hpp"
#include "editor/Cursor.hpp"
#include "editor/EditorKeys.hpp"


#include <gtest/gtest.h>

TEST(CursorMovementRelativeToLine, CursorPositionStaysAheadOfLineByOneCol)
{
    Editor editor{};
    editor.init();

    std::string line{ "Hello World" };

    for (const auto& c : line) {
        editor.outputCharacter(c);
    };

    constexpr int expectedRow{};
    const int expectedCol{ static_cast<int>(line.length()) };
    const auto& cursor{ editor.getCursor() };

    EXPECT_EQ(expectedRow, cursor.row());
    EXPECT_EQ(expectedCol, cursor.col());
}

TEST(CursorMovementRelativeToLine, CursorPositionDoesNotStayBehindLineByOne)
{
    Editor editor{};
    editor.init();

    std::string line{ "Hello World" };

    for (const auto& c : line) {
        editor.outputCharacter(c);
    };

    constexpr int expectedRow{};
    int expectedCol{ static_cast<int>(line.length()) - 1};
    const auto& cursor{ editor.getCursor() };

    EXPECT_EQ(expectedRow, cursor.row());
    EXPECT_NE(expectedCol, cursor.col());
}

TEST(CursorMovementRelativeToLine, CursorPositionGoesDownOneRowAndColZeroOnEnterKeyPress)
{
    Editor editor{};
    editor.init();

    editor.handleInput('i');
    std::string line{ "Hello World\n" };

    for (const auto& c : line) {
        editor.handleInput(c);
    };

    constexpr int expectedRow{ 1 };
    int expectedCol{};
    const auto& cursor{ editor.getCursor() };

    EXPECT_EQ(expectedCol, cursor.col());
    EXPECT_EQ(expectedRow, cursor.row());
}

TEST(CursorMovementRelativeToLine, PressingKeyIMovesCursorLeftOnce)
{
    Editor editor{};
    editor.init();

    editor.handleInput('i');

    std::string line{ "Hello World" };
    for (const auto& c : line) {
        editor.handleInput(c);
    };

    editor.handleInput(EditorKeys::ESCAPE);
    editor.handleInput('i');

    int expectedRow{};
    const int expectedCol{  static_cast<int>(line.length()) - 1 };
    const auto& cursor{ editor.getCursor() };

    EXPECT_EQ(expectedCol, cursor.col());
    EXPECT_EQ(expectedRow, cursor.row());
}

TEST(CursorMovementRelativeToLine, TypingALineThenGoingToNormalModeThenInsertModeWithKeyIAndTypingAgainPlacesCursorAtLastLinesCol)
{
    Editor editor{};
    editor.init();

    editor.handleInput('i');

    std::string line{ "Hello World" };
    for (const auto& c : line) {
        editor.handleInput(c);
    };

    editor.handleInput(EditorKeys::ESCAPE);
    editor.handleInput('i');

    for (const auto& c : line) {
        editor.handleInput(c);
    };

    int expectedRow{};
    const int expectedCol{ 21 };
    const auto& cursor{ editor.getCursor() };

    EXPECT_EQ(expectedCol, cursor.col());
    EXPECT_EQ(expectedRow, cursor.row());
}

TEST(CursorMovementRelativeToLine, TypingALineThenSwitchingToInsertModeWithKeyIAndTypingAgainDoesNotPlaceCursorAtEndOfLineWithOneOffset)
{
    Editor editor{};
    editor.init();

    editor.handleInput('i');

    std::string line{ "Hello World" };
    for (const auto& c : line) {
        editor.handleInput(c);
    };

    editor.handleInput(EditorKeys::ESCAPE);
    editor.handleInput('i');

    for (const auto& c : line) {
        editor.handleInput(c);
    };

    int expectedRow{};
    const int nonExpectedCol{ 22 };
    const auto& cursor{ editor.getCursor() };

    EXPECT_NE(nonExpectedCol, cursor.col());
    EXPECT_EQ(expectedRow, cursor.row());
}


