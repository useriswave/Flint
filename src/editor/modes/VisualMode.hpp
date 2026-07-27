#ifndef VISUALMODE_HPP
#define VISUALMODE_HPP

#include "editor/navigation/INavigatable.hpp"
#include "editor/modes/IMode.hpp"

class VisualMode : public INavigatable , public IMode
{
public:
    VisualMode(Buffer& buffer, Cursor& cursor, ModeType& modeType)
        : IMode{ buffer, cursor, modeType }
    {}

public:
    void execute(int key) override;
};

#endif
