#ifndef EDITINGCONTROLLER_HPP
#define EDITINGCONTROLLER_HPP

#include "editor/Cursor.hpp"
#include "editor/buffer/Buffer.hpp"
#include "editor/motions/Motions.hpp"
#include "persistence/FileHandler.hpp"

class EditingController final
{
public:
    void moveUp();
    void moveDown();
    void moveRight();
    void moveLeft();
    void moveStartLine();
    void moveEndLine();
    void moveToFirstChar();
    void shiftCursorRight();
    void shiftCursorLeft();

public:
    void addNewLine();
    void addCharacter(int c);
    void removeCharacter();
    void addCharacterAt(int row, int col, int c);
    void addNewLineAt(int row, int col);
    void removeCharacterAt(int row, int col);
    void resetCursor();

public:
    void openFile(const std::string& path);
    void saveFile();

public:
    void setCursor(const Cursor& cursor);

public:
    const Cursor& cursor() const;
    int currentRow() const;
    int currentCol() const;
    int lineCount() const;
    const std::string& currentLine() const;
    const std::vector<std::string>& lines() const;
    char currentCharacter() const;

private:
    void fillLines(std::vector<std::string> lines);
    void mergeLines();

private:
    FileHandler m_fileHandler{};
    Buffer m_buffer{};
    Cursor m_cursor{};
    Motions m_motions{};
};

#endif
