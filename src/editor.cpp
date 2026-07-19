#include "../include/editor.hpp"
#include <ncurses.h>

namespace
{
    constexpr int g_CTRLQ{ 17 };
    constexpr int g_ESCAPE{ 27 };
}


bool Editor::isOpen() const noexcept
{
    return m_isOpen;
}

void Editor::init()
{
    getScreenSize();
    drawEOB();
}

void Editor::drawEOB()
{
    for (int i{ m_cursor.col + 1 }; i < m_height; ++i) {
        mvprintw(i, 0, "%c", '~');
    }

    refresh();
}

void Editor::getScreenSize()
{
    getmaxyx(stdscr, m_height, m_width);
}

void Editor::handleInput(int key)
{
    switch (m_editMode) {
        case EditMode::normal:
            handleNormalMode(key);
            break;
        case EditMode::insert:
            handleInsertMode(key);
            break;
        case EditMode::visual:
            handleVisualMode(key);
            break;
    }

    updateStatusLine();
}

void Editor::handleNormalMode(const int key)
{
    switch (key) {
        case g_CTRLQ:
            m_isOpen = false;
            break;

        case '\n':
            break;

        case 'j':
            moveDown();
            break;

        case 'k':
            moveUp();
            break;

        case 'h':
            moveLeft();
            break;

        case 'l':
            moveRight();
            break;

        case 'a':
            m_editMode = EditMode::insert;
            break;
    }
}

void Editor::handleInsertMode(const int key)
{
    switch (key) {
        case g_ESCAPE:
            m_editMode = EditMode::normal;
            break;
        default:
            outputCharacter(static_cast<char>(key));
            break;
    }

}

void Editor::handleVisualMode(const int key)
{

}

void Editor::moveDown()
{
    move(--m_cursor.row, m_cursor.col);
}

void Editor::moveUp()
{
    move(++m_cursor.row, m_cursor.col);
}

void Editor::moveRight()
{
    move(m_cursor.row, ++m_cursor.col);
}

void Editor::moveLeft()
{
    move(m_cursor.row, --m_cursor.col);
}

void Editor::outputCharacter(const char c)
{
    mvaddch(m_cursor.row, m_cursor.col, c);
    moveRight();
}

void Editor::updateStatusLine()
{
    mvaddstr(m_height, 0, "FEET");
}

