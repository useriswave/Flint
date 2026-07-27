#ifndef CURSOR_HPP
#define CURSOR_HPP

#include "editor/buffer/Buffer.hpp"

struct Cursor
{
    int row{};
    int col{};
    int savedCol{};
};

#endif

