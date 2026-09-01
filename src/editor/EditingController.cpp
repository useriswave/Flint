#include "EditingController.hpp"

void EditingController::moveUp()
{
    m_motions.up(m_cursor, m_buffer);
}

void EditingController::moveDown()
{
    m_motions.down(m_cursor, m_buffer);
}

void EditingController::moveRight()
{
    m_motions.right(m_cursor, m_buffer);
}

void EditingController::moveLeft()
{
    m_motions.left(m_cursor, m_buffer);
}

void EditingController::moveStartLine()
{
    m_motions.startLine(m_cursor, m_buffer);
}

void EditingController::moveEndLine()
{
    m_motions.endLine(m_cursor, m_buffer);
}

void EditingController::moveToFirstChar()
{
    m_motions.firstCharacter(m_cursor, m_buffer);
}

void EditingController::moveNextWord()
{
    m_motions.nextWord(m_cursor, m_buffer);
}

void EditingController::shiftCursorRight()
{
    if (!currentLine().empty() && m_cursor.col() < static_cast<int>(currentLine().length())) {
        m_cursor.incrementCol();
    }
}

void EditingController::shiftCursorLeft()
{
    if (m_cursor.col() > 0) {
        m_cursor.decrementCol();
    }
}

void EditingController::addNewLine()
{
    m_buffer.insertNewLine(m_cursor.row(), m_cursor.col());
    moveDown();
    moveStartLine();
}

void EditingController::addCharacter(const int c)
{
    m_buffer.insertCharacter(m_cursor.row(), m_cursor.col(), c);
    m_cursor.incrementCol();
}

void EditingController::removeCharacter()
{
    if (m_cursor.atBeginning())  {
        return;
    }

    if (m_cursor.col() == 0) {
        mergeLines();
    } else {
        m_buffer.removeCharacter(m_cursor.row(), m_cursor.col() - 1);
        m_cursor.decrementCol();
    }
}

void EditingController::addCharacterAt(const int row, const int col, const int c)
{
    if (row == m_buffer.lineCount()) {
        m_buffer.insertNewLine(row, 0);
    }

    m_buffer.insertCharacter(row, col, c);
}

void EditingController::addNewLineAt(const int row, const int col)
{
    m_buffer.insertNewLine(row, col);
}

void EditingController::removeCharacterAt(const int row, const int col)
{
    if (row == 0 && col == 0) {
        return;
    }

    if (col == 0) {
        m_buffer.mergeLines(row, 0);
    } else {
        m_buffer.removeCharacter(row, col - 1);
    }
}

void EditingController::resetCursor()
{
    m_cursor.reset();
}

void EditingController::setCursor(const Cursor& cursor)
{
    m_cursor = cursor;
}

const Cursor& EditingController::cursor() const
{
    return m_cursor;
}

int EditingController::currentRow() const
{
    return m_cursor.row();
}

int EditingController::currentCol() const
{
    return m_cursor.col();
}

int EditingController::lineCount() const
{
    return m_buffer.lineCount();
}

const std::string& EditingController::currentLine() const
{
    return m_buffer.getText(m_cursor.row());
};

const std::vector<std::string>& EditingController::lines() const
{
    return m_buffer.lines();
}

char EditingController::currentCharacter() const
{
    if (m_cursor.col() > 0) {
        return currentLine().at(m_cursor.col() - 1);
    }

    return {};
}

void EditingController::mergeLines()
{
    int currentCol{ m_cursor.col() };
    int currentRow{ m_cursor.row() };

    m_cursor.decrementRow();
    m_motions.endLine(m_cursor, m_buffer);
    shiftCursorRight();
    m_buffer.mergeLines(currentRow, currentCol);
}

void EditingController::openFile(const std::string& path)
{
    fillLines(m_fileHandler.openAndRead(path));
}

void EditingController::saveFile()
{
    m_fileHandler.save(m_buffer.lines());
}

void EditingController::fillLines(std::vector<std::string> lines)
{
    m_buffer.setLines(std::move(lines));
}

