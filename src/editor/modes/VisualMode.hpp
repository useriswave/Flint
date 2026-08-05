#ifndef VISUALMODE_HPP
#define VISUALMODE_HPP

#include "editor/modes/IMode.hpp"

class VisualMode final : public IMode
{
public:
    void execute(Editor& editor, int key) override;
};

#endif
