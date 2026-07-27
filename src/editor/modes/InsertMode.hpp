#ifndef INSERTMODE_HPP
#define INSERTMODE_HPP

#include "editor/modes/IMode.hpp"

class InsertMode : public IMode
{
public:
    InsertMode(Buffer& buffer, Cursor& cursor, ModeType& modeType)
        : IMode{ buffer, cursor, modeType }
    {}

public:
    void execute(int key) override;
};

#endif
