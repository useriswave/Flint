#ifndef COMMAND_HPP
#define COMMAND_HPP

class ICommand
{
public:
    virtual void execute() = 0;
    virtual void undo() = 0;

    virtual ~ICommand() = default;
};

#endif
