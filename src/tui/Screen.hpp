#ifndef SCREEN_HPP
#define SCREEN_HPP

#include "editor/Cursor.hpp"

#include <string>

class Screen
{
public:
    int getHeight();
    int getWidth();

public:
    void printCharacter(int row, int col, char c);
    void drawLine(int row, const std::string& line);
    void eraseCharacter(int row, int col);

public:
    void drawStatusLine(Cursor& cursor);

private:
    int m_height{};
    int m_width{};
};

#endif
