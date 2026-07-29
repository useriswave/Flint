#ifndef EDITOR_HPP
#define EDITOR_HPP

#include "editor/Cursor.hpp"
#include "editor/modes/ModeType.hpp"
#include "editor/modes/IMode.hpp"
#include "editor/modes/NormalMode.hpp"
#include "editor/motions/Motions.hpp"

#include "tui/Screen.hpp"
#include "buffer/Buffer.hpp"
#include "persistence/FileHandler.hpp"

#include <memory>

class Editor
{
public:
    Editor() {}/*{ init(); } */

public:
    bool isOpen() const noexcept;
    void init();
    void handleInput(const int key);

public:
    void moveUp();
    void moveDown();
    void moveRight();
    void moveLeft();
    void moveToStartOfLine();
    void moveToEndOfLine();
    void insertAtStartOfLine();
    void appendToEndOfLine();

public:
    void addNewLine();
    void outputCharacter(int key);
    void moveCursorTopLeft();

public:
    void setMode(std::unique_ptr<IMode> mode);

public:
    void saveFile();
    void openFile();
    void close() noexcept;

public:
    const Cursor& getCursor() const { return m_cursor; }

private:
    FileHandler m_fileHandler{};
    Buffer m_buffer{};
    Screen m_screen{};
    Cursor m_cursor{};
    Motions m_motions{};
    ModeType m_modeType{ ModeType::normal };
    std::unique_ptr<IMode> m_mode{ std::make_unique<NormalMode>() };
    bool m_isOpen{};
};

#endif
