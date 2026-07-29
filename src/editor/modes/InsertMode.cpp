#include "editor/modes/InsertMode.hpp"
#include "editor/modes/NormalMode.hpp"
#include "editor/EditorKeys.hpp"
#include "editor/Editor.hpp"

#include <memory>

void InsertMode::execute(Editor& editor, int key)
{
    if (key == EditorKeys::ESCAPE) {
        editor.setMode(std::make_unique<NormalMode>());
    } else {
        editor.outputCharacter(key);
    }
}

