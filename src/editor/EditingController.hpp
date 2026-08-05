#ifndef EDITINGCONTROLLER_HPP
#define EDITINGCONTROLLER_HPP

#include "editor/Cursor.hpp"
#include "editor/buffer/Buffer.hpp"
#include "editor/motions/Motions.hpp"

class EditingController
{
public:
    void moveUp();
    void moveDown();
    void moveRight();
    void moveLeft();
    void moveStartLine();
    void moveEndLine();
    void beginInsertAfter();
    void endInsertAfter();

public:
    void addNewLine();
    void addCharacter(int c);
    void removeCharacter();
    void addCharacterAt(int row, int col, int c);
    void addNewLineAt(int row, int col);
    void removeCharacterAt(int row, int col);
    void resetCursor();

public:
    void setCursor(const Cursor& cursor);

public:
    const Cursor& cursor() const { return m_cursor; }
    int currentRow() const { return m_cursor.row(); }
    int currentCol() const { return m_cursor.col(); }
    int lineCount() { return m_buffer.lineCount(); }
    const std::string& currentLine() const { return m_buffer.getText(m_cursor.row()); };
    const std::vector<std::string>& lines() const { return m_buffer.lines(); }
    char currentCharacter() { return currentLine().at(m_cursor.col() - 1); }

private:
    void mergeLines();

private:
    Buffer m_buffer{};
    Cursor m_cursor{};
    Motions m_motions{};
};

#endif
