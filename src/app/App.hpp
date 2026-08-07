#ifndef APP_HPP
#define APP_HPP

#include "editor/Editor.hpp"

#include <ncurses.h>

class App
{
public:
    App(std::string path)
        : m_path { std::move(path) }
    {}

    ~App()
    {
        endwin();
    }

public:
    void start();
    void init();

private:
    Editor m_editor{};
    std::string m_path{};
};

#endif
