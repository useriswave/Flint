#include "editor/history/HistoryManager.hpp"

void HistoryManager::execute(std::unique_ptr<ICommand> command)
{
    if (command) {
        command->execute();
        m_undoStack.emplace_back(std::move(command));
        m_redoStack.clear();
    }
}

void HistoryManager::undo()
{
    if (!m_undoStack.empty()) {
        m_undoStack.back()->undo();
        m_redoStack.emplace_back(std::move(m_undoStack.back()));
        m_undoStack.pop_back();
    }
}

void HistoryManager::redo()
{
    if (!m_redoStack.empty()) {
        m_redoStack.back()->execute();
        m_undoStack.emplace_back(std::move(m_redoStack.back()));
        m_redoStack.pop_back();
    }
}
