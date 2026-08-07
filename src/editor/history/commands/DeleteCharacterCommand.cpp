#include "editor/history/commands/DeleteCharacterCommand.hpp"

void DeleteCharacterCommand::execute()
{
    m_controller.setCursor(m_before.cursor);
    m_controller.removeCharacter();
    m_after = { m_controller.cursor(), m_controller.currentCharacter() };
}

void DeleteCharacterCommand::undo()
{
    if (m_before.cursor.col() == 0) {
        m_controller.addNewLineAt(m_after.cursor.row(), m_after.cursor.col());
    } else {
        m_controller.addCharacterAt(m_before.cursor.row(), m_before.cursor.col() - 1, m_character);
    }

    m_controller.setCursor(m_before.cursor);
}

