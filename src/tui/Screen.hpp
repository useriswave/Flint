#ifndef SCREEN_HPP
#define SCREEN_HPP

#include "editor/Cursor.hpp"
#include "tui/Viewport.hpp"

#include <string>
#include <vector>

class Screen
{
public:
    void update(const Cursor& cursor, const std::vector<std::string>& lines);
    void fitViewport(const Cursor& cursor, const std::vector<std::string>& lines) const;

private:
    void drawStatusLine(const Cursor& cursor, const std::string& line) const;
    void drawLine(int row, const std::string& line) const;
    std::string expandTabs(std::string::const_iterator start, std::string::const_iterator end) const;
    int screenCol(const std::string& line, int col) const;
    int screenRow(const Cursor& cursor) const;
    void drawTildes(std::size_t start, std::size_t end) const;

private:
    Viewport m_viewport{};
    static constexpr int TAB_WIDTH{ 4 };
    int m_height{};
    int m_width{};
};

#endif
