#include "editor/Editor.hpp"

#include "editor/modes/InsertMode.hpp"
#include "editor/modes/VisualMode.hpp"
#include "editor/modes/NormalMode.hpp"

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
    auto previousType{ m_modeType };
    m_mode->execute(key);

    if (previousType != m_modeType) {
        changeMode();
    }
}

void Editor::changeMode()
{
    switch (m_modeType) {
        case ModeType::normal:
            m_mode = std::make_unique<NormalMode>(m_buffer, m_cursor, m_modeType);
            break;

        case ModeType::visual:
            m_mode = std::make_unique<VisualMode>(m_buffer, m_cursor, m_modeType);
            break;

        case ModeType::insert:
            m_mode = std::make_unique<InsertMode>(m_buffer, m_cursor, m_modeType);
            break;
    }
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
