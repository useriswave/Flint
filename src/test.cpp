#include "../include/editor.hpp"

#include <ncurses.h>

void initTUI()
{
    initscr();
    noecho();
    cbreak();
    raw();
    keypad(stdscr, true);

    refresh();
}

int main()
{
    Editor editor{};
    editor.init();

    std::string line{ "Hello World" };

    while (editor.isOpen()) {
        for (const auto c : line) {
            editor.handleInput(c);
        }

        editor.handleInput('q' & 0x1f);
    }

    endwin();
}
