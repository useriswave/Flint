#include "app/App.hpp"
#include <ncurses.h>

void App::start()
{
    init();

    m_editor.openFile(m_path);
    m_editor.init();

    while (m_editor.isOpen()) {
        m_editor.handleInput(getch());
    }
}

void App::init()
{
    initscr();
    raw();
    noecho();
    keypad(stdscr, true);
    set_escdelay(25);

    refresh();
}
