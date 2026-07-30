#include "editor/modes/InsertMode.hpp"
#include "editor/EditorKeys.hpp"
#include "editor/Editor.hpp"

void InsertMode::execute(Editor& editor, int key)
{
    switch (key) {
        case EditorKeys::ESCAPE:
            editor.setMode(ModeType::normal);
            editor.moveLeft();
            break;

        case EditorKeys::ENTER:
            editor.addNewLine();
            break;

        default:
            editor.outputCharacter(key);
    }
}

