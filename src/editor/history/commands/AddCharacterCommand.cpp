#include "editor/history/commands/AddCharacterCommand.hpp"

void AddCharacterCommand::execute()
{
    m_before = { m_controller.cursor() };
    m_controller.addCharacter(m_character);
    m_after = { m_controller.cursor(), m_character };
}

void AddCharacterCommand::undo()
{
    m_controller.removeCharacterAt(m_after.cursor.row(), m_after.cursor.col());
    m_controller.setCursor(m_before.cursor);
}
