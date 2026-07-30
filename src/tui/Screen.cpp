#include "tui/Screen.hpp"

#include <ncurses.h>
#include <string>
#include <format>

int Screen::getHeight()
{
    return getmaxy(stdscr);
}

int Screen::getWidth()
{
    return getmaxx(stdscr);
}

void Screen::printCharacter(Cursor& cursor, const int c)
{
    mvaddch(cursor.row(), cursor.col(), c);
}

void Screen::drawLine(const int row, const std::string& line)
{
    clrtoeol();
    mvaddstr(row, 0, line.c_str());
}

void Screen::drawCursor(Cursor& cursor)
{
    refresh();
    move(cursor.row(), cursor.col());
    refresh();

}

void Screen::eraseCharacter(Cursor& cursor)
{
    mvdelch(cursor.row(), cursor.col());
}

void Screen::drawStatusLine(Cursor& cursor)
{
    int row{ cursor.row() };
    int col{ cursor.col() };

    m_height = getHeight();
    mvaddstr(m_height - 1, 0, std::format("---R{}:COL{}---", row, col).c_str());

    cursor.setRow(row);
    cursor.setCol(col);

    move(row, col);
}
