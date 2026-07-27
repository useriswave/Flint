#include "app/App.hpp"

void App::start()
{
    init();
    m_editor.init();

    while (m_editor.isOpen()) {
        m_editor.handleInput(getch());
    }
}

void App::init()
{
    initscr();
    noecho();
    cbreak();
    raw();
    keypad(stdscr, true);

    refresh();
}
