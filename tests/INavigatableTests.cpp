#include "editor/modes/NormalMode.hpp"
#include "editor/buffer/Buffer.hpp"
#include "editor/Cursor.hpp"
#include "editor/modes/ModeType.hpp"

#include <gtest/gtest.h>

TEST(CursorNavigationTest, CursorMustGoDown)
{
    Buffer buffer{};
    Cursor cursor{};
    ModeType modeType { ModeType::normal };
    NormalMode normalMode{buffer, cursor, modeType};

    // buffer.insertCharacter(int row, int col, char c);
}
