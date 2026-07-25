#include "../include/editor.hpp"
#include "../include/editorkeys.hpp"

#include <ncurses.h>

bool Editor::isOpen() const noexcept
{
    return m_isOpen;
}

void Editor::init()
{
    getScreenSize();
    moveCursorTopLeft();
}

void Editor::getScreenSize()
{
    getmaxyx(stdscr, m_height, m_width);
}

void Editor::handleInput(int key)
{
    switch (m_editMode) {
        case EditMode::normal:
            handleNormalMode(key);
            break;
        case EditMode::insert:
            handleInsertMode(key);
            break;
        case EditMode::visual:
            handleVisualMode(key);
            break;
    }

    // m_screen.drawStatusLine(m_cursor);
}

void Editor::handleNormalMode(const int key)
{
    switch (key) {
        case EditorKeys::ctrlKey('q'):
            m_isOpen = false;
            break;

        case '\n':
            break;

        case 'j':
            moveDownNormalMode();
            break;

        case 'k':
            moveUpNormalMode();
            break;

        case 'h':
            moveLeft();
            break;

        case 'l':
            moveRight();
            break;

        case 'a':
            if (static_cast<int>(m_buffer.getText(m_cursor.row).length()) - 1 > 0) {
                move(m_cursor.row, ++m_cursor.col);
            }

            m_editMode = EditMode::insert;
            break;

        case 'i':
            m_editMode = EditMode::insert;
            break;

        case 'I':
            m_cursor.col = 0;
            break;

        case 'A':
            const auto& currentLine{ m_buffer.getText(m_cursor.row) };

            if (static_cast<int>(currentLine.length()) - 1 > 0) {
                move(m_cursor.row, ++m_cursor.col);
            }

            m_editMode = EditMode::insert;
            break;
    }
}

void Editor::handleInsertMode(const int key)
{
    switch (key) {
        case EditorKeys::g_ESCAPE_KEY:
            m_editMode = EditMode::normal;
            break;

        case '\n':
        case '\r':
            addNewLine();
            break;


        default:
            outputCharacter(key);
    }
}

void Editor::handleVisualMode(const int key)
{

}

void Editor::addNewLine()
{
    m_buffer.insertNewLine(m_cursor.row, m_cursor.col);
    m_screen.drawLine(m_cursor.row, m_buffer.getText(m_cursor.row));

    for (std::size_t i{}; i < m_buffer.lineCount() - m_cursor.row; ++i) {
        m_screen.drawLine(m_cursor.row+i, m_buffer.getText(m_cursor.row+i));
    }

    moveDownInsertMode();
}

void Editor::outputCharacter(const int key)
{
    m_buffer.insertCharacter(m_cursor.row, m_cursor.col, key);
    m_screen.drawLine(m_cursor.row, m_buffer.getText(m_cursor.row));
    moveRight();
}

void Editor::moveDownNormalMode()
{
    if (m_cursor.row == m_buffer.lineCount() - 1) {
        return;
    }

    const auto& nextLine{ m_buffer.getText(m_cursor.row + 1) };
    const int nextLineCols{ static_cast<int>(nextLine.length()) - 1 };

    if (nextLine.empty()) {
        m_cursor.stickyCol = 0;
    } else if (nextLineCols < m_cursor.col) {
        m_cursor.stickyCol = nextLineCols;
    } else {
        m_cursor.stickyCol = m_cursor.col;
    }

    move(++m_cursor.row, m_cursor.stickyCol);
}

void Editor::moveUpNormalMode()
{
    if (m_cursor.row == 0) {
        return;
    }

    const auto& previousLine{ m_buffer.getText(m_cursor.row - 1) };
    const int previousLineCols{ static_cast<int>(previousLine.length()) - 1 };

    if (previousLine.empty()) {
        m_cursor.stickyCol = 0;
    } else if (previousLineCols < m_cursor.col) {
        m_cursor.stickyCol = previousLineCols;
    } else {
        m_cursor.stickyCol = m_cursor.col;
    }

    move(--m_cursor.row, m_cursor.stickyCol);
}

void Editor::moveDownInsertMode()
{
    ++m_cursor.row;
    m_cursor.col = 0;
}

void Editor::moveRight()    // might wanna separate normal from insert mode (for now its both, move right should be last on addch)
{
    if (m_editMode == EditMode::insert) {

        move(m_cursor.row, ++m_cursor.col);

    } else if (m_editMode == EditMode::normal) {

        if (m_cursor.col >= static_cast<int>(m_buffer.getText(m_cursor.row).length()) - 1) {
            return;
        }

        m_cursor.col = ++m_cursor.stickyCol;
        move(m_cursor.row, m_cursor.stickyCol);

    } else if (m_editMode == EditMode::visual) {

    } else {

    }
}

void Editor::moveLeft()
{
    if (m_cursor.stickyCol <= 0) {  // issue here
        return;
    }

    m_cursor.col = --m_cursor.stickyCol;
    move(m_cursor.row, m_cursor.stickyCol);
}

void Editor::moveCursorTopLeft()
{
    move((m_cursor.row = 0), (m_cursor.col = 0));
}
