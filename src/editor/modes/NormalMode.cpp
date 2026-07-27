#include "editor/modes/NormalMode.hpp"

void NormalMode::execute(int key)
{
    switch (key) {
        case 'k':
            moveUp(m_cursor, m_buffer);
            break;

        case 'j':
            moveDown(m_cursor, m_buffer);
            break;

        case 'h':
            moveLeft(m_cursor, m_buffer);
            break;

        case 'l':
            moveRight(m_cursor, m_buffer);
            break;

        case 'A':
            moveToEndOfLine();
            m_modeType = ModeType::insert;
            break;

        case 'I':
        moveToStartOfLine();
        m_modeType = ModeType::insert;
        break;
    }
}
