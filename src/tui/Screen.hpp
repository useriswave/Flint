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
    void drawStatusLine(const Cursor& cursor, const std::string& line);

public:
    void fitViewport(const Cursor& cursor, const std::vector<std::string>& lines);
    void refreshAll(const Cursor& cursor, const std::vector<std::string>& lines);
    void refreshLine(const Cursor& cursor, const std::string& line);
    void refreshCursor(const Cursor& cursor, const std::string& line);
    void refreshScreen();

private:
    void drawLine(int row, const std::string& line) const;
    std::string expandTabs(std::string::const_iterator start, std::string::const_iterator end) const;
    int screenCol(const std::string& line, int col) const;
    int screenRow(const Cursor& cursor) const;
    void drawTildes(std::size_t start, std::size_t end) const;

private:
    static constexpr int TAB_WIDTH{ 4 };
    int m_topLine{};
};

#endif
