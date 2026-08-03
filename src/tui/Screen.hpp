#ifndef SCREEN_HPP
#define SCREEN_HPP

#include "editor/Cursor.hpp"

#include <ncurses.h>
#include <string>
#include <vector>

class Screen
{
public:
    [[maybe_unused]] int getHeight();
    [[maybe_unused]] int getWidth();

public:
    void drawStatusLine(const Cursor& cursor);
    void drawCharacter(const Cursor& cursor, int c);

public:
    void refreshAll(int row, int col, const std::vector<std::string>& lines);
    void refreshLine(int row, int col, const std::string& line);
    void refreshCursor(const Cursor& cursor, const std::string& line);
    void refreshScreen();

public:
    void drawCursorRight(const Cursor& cursor);
    void drawCursorLeft(const Cursor& cursor);

private:
    std::string expandTabs(std::string::const_iterator start, std::string::const_iterator end);
    int screenCol(const std::string& line, int col);

private:
    Cursor m_cursor{};
    static constexpr int TAB_WIDTH{ 4 };
};

#endif
