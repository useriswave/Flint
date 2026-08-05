#include "editor/history/commands/AddNewLineCommand.hpp"

void AddNewLineCommand::execute()
{
    m_before = { m_controller.cursor() };
    m_controller.addNewLine();
    m_after = { m_controller.cursor() };

}

void AddNewLineCommand::undo()
{
    m_controller.removeCharacterAt(m_after.cursor.row(), m_after.cursor.col());
    m_controller.setCursor(m_before.cursor);
}

