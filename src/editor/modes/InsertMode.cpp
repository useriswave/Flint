#include "editor/modes/InsertMode.hpp"
#include "editor/EditorKeys.hpp"
#include "editor/Editor.hpp"
#include <ncurses.h>

void InsertMode::execute(Editor& editor, int key)
{
    switch (key) {
        case EditorKeys::ESCAPE:
            editor.setMode(Mode::Type::normal);
            editor.endInsertAfter();
            editor.saveHistory();
            break;

        case EditorKeys::ENTER:
            editor.outputNewLine();
            break;

        case KEY_BACKSPACE:
            editor.deleteCharacter();
            break;

        default:
            editor.outputCharacter(key);
    }
}

