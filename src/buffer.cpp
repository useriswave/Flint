#include "../include/buffer.hpp"

#include <stdexcept>
#include <format>

void Buffer::insertNewLine(const int row, const int col)
{
    if (row < 0 || row > m_lines.size()) {
        throw std::out_of_range{ std::format("ERROR insertNewLine(): cursor row is out of range: {}", row) };
    }

    auto& line{ m_lines[row] };

    if (col < 0 || col > line.size()) {
        throw std::out_of_range{ std::format("ERROR insertNewLine(): cursor column is out of range: {}", col) };
    }

    auto right{ line.substr(col, line.length() - 1) };
    line.erase(line.begin() + col);
    m_lines.insert(m_lines.begin() + row + 1, std::move(right));
}

void Buffer::insertCharacter(const int row, const int col, const char c)
{
    if (row < 0 || row > static_cast<int>(m_lines.size()) - 1) {
        throw std::out_of_range{ std::format("ERROR insertCharacter(): cursor row is out of range: {}", row) };
    }

    auto& line{ m_lines[row] };

    if (col < 0 || col > line.size()) {
        throw std::out_of_range{ std::format("ERROR: cursor column is out of range: {}", col) };
    }

    line.insert(line.begin() + col, c);
}

void Buffer::deleteCharacter(const int row, const int col)
{
    if (row < 0 || row > m_lines.size() - 1) {
        throw std::out_of_range{ std::format("ERROR deleteCharacter(): cursor row is out of range: {}", row) };
    }

    auto& line{ m_lines[row] };

    if (col < 0 || col > line.size() - 1) {
        throw std::out_of_range{ std::format("ERROR deleteCharacter(): cursor column is out of range: {}", col) };
    }

    m_lines.erase(m_lines.begin() + col);
}

const std::string& Buffer::getText(const int row) const
{
    if (row < 0 || row >= m_lines.size()) {
        throw std::out_of_range{ std::format("ERROR getText(): cursor row is out of range: {}", row) };
    }

    return m_lines[row];
}

std::size_t Buffer::lineCount() const
{
    return m_lines.size();
}
