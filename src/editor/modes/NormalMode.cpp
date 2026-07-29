#include "editor/modes/NormalMode.hpp"
#include "editor/modes/InsertMode.hpp"
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
            editor.setMode(std::make_unique<InsertMode>());
            break;

        case 'a':
            editor.setMode(std::make_unique<InsertMode>());
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
