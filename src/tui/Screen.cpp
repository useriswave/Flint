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

    move(cursor.row(), screenCol(lines[cursor.row()], cursor.col()));
}

void Screen::refreshViewport(const int row, const int col, const std::vector<std::string>& lines)
{
    erase();

    for (std::size_t i{}; i < lines.size(); ++i) {
        std::string expanded{ expandTabs(lines[i].begin(), lines[i].end()) };
        mvaddstr(i, 0, expanded.c_str());
    }

    for (std::size_t i{ lines.size() }; i < getHeight(); ++i) {
        mvaddch(static_cast<int>(i), 0, '~');
    }

    move(row, screenCol(lines[row], col));
    refresh();
}

void Screen::refreshLine(const int row, const int col, const std::string& line)
{
    std::string expanded{ expandTabs(line.begin(), line.end()) };

    move(row, 0);

    clrtoeol();
    mvaddstr(row, 0, expanded.c_str());

    move(row, screenCol(line, col));
}

void Screen::refreshCursor(const Cursor& cursor, const std::string& line)
{
    move(cursor.row(), screenCol(line, cursor.col()));
}

void Screen::refreshScreen()
{
    refresh();
}

void Screen::drawStatusLine(const Cursor& cursor)
{
    int row{ cursor.row() };
    int col{ cursor.col() };

    int height = getHeight();
    move(height - 1, 0);
    clrtoeol();
    mvaddstr(height - 1, 0, std::format("---R{}:COL{}---", row, col).c_str());

    move(row, col);
}

std::string Screen::expandTabs(std::string::const_iterator start, std::string::const_iterator end)
{
    std::string expanded{};

    for (auto it{ start }; it < end; ++it) {
        if (*it == '\t') {
            expanded.append(4, ' ');
        } else {
            expanded += *it;
        }
    }

    return expanded;
}

int Screen::screenCol(const std::string& line, const int col)
{
    return static_cast<int>(expandTabs(line.begin(), line.begin() + col).length());
}

