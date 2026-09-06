#ifndef CURSOR_HPP
#define CURSOR_HPP

#include "editor/Position.hpp"

struct Cursor final
{
public:
    int row() const;
    int col() const;
    int savedCol() const;

public:
    void setCol(int col);
    void setRow(int row);
    void setSavedCol(int col);
    void syncCols(int col);
    void move(int row, int col);

public:
    void incrementCol();
    void decrementCol();
    void incrementRow();
    void decrementRow();
    void reset();

public:
    bool atBeginning() const noexcept;

private:
    Position m_position{};
    int m_savedCol{};
};

#endif

