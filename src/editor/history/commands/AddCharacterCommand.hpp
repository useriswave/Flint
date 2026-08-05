#ifndef ADDTEXTCOMMAND_HPP
#define ADDTEXTCOMMAND_HPP

#include "editor/EditingController.hpp"
#include "editor/history/commands/ICommand.hpp"
#include "editor/history/EditRecord.hpp"

class AddCharacterCommand : public ICommand
{
public:
    AddCharacterCommand(EditingController& controller, int character)
        : m_controller{ controller }
        , m_character{ character }
    {}

public:
    void execute() override;
    void undo() override;

private:
    EditingController& m_controller;
    EditRecord m_before{};
    EditRecord m_after{};
    int m_character{};
};

#endif
