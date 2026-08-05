#ifndef DELETETEXTCOMMAND_HPP
#define DELETETEXTCOMMAND_HPP

#include "editor/EditingController.hpp"
#include "editor/history/commands/ICommand.hpp"
#include "editor/history/EditRecord.hpp"

class DeleteCharacterCommand final : public ICommand
{
public:
    DeleteCharacterCommand(EditingController& controller, int character)
        : m_controller{ controller }
        , m_character{ character }
    {}

public:
    void execute() override;
    void undo() override;

private:
    EditingController& m_controller;
    EditRecord m_before{};
    int m_character{};
};

#endif
