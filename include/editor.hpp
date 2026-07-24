#include "../include/cursor.hpp"
#include "../include/editmode.hpp"
#include "../include/buffer.hpp"
#include "../include/screen.hpp"

#include "filehandler.hpp"

class Editor
{
public:
    Editor()
    {
    }

public:
    bool isOpen() const noexcept;
    void init();
    void getScreenSize();
    void handleInput(const int key);

private:
    void handleNormalMode(const int key);
    void handleInsertMode(const int key);
    void handleVisualMode(const int key);

private:
    void moveDown();
    void moveUp();
    void moveRight();
    void moveLeft();
    void moveCursorTopLeft();

private:
    FileHandler m_fileHandler{};
    Buffer m_buffer{};
    Screen m_screen{};
    Cursor m_cursor{};
    int m_height{};
    int m_width{};
    bool m_isOpen{ true };
    EditMode m_editMode{ EditMode::normal };
};
