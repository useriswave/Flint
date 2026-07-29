#ifndef IMODE_HPP
#define IMODE_HPP

class Editor;

class IMode
{
public:
    virtual ~IMode() = default;

public:
    virtual void execute(Editor& editor, int key) = 0;
};

#endif
