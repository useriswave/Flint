#include "editor/motions/Motions.hpp"
#include "editor/buffer/Buffer.hpp"
#include "editor/Editor.hpp"

#include "editor/Cursor.hpp"

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
    Editor editor{};

    editor.init();
    std::string line{ "Hello World" };

    editor.moveRight();

    for (const auto& c : line) {
        editor.outputCharacter(c);
    }

    const auto& cursor{ editor.getCursor() };
    std::cout << "Row: " << cursor.row << ", Col: " << cursor.col << ", saved col: " << cursor.savedCol << " Len: " << line.length() << '\n';
    assert(cursor.col == line.length());
}
