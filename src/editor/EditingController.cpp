#include "EditingController.hpp"

void EditingController::moveUp()
{
    m_motions.moveUp(m_cursor, m_buffer);
}

void EditingController::moveDown()
{
    m_motions.moveDown(m_cursor, m_buffer);
}

void EditingController::moveRight()
{
    m_motions.moveRight(m_cursor, m_buffer);
}

void EditingController::moveLeft()
{
    m_motions.moveLeft(m_cursor, m_buffer);
}

void EditingController::moveToStartLine()
{
    m_motions.moveToStartOfLine(m_cursor, m_buffer);
}

void EditingController::moveToEndLine()
{
    m_motions.moveToEndOfLine(m_cursor, m_buffer);
}

void EditingController::beginInsertAfter()
{
    if (!currentLine().empty() && m_cursor.col() < static_cast<int>(currentLine().length())) {
        m_cursor.incrementCol();
    }
}

void EditingController::endInsertAfter()
{
    if (m_cursor.col() > 0) {
        m_cursor.decrementCol();
    }
}

void EditingController::addNewLine()
{
    m_buffer.insertNewLine(m_cursor.row(), m_cursor.col());
    moveDown();
    moveToStartLine();
}

void EditingController::addCharacter(const int c)
{
    m_buffer.insertCharacter(m_cursor.row(), m_cursor.col(), c);
    m_cursor.incrementCol();
}

void EditingController::backspace()
{
    if (m_cursor.atBeginning())  {
        return;
    }

    if (m_cursor.col() == 0) {
        int currentCol{ m_cursor.col() };
        int currentRow{ m_cursor.row() };

        m_cursor.decrementRow();
        m_motions.moveToEndOfLine(m_cursor, m_buffer);
        beginInsertAfter();
        m_buffer.mergeLines(currentRow, currentCol);

        return;
    }

    m_buffer.removeCharacter(m_cursor.row(), m_cursor.col() - 1);
    m_motions.moveLeft(m_cursor, m_buffer);
}

void EditingController::resetCursor()
{
    m_cursor.reset();
}
