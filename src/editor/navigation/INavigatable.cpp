#include "editor/navigation/INavigatable.hpp"

void INavigatable::moveUp(Cursor& cursor, const Buffer& buffer)
{
    if (cursor.row > 0) {
        const auto& previousLine{ buffer.getText(cursor.row - 1) };
        const auto previousCols{ previousLine.empty() ? 0 : static_cast<int>(previousLine.length()) - 1 };

        --cursor.row;
        cursor.col = std::min(cursor.savedCol, previousCols);
    }
}

void INavigatable::moveDown(Cursor& cursor, const Buffer& buffer)
{
    if (cursor.row < static_cast<int>(buffer.lineCount()) - 1) {
        const auto& nextLine{ buffer.getText(cursor.row + 1) };
        const auto nextCols{ nextLine.empty() ? 0 : static_cast<int>(nextLine.length()) - 1 };

        ++cursor.row;
        cursor.col = std::min(cursor.savedCol, nextCols);
    }
}

void INavigatable::moveRight(Cursor& cursor, const Buffer& buffer)
{
    if (cursor.col < static_cast<int>(buffer.getText(cursor.row).length()) - 1) {
        ++cursor.col;
        cursor.savedCol = cursor.col;
    }
}

void INavigatable::moveLeft(Cursor& cursor, const Buffer& buffer)
{
    if (cursor.col > 0) {
        --cursor.col;
        cursor.savedCol = cursor.col;
    }
}

void INavigatable::moveToEndOfLine(Cursor& cursor, const Buffer& buffer)
{
    const auto& line{ buffer.getText(cursor.row) };
    const auto lineCols{ line.empty() ? 0 : static_cast<int>(buffer.getText(cursor.row).length()) - 1 };

    if (cursor.col < lineCols) {
        cursor.col = lineCols;
        cursor.savedCol = cursor.col;
    }
}

void INavigatable::moveToStartOfLine(Cursor& cursor, const Buffer& buffer)
{
    cursor.col = 0;
    cursor.savedCol = 0;
}
