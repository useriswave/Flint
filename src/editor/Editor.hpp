#ifndef EDITOR_HPP
#define EDITOR_HPP

#include "editor/Cursor.hpp"
#include "editor/modes/ModeType.hpp"
#include "editor/modes/IMode.hpp"

#include "tui/Screen.hpp"
#include "buffer/Buffer.hpp"
#include "persistence/FileHandler.hpp"

#include <memory>

class Editor
{
public:
    Editor() { init(); }

public:
    bool isOpen() const noexcept;
    void init();
    void handleInput(const int key);

public:
    void addNewLine();
    void outputCharacter(int key);
    void moveCursorTopLeft();

public:
    void changeMode(std::unique_ptr<IMode> mode);
    void close() noexcept;

private:
    FileHandler m_fileHandler{};
    Buffer m_buffer{};
    Screen m_screen{};
    Cursor m_cursor{};
    ModeType m_modeType{ ModeType::normal };
    std::unique_ptr<IMode> m_mode{};
    bool m_isOpen{ true };
};

#endif
