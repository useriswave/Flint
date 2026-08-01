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
    void moveToStartLine();
    void moveToEndLine();
    void appendToEndLine();

public:
    void addNewLine();
    void addCharacter(int c);
    void backspace();
    void resetCursor();

public:
    const Cursor& cursor() const { return m_cursor; }
    int lineCount() { return m_buffer.lineCount(); }
    const std::string& currentLine() const { return m_buffer.getText(m_cursor.row()); };
    const std::vector<std::string>& lines() const { return m_buffer.lines(); }

private:
    Buffer m_buffer{};
    Cursor m_cursor{};
    Motions m_motions{};
};

#endif
