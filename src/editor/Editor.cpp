#include "editor/Editor.hpp"

#include "editor/EditorKeys.hpp"

#include <ncurses.h>

bool Editor::isOpen() const noexcept
{
    return m_isOpen;
}

void Editor::init()
{
    moveCursorTopLeft();    // call in constructor if this is the only call
}

void Editor::handleInput(int key)
{
    m_mode->execute(key);
}

void Editor::changeMode(std::unique_ptr<IMode> mode)
{
    m_mode = std::move(mode);
}

void Editor::addNewLine()
{
}

void Editor::outputCharacter(const int key)
{
}

void Editor::moveCursorTopLeft()
{
    // move((m_cursor.row = 0), (m_cursor.col = 0));
}

void Editor::close() noexcept
{
    m_isOpen = false;
}

