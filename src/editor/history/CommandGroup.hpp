#ifndef COMMANDGROUP_HPP
#define COMMANDGROUP_HPP

#include "editor/history/commands/ICommand.hpp"

#include <vector>
#include <memory>

class CommandGroup
{
using Commands = std::vector<std::unique_ptr<ICommand>>;

public:
    void executeAll();
    void executeBack();

public:
    void push(std::unique_ptr<ICommand> command);
    void clearAll();

public:
    void undoAll();
    void redoAll();

public:
    bool isEmpty() const noexcept;

private:
    Commands m_commands{};
};

#endif
