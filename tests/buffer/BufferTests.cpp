#include "editor/Editor.cpp"
#include "editor/EditingController.hpp"

#include <gtest/gtest.h>
#include <ncurses.h>

TEST(BufferTest, BufferDeletesLastCharacterOfLine)
{
    EditingController controller{};

    std::string text{ "Hello World" };

    for (int i{}; i < text.length() - 1; ++i) {
        controller.addCharacter(text[i]);
    }

    controller.backspace();
    const auto& currentLine{ controller.currentLine() };

    EXPECT_EQ(currentLine, "Hello Worl");
}

TEST(BufferTest, BackspaceAtFirstLetterDeletesFirstChar)
{
    EditingController controller{};
    std::string text{ "Hello World" };

    for (std::size_t i{}; i < text.length(); ++i) {
        controller.addCharacter(text[i]);
    }

    controller.moveToStartLine();
    controller.moveRight();
    controller.backspace();

    const auto& current{ controller.currentLine() };

    EXPECT_EQ(current, "ello World");
}
