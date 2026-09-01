#include "editor/Editor.hpp"
#include "editor/modes/InsertMode.hpp"
#include "editor/modes/VisualMode.hpp"
#include "editor/modes/ModeType.hpp"
#include "editor/history/commands/AddNewLineCommand.hpp"
#include "editor/history/commands/AddCharacterCommand.hpp"
#include "editor/history/commands/DeleteCharacterCommand.hpp"

#include <memory>

bool Editor::isOpen() const noexcept
{
    return m_isOpen;
}

void Editor::init()
{
    resetCursor();
    m_isOpen = true;
    update();
}

void Editor::handleInput(int key)
{
    m_mode->execute(*this, key);
    update();
}

void Editor::navigateUp()
{
    m_controller.moveUp();
}

void Editor::navigateDown()
{
    m_controller.moveDown();
}

void Editor::navigateRight()
{
    m_controller.moveRight();
}

void Editor::navigateLeft()
{
    m_controller.moveLeft();
}

void Editor::navigateStartLine()
{
    m_controller.moveStartLine();
}

void Editor::navigateEndLine()
{
    m_controller.moveEndLine();
}

void Editor::navigateFirstCharacter()
{
    m_controller.moveToFirstChar();
}

void Editor::navigateNextWord()
{
    m_controller.moveNextWord();
}

void Editor::openFile(const std::string& path)
{
    m_controller.openFile(path);
}

void Editor::saveFile()
{
    m_controller.saveFile();
}

void Editor::saveHistory()
{
    m_history.commitCommands();
}

void Editor::setMode(Mode::Type mode)
{
    switch (mode) {
        case Mode::Type::normal:
            m_mode = std::make_unique<NormalMode>();
            m_modeType = Mode::Type::normal;
            break;

        case Mode::Type::visual:
            m_mode = std::make_unique<VisualMode>();
            m_modeType = Mode::Type::visual;
            break;

        case Mode::Type::insert:
            m_mode = std::make_unique<InsertMode>();
            m_modeType = Mode::Type::insert;
            break;
    }
}

void Editor::outputNewLine()
{
    m_history.processCommand(std::make_unique<AddNewLineCommand>(m_controller));

}

void Editor::outputCharacter(const int key)
{
    m_history.processCommand(std::make_unique<AddCharacterCommand>(m_controller, key));
}

void Editor::deleteCharacter()
{
    if (!m_controller.cursor().atBeginning()) {
        m_history.processCommand(std::make_unique<DeleteCharacterCommand>(m_controller, m_controller.currentCharacter()));
    }
}

void Editor::undo()
{
    m_history.undo();
}

void Editor::redo()
{
    m_history.redo();
}

void Editor::beginInsertAfter()
{
    m_controller.shiftCursorRight();
}

void Editor::endInsertAfter()
{
    m_controller.shiftCursorLeft();
}

void Editor::resetCursor()
{
    m_controller.resetCursor();
}


void Editor::close() noexcept
{
    m_isOpen = false;
}

void Editor::update()
{
    m_screen.update(m_controller.cursor(), m_controller.lines());
    m_screen.drawStatusLine(m_controller.cursor(), m_controller.currentLine(), m_modeType);
}
