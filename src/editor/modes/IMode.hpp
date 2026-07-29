#ifndef IMODE_HPP
#define IMODE_HPP

#include "editor/modes/ModeType.hpp"
#include "editor/Cursor.hpp"
#include "editor/buffer/Buffer.hpp"

class IMode
{
public:
    IMode(Buffer& buffer, Cursor& cursor, ModeType& modeType)
        : m_buffer { buffer }
        , m_cursor { cursor }
        , m_modeType { modeType }
    {}

    virtual ~IMode() = default;

public:
    virtual void execute(int key) = 0;

protected:
    Buffer& m_buffer;
    Cursor& m_cursor;
    ModeType& m_modeType;
};

#endif
