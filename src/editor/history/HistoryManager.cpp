#include "editor/history/HistoryManager.hpp"
#include "editor/history/CommandGroup.hpp"

void HistoryManager::processCommand(std::unique_ptr<ICommand> command)
{
    if (!command) {
        return;
    }

    command->execute();
    m_group.push(std::move(command));

    if (m_group.isEmpty()) {
        m_redoStack.clear();
    }
}

void HistoryManager::commitCommands()
{
    if (!m_group.isEmpty()) {
        m_undoStack.emplace_back(std::move(m_group));
        m_group = {};
    }
}

void HistoryManager::undo()
{
    if (!m_undoStack.empty()) {
        m_undoStack.back().undoAll();
        m_redoStack.emplace_back(std::move(m_undoStack.back()));
        m_undoStack.pop_back();
    }
}

void HistoryManager::redo()
{
    if (!m_redoStack.empty()) {
        m_redoStack.back().executeAll();
        m_undoStack.emplace_back(std::move(m_redoStack.back()));
        m_redoStack.pop_back();
    }
}
