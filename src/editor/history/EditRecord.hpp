#ifndef EDITRECORD_HPP
#define EDITRECORD_HPP

#include "editor/Cursor.hpp"

struct EditRecord final
{
    Cursor cursor{};
    int character{};
};

#endif
