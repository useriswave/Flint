#ifndef IHORIZONTALMOVABLE_HPP
#define IHORIZONTALMOVABLE_HPP

#include "editor/Cursor.hpp"
#include "editor/buffer/Buffer.hpp"

class INavigatable
{
protected:
    void moveUp(Cursor& cursor, const Buffer& buffer);
    void moveDown(Cursor& cursor, const Buffer& buffer);
    void moveRight(Cursor& cursor, const Buffer& buffer);
    void moveLeft(Cursor& cursor, const Buffer& buffer);

protected:
    void moveToEndOfLine(Cursor& cursor, const Buffer& buffer);
    void moveToStartOfLine(Cursor& cursor, const Buffer& buffer);
};

#endif
