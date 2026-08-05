#include "editor/EditorKeys.hpp"
#include "editor/Editor.hpp"

void NormalMode::execute(Editor& editor, int key)
{
    switch (key) {
        case 'k':
            editor.navigateUp();
            break;

        case 'j':
            editor.navigateDown();
            break;

        case 'h':
            editor.navigateLeft();
            break;

        case 'l':
            editor.navigateRight();
            break;

        case 'i':
            editor.setMode(ModeType::insert);
            break;

        case 'a':
            editor.setMode(ModeType::insert);
            editor.shiftCursorRight();
            break;

        case '$':
            editor.navigateEndLine();
            break;

        case '0':
            editor.navigateStartLine();
            break;

        case 'A':
            editor.navigateEndLine();
            editor.setMode(ModeType::insert);
            editor.shiftCursorRight();
            break;

        case 'I':
            editor.navigateStartLine();
            editor.setMode(ModeType::insert);
            break;

        case 'u':
            editor.undo();
            break;

        case 'r':
            editor.redo();
            break;

        case EditorKeys::CTRL_S:
            editor.saveFile();
            break;

        case EditorKeys::CTRL_Q:
            editor.close();
            break;
    }
}
