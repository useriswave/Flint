#include "editor/Cursor.hpp"
#include "tui/Screen.hpp"

#include "persistence/FileHandler.hpp"
#include "editor/modes/IMode.hpp"
#include "editor/modes/NormalMode.hpp"

#include <memory>

class Editor
{
public:
    Editor() = default;

public:
    bool isOpen() const noexcept;
    void init();
    void handleInput(const int key);

private:
    void addNewLine();
    void outputCharacter(int key);
    void moveCursorTopLeft();

private:
    void changeMode();

private:
    FileHandler m_fileHandler{};
    Buffer m_buffer{};
    Screen m_screen{};
    Cursor m_cursor{};
    ModeType m_modeType{ ModeType::normal };
    std::unique_ptr<IMode> m_mode{ std::make_unique<NormalMode>(m_buffer, m_cursor, m_modeType) };
    bool m_isOpen{ true };
};
