#include "editor/Editor.hpp"
#include "editor/modes/InsertMode.hpp"
#include "editor/modes/VisualMode.hpp"
#include "editor/modes/ModeType.hpp"

#include <memory>

void Editor::handleInput(int key)
{
    m_mode->execute(*this, key);
    m_screen.update(m_controller.cursor(), m_controller.lines());
}

bool Editor::isOpen() const noexcept
{
    return m_isOpen;
}

void Editor::init()
{
    resetCursor();
    m_isOpen = true;
    m_screen.update(m_controller.cursor(), m_controller.lines());
}

void Editor::moveUp()
{
    m_controller.moveUp();
}

void Editor::moveDown()
{
    m_controller.moveDown();
}

void Editor::moveRight()
{
    m_controller.moveRight();
}

void Editor::moveLeft()
{
    m_controller.moveLeft();
}

void Editor::moveToStartOfLine()
{
    m_controller.moveToStartLine();
}

void Editor::moveToEndOfLine()
{
    m_controller.moveToEndLine();
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
}

void Editor::outputCharacter(const int key)
{
    m_controller.addCharacter(key);
}

void Editor::deleteCharacter()
{
    auto rowBefore{ m_controller.cursor().row() };
    m_controller.backspace();
}

void Editor::resetCursor()
{
    m_controller.resetCursor();
}

void Editor::shiftCursorRight()
{
    m_controller.beginInsertAfter();
}

void Editor::shiftCursorLeft()
{
    m_controller.endInsertAfter();
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
