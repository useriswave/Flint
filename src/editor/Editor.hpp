#ifndef EDITOR_HPP
#define EDITOR_HPP

#include "editor/EditingController.hpp"
#include "editor/modes/ModeType.hpp"
#include "editor/modes/IMode.hpp"
#include "editor/modes/NormalMode.hpp"
#include "tui/Screen.hpp"

#include <memory>

class Editor
{
public:
    [[nodiscard]] bool isOpen() const noexcept;
    void init();
    void handleInput(const int key);

public:
    void navigateUp();
    void navigateDown();
    void navigateRight();
    void navigateLeft();
    void navigateStartLine();
    void navigateEndLine();

public:
    void outputNewLine();
    void deleteCharacter();
    void outputCharacter(int key);
    void resetCursor();

public:
    void shiftCursorRight();
    void shiftCursorLeft();

public:
    void setMode(ModeType mode);

public:
    void saveFile();
    void openFile();
    void close() noexcept;

private:
    EditingController m_controller{};
    Screen m_screen{};
    ModeType m_modeType{ ModeType::normal };
    std::unique_ptr<IMode> m_mode{ std::make_unique<NormalMode>() };
    bool m_isOpen{};
};

#endif
