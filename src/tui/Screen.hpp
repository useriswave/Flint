#ifndef SCREEN_HPP
#define SCREEN_HPP

#include "editor/Cursor.hpp"

#include <string>

class Screen
{
public:
    [[maybe_unused]] int getHeight();
    [[maybe_unused]] int getWidth();

public:
    void drawCharacter(const Cursor&, int c);
    void refreshLine(int row, const std::string& line);
    void refreshCursor(const Cursor& cursor);
    [[maybe_unused]] void eraseCharacter(const Cursor& cursor);

public:
    void drawStatusLine(const Cursor& cursor);

private:
    int m_height{};
    [[maybe_unused]] int m_width{};
};

#endif
