#ifndef APP_HPP
#define APP_HPP

#include "../include/editor.hpp"
#include "../include/filehandler.hpp"

#include <ncurses.h>

class App
{
public:
    App() = default;

    ~App() {
        endwin();
    }

public:
    void start();
    void init();

private:
    Editor m_editor{};
    FileHandler m_fileHandler{};
    int m_key{};
};

#endif
