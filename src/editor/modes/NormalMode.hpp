#ifndef NORMALMODE_HPP
#define NORMALMODE_HPP

#include "editor/Cursor.hpp"
#include "editor/navigation/INavigatable.hpp"
#include "editor/modes/IMode.hpp"

class NormalMode : public INavigatable, public IMode
{
public:
    NormalMode(Buffer& buffer, Cursor& cursor, ModeType& modeType)
        : IMode{ buffer, cursor, modeType }
    {}

public:
    void execute(int key) override;
};

#endif
