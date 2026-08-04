#include "editor/Editor.hpp"
#include "editor/modes/InsertMode.hpp"
#include "editor/modes/VisualMode.hpp"
#include "editor/modes/ModeType.hpp"

#include <memory>

void Editor::handleInput(int key)
{
    m_mode->execute(*this, key);
    m_screen.drawStatusLine(m_controller.cursor(), m_controller.currentLine());
}

bool Editor::isOpen() const noexcept
{
    return m_isOpen;
}

void Editor::init()
{
    m_screen.refreshAll(m_controller.cursor(), m_controller.lines());
    resetCursor();
    m_isOpen = true;
}

void Editor::moveUp()
{
    m_controller.moveUp();
    m_screen.fitViewport(m_controller.cursor(), m_controller.lines());
    m_screen.refreshCursor(m_controller.cursor(), m_controller.currentLine());
}

void Editor::moveDown()
{
    m_controller.moveDown();
    m_screen.fitViewport(m_controller.cursor(), m_controller.lines());
    m_screen.refreshCursor(m_controller.cursor(), m_controller.currentLine());
}

void Editor::moveRight()
{
    m_controller.moveRight();
    m_screen.refreshCursor(m_controller.cursor(), m_controller.currentLine());
}

void Editor::moveLeft()
{
    m_controller.moveLeft();
    m_screen.refreshCursor(m_controller.cursor(), m_controller.currentLine());
}

void Editor::moveToStartOfLine()
{
    m_controller.moveToStartLine();
    m_screen.refreshCursor(m_controller.cursor(), m_controller.currentLine());
}

void Editor::moveToEndOfLine()
{
    m_controller.moveToEndLine();
    m_screen.refreshCursor(m_controller.cursor(), m_controller.currentLine());
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
            break;
    }
}

void Editor::addNewLine()
{
    m_controller.addNewLine();
    m_screen.refreshAll(m_controller.cursor(), m_controller.lines());
}

void Editor::outputCharacter(const int key)
{
    m_controller.addCharacter(key);
    m_screen.refreshLine(m_controller.cursor(), m_controller.currentLine());
}

void Editor::deleteCharacter()
{
    auto rowBefore{ m_controller.cursor().row() };
    m_controller.backspace();

    if (m_controller.cursor().row() == rowBefore) {
        m_screen.refreshLine(m_controller.cursor(), m_controller.currentLine());
    } else {
        m_screen.refreshAll(m_controller.cursor(), m_controller.lines());
    }
}

void Editor::resetCursor()
{
    m_controller.resetCursor();
}

void Editor::shiftCursorRight()
{
    m_controller.beginInsertAfter();
    m_screen.refreshCursor(m_controller.cursor(), m_controller.currentLine());
}

void Editor::shiftCursorLeft()
{
    m_controller.endInsertAfter();
    m_screen.refreshCursor(m_controller.cursor(), m_controller.currentLine());
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
