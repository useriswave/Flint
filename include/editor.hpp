#include "../include/cursor.hpp"
#include "../include/editmode.hpp"

class Editor
{
public:
    Editor()
    {
    }

public:
    bool isOpen() const noexcept;
    void init();
    void drawEOB();
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
    void outputCharacter(const char c);
    void updateStatusLine();

private:
    Cursor m_cursor{};
    int m_height{};
    int m_width{};
    bool m_isOpen{ true };
    EditMode m_editMode{ EditMode::normal };
};
