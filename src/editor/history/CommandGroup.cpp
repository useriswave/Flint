#include "editor/history/CommandGroup.hpp"

void CommandGroup::executeAll()
{
    for (const auto& command : m_commands) {
        command->execute();
    }
}

void CommandGroup::undoAll()
{
    for (int i{ static_cast<int>(m_commands.size()) - 1 }; i >= 0; --i) {
        m_commands[i]->undo();
    }
}

void CommandGroup::push(std::unique_ptr<ICommand> command)
{
    m_commands.emplace_back(std::move(command));
}

void CommandGroup::clearAll()
{
    m_commands.clear();
}

bool CommandGroup::isEmpty() const noexcept
{
    return m_commands.empty();
}

