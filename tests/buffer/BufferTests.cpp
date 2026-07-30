#include "editor/buffer/Buffer.hpp"

#include <gtest/gtest.h>

TEST(BufferTest, BufferDeletesLastCharacterOfLine)
{
    Buffer buffer{};

    std::string text{ "Hello World" };

    for (int i{}; i < text.length(); ++i) {
        buffer.insertCharacter(0, i, text[i]);
    }

    buffer.deleteCharacter(0, text.length());
    const auto& currentLine{ buffer.getText(0) };

    EXPECT_EQ(currentLine, "Hello Worl");
}

TEST(BufferTest, BackspaceAtFirstLetterDeletesFirstChar)
{
    Buffer buffer{};

    std::string text{ "THISISATEST" };

    for (int i{}; i < text.length(); ++i) {
        buffer.insertCharacter(0, i, text[i]);
    }

    buffer.deleteCharacter(0, 1);
    const auto& currentLine{ buffer.getText(0) };

    EXPECT_EQ(currentLine, "THISISATEST");

}
