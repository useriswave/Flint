#ifndef INSERTMODE_HPP
#define INSERTMODE_HPP

#include "editor/modes/IMode.hpp"

class InsertMode final : public IMode
{
public:
    void execute(Editor& editor, int key) override;
};

#endif
