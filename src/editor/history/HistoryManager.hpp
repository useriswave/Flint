#ifndef HISTORYMANAGER_HPP
#define HISTORYMANAGER_HPP

#include "editor/history/commands/ICommand.hpp"

#include <vector>
#include <memory>

using Commands = std::vector<std::unique_ptr<ICommand>>;

class HistoryManager
{
public:
    void execute(std::unique_ptr<ICommand> command);
    void undo();
    void redo();

private:
    Commands m_undoStack{};
    Commands m_redoStack{};
};

#endif

