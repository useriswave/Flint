#include "app/App.hpp"
#include <ncurses.h>

void App::start()
{
    init();


    try {
        m_editor.openFile(m_path);
    } catch (std::runtime_error& e) {
        throw;
    }

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
