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

void Screen::drawCharacter(const Cursor& cursor, const int c)
{
    mvaddch(cursor.row(), cursor.col(), c);
}

void Screen::refreshLine(const int row, const std::string& line)
{
    move(row, 0);
    clrtoeol();
    mvaddstr(row, 0, line.c_str());
}

void Screen::refreshCursor(const Cursor& cursor)
{
    move(cursor.row(), cursor.col());
}

void Screen::eraseCharacter(const Cursor& cursor)
{
    mvdelch(cursor.row(), cursor.col());
}

void Screen::drawStatusLine(const Cursor& cursor)
{
    int row{ cursor.row() };
    int col{ cursor.col() };

    m_height = getHeight();
    mvaddstr(m_height - 1, 0, std::format("---R{}:COL{}---", row, col).c_str());

    move(row, col);
}
