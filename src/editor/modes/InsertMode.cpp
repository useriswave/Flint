#include "editor/modes/InsertMode.hpp"
#include "editor/EditorKeys.hpp"

void InsertMode::execute(int key)
{
    if (key == EditorKeys::ESCAPE) {
        m_modeType = ModeType::normal;
    }
}

