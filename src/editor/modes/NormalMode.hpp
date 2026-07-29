#ifndef NORMALMODE_HPP
#define NORMALMODE_HPP

#include "editor/modes/IMode.hpp"

class NormalMode final : public IMode
{
public:
    void execute(Editor& editor, int key) override;
};

#endif
