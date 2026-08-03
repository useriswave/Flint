#ifndef IHORIZONTALMOVABLE_HPP
#define IHORIZONTALMOVABLE_HPP

#include "editor/Cursor.hpp"
#include "editor/buffer/Buffer.hpp"

class Motions
{
public:
    void moveUp(Cursor& cursor, const Buffer& buffer);
    void moveDown(Cursor& cursor, const Buffer& buffer);
    void moveRight(Cursor& cursor, const Buffer& buffer);
    void moveLeft(Cursor& cursor, const Buffer& buffer);

public:
    void moveToEndOfLine(Cursor& cursor, const Buffer& buffer);
    void moveToStartOfLine(Cursor& cursor, const Buffer& buffer);
};

#endif
