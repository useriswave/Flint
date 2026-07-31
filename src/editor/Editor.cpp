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
    resetCursor();
    m_isOpen = true;
}

void Editor::handleInput(int key)
{
    m_mode->execute(*this, key);
    m_screen.drawStatusLine(m_controller.cursor());
}

void Editor::moveUp()
{
    m_controller.moveUp();
}

void Editor::moveDown()
{
    m_controller.moveDown();
    m_screen.refreshCursor(m_controller.cursor());
}

void Editor::moveRight()
{
    m_controller.moveRight();
    m_screen.refreshCursor(m_controller.cursor());
}

void Editor::moveLeft()
{
    m_controller.moveLeft();
    m_screen.refreshCursor(m_controller.cursor());
}

void Editor::moveToStartOfLine()
{
    m_controller.moveToStartLine();
    m_screen.refreshCursor(m_controller.cursor());
}

void Editor::moveToEndOfLine()
{
    m_controller.moveToEndLine();
    m_screen.refreshCursor(m_controller.cursor());
}

void Editor::insertAtStartOfLine()
{
    m_controller.moveToStartLine();
    setMode(ModeType::insert);
    m_screen.refreshCursor(m_controller.cursor());
}

void Editor::appendToEndOfLine()
{
    m_controller.appendToEndLine();
    setMode(ModeType::insert);
    m_screen.refreshCursor(m_controller.cursor());
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
    m_controller.addNewLine();

    for (int i{ m_controller.cursor().row() }; i < m_controller.lineCount(); ++i) {
        m_screen.refreshLine(i, m_controller.currentLine());
    }

    m_screen.refreshCursor(m_controller.cursor());
}

void Editor::outputCharacter(const int key)
{
    m_controller.addCharacter(key);
    m_screen.refreshLine(m_controller.cursor().row(), m_controller.currentLine());
}

void Editor::deleteCharacter()
{
    m_controller.backspace();
    m_screen.refreshLine(m_controller.cursor().row(), m_controller.currentLine());
}

void Editor::resetCursor()
{
    m_controller.resetCursor();
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
