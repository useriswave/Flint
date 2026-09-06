#include "Cursor.hpp"

#include <stdexcept>
#include <format>

int Cursor::row() const
{
    return m_position.row;
}

int Cursor::col() const
{
    return m_position.col;
}

int Cursor::savedCol() const
{
    return m_savedCol;
}

void Cursor::setCol(int col)
{
    if (col < 0) {
        throw std::runtime_error{ std::format("ERROR Cursor::setCol(): Cursor column cannot be < 0: {}", m_position.col) };
    }

    m_position.col = col;
}

void Cursor::setRow(int row)
{
    if (row < 0) {
        throw std::runtime_error{ std::format("ERROR Cursor::setRow(): Cursor row cannot be < 0: {}", m_position.col) };
    }

    m_position.row = row;
}

void Cursor::setSavedCol(int col)
{
    if (col < 0) {
        throw std::runtime_error{ std::format("ERROR Cursor::setCol(): Cursor column cannot be < 0: {}", m_position.col) };
    }

    m_savedCol = col;
}

void Cursor::syncCols(int col)
{
    m_position.col = col;
    m_savedCol = col;
}

void Cursor::move(int row, int col)
{
    setRow(row);
    syncCols(col);
}

void Cursor::incrementCol()
{
    ++m_position.col;
    m_savedCol = m_position.col;
}

void Cursor::decrementCol()
{
    if (m_position.col > 0) {
        --m_position.col;
        m_savedCol = m_position.col;
    }
}

void Cursor::incrementRow()
{
    ++m_position.row;
}

void Cursor::decrementRow()
{
    if (m_position.row > 0) {
        --m_position.row;
    }
}

void Cursor::reset()
{
    setRow(0);
    setCol(0);
}

bool Cursor::atBeginning() const noexcept
{
    return m_position.col == 0 && m_position.row == 0;
}

