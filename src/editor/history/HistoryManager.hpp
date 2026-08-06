#ifndef HISTORYMANAGER_HPP
#define HISTORYMANAGER_HPP

#include "editor/history/CommandGroup.hpp"

#include <vector>
#include <memory>

class HistoryManager final
{
public:
    void processCommand(std::unique_ptr<ICommand> command);
    void commitCommands();
    void undo();
    void redo();

private:
    void executeAndPush(std::unique_ptr<ICommand> command);

private:
    CommandGroup m_group{};
    std::vector<CommandGroup> m_undoStack{};
    std::vector<CommandGroup> m_redoStack{};
};

#endif

