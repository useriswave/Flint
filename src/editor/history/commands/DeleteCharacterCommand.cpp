#include "editor/history/commands/DeleteCharacterCommand.hpp"

void DeleteCharacterCommand::execute()
{
    m_before = { m_controller.cursor(), m_character };
    m_controller.removeCharacter();
}

void DeleteCharacterCommand::undo()
{
    m_controller.addCharacterAt(m_before.cursor.row(), m_before.cursor.col() - 1, m_before.character);
    m_controller.setCursor(m_before.cursor);
}

