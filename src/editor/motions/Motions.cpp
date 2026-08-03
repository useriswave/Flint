#include "editor/motions/Motions.hpp"

void Motions::moveUp(Cursor& cursor, const Buffer& buffer)
{
    if (cursor.row() > 0) {
        const auto& previousLine{ buffer.getText(cursor.row() - 1) };
        const auto previousCols{ previousLine.empty() ? 0 : static_cast<int>(previousLine.length()) - 1 };

        cursor.decrementRow();
        cursor.setCol(std::min(cursor.savedCol(), previousCols));
    }
}

void Motions::moveDown(Cursor& cursor, const Buffer& buffer)
{
    if (cursor.row() < static_cast<int>(buffer.lineCount()) - 1) {
        const auto& nextLine{ buffer.getText(cursor.row() + 1) };
        const auto nextCols{ nextLine.empty() ? 0 : static_cast<int>(nextLine.length()) - 1 };

        cursor.incrementRow();
        cursor.setCol(std::min(cursor.savedCol(), nextCols));
    }
}

void Motions::moveRight(Cursor& cursor, const Buffer& buffer)
{
    if (cursor.col() < static_cast<int>(buffer.getText(cursor.row()).length()) - 1) {
        cursor.incrementCol();
    }
}

void Motions::moveLeft(Cursor& cursor, const Buffer& buffer)
{
    cursor.decrementCol();
}

void Motions::moveToEndOfLine(Cursor& cursor, const Buffer& buffer)
{
    const auto& line{ buffer.getText(cursor.row()) };
    const auto lineCols{ line.empty() ? 0 : static_cast<int>(buffer.getText(cursor.row()).length() - 1) };

    if (cursor.col() < lineCols) {
        cursor.syncCols(lineCols);
    }
}

void Motions::moveToStartOfLine(Cursor& cursor, const Buffer& buffer)
{
    cursor.syncCols(0);
}
