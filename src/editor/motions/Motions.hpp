#ifndef IHORIZONTALMOVABLE_HPP
#define IHORIZONTALMOVABLE_HPP

#include "editor/Cursor.hpp"
#include "editor/buffer/Buffer.hpp"

class Motions
{
public:
    void up(Cursor& cursor, const Buffer& buffer);
    void down(Cursor& cursor, const Buffer& buffer);
    void right(Cursor& cursor, const Buffer& buffer);
    void left(Cursor& cursor, const Buffer& buffer);

public:
    void endLine(Cursor& cursor, const Buffer& buffer);
    void startLine(Cursor& cursor, const Buffer& buffer);
    void firstCharacter(Cursor& cursor, const Buffer& buffer);
};

#endif
