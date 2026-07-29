#ifndef NORMALMODE_HPP
#define NORMALMODE_HPP

#include "editor/navigation/INavigatable.hpp"
#include "editor/modes/IMode.hpp"

class NormalMode final : public INavigatable, public IMode
{
public:
    void execute(Editor& editor, int key) override;
};

#endif
