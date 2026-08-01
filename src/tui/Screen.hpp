#ifndef SCREEN_HPP
#define SCREEN_HPP

#include "editor/Cursor.hpp"

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
    void refreshAll(const Cursor& cursor, const std::vector<std::string>& lines);
    void refreshViewport(int row, int col, const std::vector<std::string>& lines);
    void refreshLine(int row, int col, const std::string& line);
    void refreshCursor(const Cursor& cursor);
    void refreshScreen();

private:
    int m_height{};
    [[maybe_unused]] int m_width{};
};

#endif
