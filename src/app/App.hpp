#ifndef APP_HPP
#define APP_HPP

#include "editor/Editor.hpp"

#include <ncurses.h>

class App
{
public:
    App() = default;

    ~App()
    {
        endwin();
    }

public:
    void start();
    void init();

private:
    Editor m_editor{};
};

#endif
