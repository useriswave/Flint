#include "Cursor.hpp"

#include <stdexcept>
#include <format>

int Cursor::row() const
{
    return m_row;
}

int Cursor::col() const
{
    return m_col;
}

int Cursor::savedCol() const
{
    return m_savedCol;
}

void Cursor::setCol(int col)
{
    if (col < 0) {
        throw std::runtime_error{ std::format("ERROR Cursor::setCol(): Cursor column cannot be < 0: {}", m_col) };
    }

    m_col = col;
}

void Cursor::setRow(int row)
{
    if (row < 0) {
        throw std::runtime_error{ std::format("ERROR Cursor::setRow(): Cursor row cannot be < 0: {}", m_col) };
    }

    m_row = row;
}

void Cursor::setSavedCol(int col)
{
    if (col < 0) {
        throw std::runtime_error{ std::format("ERROR Cursor::setCol(): Cursor column cannot be < 0: {}", m_col) };
    }

    m_savedCol = col;
}

void Cursor::syncCols(int col)
{
    m_col = col;
    m_savedCol = col;
}

void Cursor::incrementCol()
{
    ++m_col;
    m_savedCol = m_col;
}

void Cursor::decrementCol()
{
    if (m_col > 0) {
        --m_col;
        m_savedCol = m_col;
    }
}

void Cursor::incrementRow()
{
    ++m_row;
}

void Cursor::decrementRow()
{
    if (m_row > 0) {
        --m_row;
    }
}

void Cursor::reset()
{
    setRow(0);
    setCol(0);
}

bool Cursor::atBeginning() const noexcept
{
    return m_col == 0 && m_row == 0;
}

