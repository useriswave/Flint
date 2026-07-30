#include "editor/EditorKeys.hpp"
#include "editor/Editor.hpp"

void NormalMode::execute(Editor& editor, int key)
{
    switch (key) {
        case 'k':
            editor.moveUp();
            break;

        case 'j':
            editor.moveDown();
            break;

        case 'h':
            editor.moveLeft();
            break;

        case 'l':
            editor.moveRight();
            break;

        case 'i':
            editor.setMode(ModeType::insert);
            break;

        case 'a':
            editor.setMode(ModeType::insert);
            editor.moveRight();
            break;

        case '$':
            editor.moveToEndOfLine();
            break;

        case '0':
            editor.moveToStartOfLine();
            break;

        case 'A':
            editor.appendToEndOfLine();
            break;

        case 'I':
            editor.insertAtStartOfLine();
            break;

        case EditorKeys::CTRL_S:
            editor.saveFile();
            break;

        case EditorKeys::CTRL_Q:
            editor.close();
            break;
    }
}
