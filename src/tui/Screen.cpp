#include "tui/Screen.hpp"

#include <ncurses.h>
#include <string>
#include <format>

void Screen::update(const Cursor& cursor, const std::vector<std::string>& lines)
{
    m_height = getmaxy(stdscr);
    m_viewport.bottom = m_viewport.top + m_height - 2;

    if (cursor.row() < m_viewport.top) {
        m_viewport.top = cursor.row();
    }

    if (cursor.row() > m_viewport.bottom) {
        m_viewport.top = cursor.row() - m_height + 2;
    }

    fitViewport(cursor, lines);
    drawStatusLine(cursor, lines[cursor.row()]);
}

void Screen::fitViewport(const Cursor& cursor, const std::vector<std::string>& lines) const
{
    erase();

    int row{};
    int bufferRow{ m_viewport.top };

    for (; bufferRow < static_cast<int>(lines.size()) && row < m_height - 1; ++row, ++bufferRow) {
        drawLine(row, lines[bufferRow]);
    }

    drawTildes(row, m_height - 1);
}

void Screen::drawLine(const int row, const std::string& line) const
{
    std::string expanded{ std::move(expandTabs(line.begin(), line.end())) };

    move(row, 0);

    clrtoeol();
    mvaddstr(row, 0, expanded.c_str());
}

void Screen::drawStatusLine(const Cursor& cursor, const std::string& line) const
{
    move(m_height - 1, 0);
    clrtoeol();
    mvaddstr(m_height - 1, 0, std::format("-R{}:COL{}-", cursor.row(), cursor.col()).c_str());

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
    return cursor.row() - m_viewport.top;
}

