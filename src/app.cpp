#include "../include/app.hpp"

void App::start()
{
    init();
    m_editor.init();

    while (m_editor.isOpen()) {
        m_editor.handleInput(m_key = getch());
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


