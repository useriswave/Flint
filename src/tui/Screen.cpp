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

void Screen::fitViewport(const Cursor& cursor, const std::vector<std::string>& lines)
{
    int bottomLine{ m_topLine + getHeight() - 1 };

    if (cursor.row() < m_topLine) {
        m_topLine = cursor.row();
        refreshAll(cursor, lines);
    }

    if (cursor.row() > bottomLine) {
        m_topLine = cursor.row() - getHeight() + 1;
        refreshAll(cursor, lines);
    }
}

void Screen::refreshAll(const Cursor& cursor, const std::vector<std::string>& lines)
{
    erase();

    for (std::size_t i{}; i < lines.size(); ++i) {
        drawLine(i, lines[i]);
    }

    drawTildes(lines.size(), getHeight());
    move(screenRow(cursor), screenCol(lines[cursor.row()], cursor.col()));
}

void Screen::refreshLine(const Cursor& cursor, const std::string& line)
{
    drawLine(cursor.row(), line);
    move(screenRow(cursor), screenCol(line, cursor.col()));
}

void Screen::drawLine(const int row, const std::string& line) const
{
    std::string expanded{ std::move(expandTabs(line.begin(), line.end())) };

    move(row, 0);

    clrtoeol();
    mvaddstr(row, 0, expanded.c_str());
}

void Screen::refreshCursor(const Cursor& cursor, const std::string& line)
{
    move(screenRow(cursor), screenCol(line, cursor.col()));
}

void Screen::refreshScreen()
{
    refresh();
}

void Screen::drawStatusLine(const Cursor& cursor, const std::string& line)
{
    move(getHeight() - 1, 0);
    clrtoeol();
    mvaddstr(getHeight() - 1, 0, std::format("-R{}:COL{}-", cursor.row(), cursor.col()).c_str());

    move(screenRow(cursor), screenCol(line, cursor.col()));
}

std::string Screen::expandTabs(std::string::const_iterator start, std::string::const_iterator end) const
{
    std::string expanded{};

    for (auto it{ start }; it < end; ++it) {
        if (*it == '\t') {
            expanded.append(TAB_WIDTH, ' ');
        } else {
            expanded += *it;
        }
    }

    return expanded;
}

void Screen::drawTildes(const std::size_t start, const std::size_t end) const
{
    for (std::size_t i{ start }; i < end; ++i) {
        mvaddch(i, 0, '~');
    }
}

int Screen::screenCol(const std::string& line, const int col) const
{
    return static_cast<int>(expandTabs(line.begin(), line.begin() + col).length());
}

int Screen::screenRow(const Cursor& cursor) const
{
    return cursor.row() - m_topLine;
}

