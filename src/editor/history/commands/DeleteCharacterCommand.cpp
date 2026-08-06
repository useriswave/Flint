#include "editor/history/commands/DeleteCharacterCommand.hpp"

void DeleteCharacterCommand::execute()
{
    m_controller.setCursor(m_before.cursor);
    m_controller.removeCharacter();
}

void DeleteCharacterCommand::undo()
{
    m_controller.addCharacterAt(m_before.cursor.row(), m_before.cursor.col() - 1, m_character);
    m_controller.setCursor(m_before.cursor);
}

