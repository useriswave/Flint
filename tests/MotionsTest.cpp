#include "../editor/motions/Motions.hpp"
#include "../editor/buffer/Buffer.hpp"
#include "../editor/Editor.hpp"

#include "../editor/Cursor.hpp"

#include <iostream>
#include <cassert>

void fillLines(Buffer& buffer, Cursor& cursor, const std::string_view& line)
{
    for (const auto& c : line) {
        buffer.insertCharacter(cursor.row, cursor.col, c);
    }
}

int main()
{
    Buffer buffer{};
    Cursor cursor{};
    Motions motions{};
    Editor editor{};

    editor.init();
    std::string line{ "Hello World" };

    editor.moveRight();

    for (const auto& c : line) {
        editor.outputCharacter(c);
    }

    Cursor c { editor.getCursor() };
    std::cout << "Row: " << c.row << ", Col: " << c.col << ", saved col: " << c.savedCol << " Len: " << line.length() << '\n';
    assert(c.col == line.length());
}
