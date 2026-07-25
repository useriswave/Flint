#include "../include/cursor.hpp"
#include "../include/editmode.hpp"
#include "../include/buffer.hpp"
#include "../include/screen.hpp"

#include "filehandler.hpp"

class Editor
{
public:
    Editor() = default;

public:
    bool isOpen() const noexcept;
    void init();
    void getScreenSize();
    void handleInput(const int key);

private:
    void handleNormalMode(int key);
    void handleInsertMode(int key);
    void handleVisualMode(int key);

private:
    void addNewLine();
    void outputCharacter(int key);

private:
    void moveDownInsertMode();
    void moveDownNormalMode();
    void moveUpNormalMode();
    void moveRight();
    void moveLeft();
    void moveCursorTopLeft();
    void moveToLineEnd();       // $
    void moveToLineStart();     // 0
    void appendAtLineEnd();     // A
    void insertAtLineStart();   // I

private:
    FileHandler m_fileHandler{};
    Buffer m_buffer{};
    Screen m_screen{};
    Cursor m_cursor{};
    EditMode m_editMode{ EditMode::normal };
    int m_height{};
    int m_width{};
    bool m_isOpen{ true };
};
