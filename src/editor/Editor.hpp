#ifndef EDITOR_HPP
#define EDITOR_HPP

#include "editor/EditingController.hpp"
#include "persistence/FileHandler.hpp"
#include "editor/modes/ModeType.hpp"
#include "editor/modes/IMode.hpp"
#include "editor/modes/NormalMode.hpp"
#include "editor/history/HistoryManager.hpp"
#include "tui/Screen.hpp"

#include <memory>

class Editor final
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
    void navigateFirstCharacter();

public:
    void outputNewLine();
    void deleteCharacter();
    void outputCharacter(int key);

public:
    void undo();
    void redo();

public:
    void beginInsertAfter();
    void endInsertAfter();
    void resetCursor();

public:
    void setMode(Mode::Type mode);

public:
    void openFile(const std::string& path);
    void saveFile();
    void saveHistory();
    void close() noexcept;

private:
    void update();

private:
    EditingController m_controller{};
    HistoryManager m_history{};
    FileHandler m_fileHandler{};
    Screen m_screen{};
    Mode::Type m_modeType{ Mode::Type::normal };
    std::unique_ptr<IMode> m_mode{ std::make_unique<NormalMode>() };
    bool m_isOpen{};
};

#endif
