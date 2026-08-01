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

void Screen::refreshAll(const Cursor& cursor, const std::vector<std::string>& lines)
{
    for (std::size_t i{}; i < lines.size(); ++i) {
        refreshLine(i, 0, lines[i]);
    }

    move(cursor.row(), cursor.col());
}

void Screen::refreshViewport(const int row, const int col, const std::vector<std::string>& lines)
{
    erase();

    for (std::size_t i{}; i < lines.size(); ++i) {
        mvaddstr(i, 0, lines[i].c_str());
    }

    for (std::size_t i{ lines.size() }; i < getHeight(); ++i) {
        mvaddch(i, 0, '~');
    }

    move(row, col);
    refresh();
}

void Screen::refreshLine(const int row, const int col, const std::string& line)
{
    int currentRow{ row };
    int currentCol{ col };

    move(row, 0);

    clrtoeol();
    mvaddstr(row, 0, line.c_str());

    move(currentRow, currentCol);
}

void Screen::refreshCursor(const Cursor& cursor)
{
    move(cursor.row(), cursor.col());
}

void Screen::refreshScreen()
{
    refresh();
}

void Screen::drawStatusLine(const Cursor& cursor)
{
    int row{ cursor.row() };
    int col{ cursor.col() };

    m_height = getHeight();
    move(m_height - 1, 0);
    clrtoeol();
    mvaddstr(m_height - 1, 0, std::format("---R{}:COL{}---", row, col).c_str());

    move(row, col);
}
