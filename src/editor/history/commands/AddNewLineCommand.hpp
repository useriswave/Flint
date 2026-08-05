#ifndef ADDNEWLINECOMMAND_HPP
#define ADDNEWLINECOMMAND_HPP

#include "editor/EditingController.hpp"
#include "editor/history/commands/ICommand.hpp"
#include "editor/history/EditRecord.hpp"

class AddNewLineCommand final : public ICommand
{
public:
    AddNewLineCommand(EditingController& controller)
        : m_controller { controller }
    {}

public:
    void execute() override;
    void undo() override;

private:
    EditingController& m_controller;
    EditRecord m_before{};
    EditRecord m_after{};
};

#endif

