#include "../include/screen.hpp"

#include <ncurses.h>
#include <string>

int Screen::getHeight()
{
    return getmaxy(stdscr);
}

int Screen::getWidth()
{
    return getmaxx(stdscr);
}

void Screen::printCharacter(const int row, const int col, const char c)
{
    mvaddch(row, col, c);
}

void Screen::drawLine(const int row, const std::string& line)
{
    clrtoeol();
    mvaddstr(row, 0, line.c_str());
}

void Screen::eraseCharacter(int row, int col)
{
    mvdelch(row, col);
}

void Screen::drawStatusLine(Cursor& cursor)
{
    int row{ cursor.row };
    int col{ cursor.col };

    m_height = getHeight();
    mvaddstr(m_height - 1, 0, "Hello");

    move(row, col);
}

