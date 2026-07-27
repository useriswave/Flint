#include "editor/modes/InsertMode.hpp"

void InsertMode::execute(int key)
{
    if (key == EditorKeys::ESCAPE) {
        m_modeType = ModeType::normal;
    }
}

