#include "editor/Editor.hpp"
#include "editor/modes/InsertMode.hpp"
#include "editor/modes/VisualMode.hpp"
#include "editor/modes/ModeType.hpp"

#include <memory>
#include <ncurses.h>

bool Editor::isOpen() const noexcept
{
    return m_isOpen;
}

void Editor::init()
{
    moveCursorTopLeft();    // call in constructor if this is the only call
    m_isOpen = true;
}

void Editor::handleInput(int key)
{
    m_mode->execute(*this, key);
    m_screen.drawStatusLine(m_cursor);
}

void Editor::moveUp()
{
    m_motions.moveUp(m_cursor, m_buffer);
    m_screen.drawCursor(m_cursor);
}

void Editor::moveDown()
{
    m_motions.moveDown(m_cursor, m_buffer);
    m_screen.drawCursor(m_cursor);
}

void Editor::moveRight()
{
    m_motions.moveRight(m_cursor, m_buffer);
    m_screen.drawCursor(m_cursor);
}

void Editor::moveLeft()
{
    m_motions.moveLeft(m_cursor, m_buffer);
    m_screen.drawCursor(m_cursor);
}

void Editor::moveToStartOfLine()
{
    m_motions.moveToStartOfLine(m_cursor, m_buffer);
    m_screen.drawCursor(m_cursor);
}

void Editor::moveToEndOfLine()
{
    m_motions.moveToEndOfLine(m_cursor, m_buffer);
    m_screen.drawCursor(m_cursor);
}

void Editor::insertAtStartOfLine()
{
    moveToStartOfLine();
    setMode(ModeType::insert);
    m_screen.drawCursor(m_cursor);
}

void Editor::appendToEndOfLine()
{
    m_motions.moveToAppendEOL(m_cursor, m_buffer);
    setMode(ModeType::insert);
    m_screen.drawCursor(m_cursor);
}

void Editor::setMode(ModeType mode)
{
    switch (mode) {
        case ModeType::normal:
            m_mode = std::move(std::make_unique<NormalMode>());
            break;

        case ModeType::visual:
            m_mode = std::move(std::make_unique<VisualMode>());
            break;

        case ModeType::insert:
            m_mode = std::move(std::make_unique<InsertMode>());
            // m_buffer.getText(m_cursor.row()).empty() ? m_cursor.setCol(0) : m_cursor.incrementCol();
            break;
    }
}

void Editor::addNewLine()
{
    m_buffer.insertNewLine(m_cursor.row(), m_cursor.col());
    m_screen.drawLine(m_cursor.row(), m_buffer.getText(m_cursor.row()));


    for (std::size_t i{}; i < m_buffer.lineCount() - m_cursor.row(); ++i) {
        m_screen.drawLine(m_cursor.row()+i, m_buffer.getText(m_cursor.row()+i));
    }

    moveDown();
    m_motions.moveToStartOfLine(m_cursor, m_buffer);
    m_screen.drawCursor(m_cursor);
}

void Editor::outputCharacter(const int key)
{
    m_buffer.insertCharacter(m_cursor.row(), m_cursor.col(), key);
    m_screen.drawLine(m_cursor.row(), m_buffer.getText(m_cursor.row()));
    // move(m_cursor.row, ++m_cursor.col);
    m_motions.moveRight(m_cursor, m_buffer);
}

void Editor::deleteCharacter()
{
    if (m_cursor.row() == 0 && m_cursor.col() == 0)
        return;

    if (m_buffer.getText(m_cursor.row()).empty()) {
        m_cursor.decrementRow();

        if (m_buffer.getText(m_cursor.row()).empty()) {
            m_cursor.syncCols(0);
        } else {
            m_cursor.syncCols(m_buffer.getText(m_cursor.row()).length());
        }

    } else {
        moveLeft();
        m_buffer.deleteCharacter(m_cursor.row(), m_cursor.col());
    }


    m_screen.drawLine(m_cursor.row(), m_buffer.getText(m_cursor.row()));
}

void Editor::moveCursorTopLeft()
{
    m_cursor.setCol(0);
    m_cursor.setRow(0);
    move(m_cursor.row(), m_cursor.col());
}

void Editor::saveFile()
{
    // m_fileHandler.save(m_buffer.lines());
}

void Editor::openFile()
{
    // m_fileHandler.openAndRead(const std::string &path, std::vector<std::string> &lines)
}

void Editor::close() noexcept
{
    m_isOpen = false;
}

