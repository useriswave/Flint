#include "../include/buffer.hpp"

#include <stdexcept>
#include <format>

void Buffer::insertNewLine(const int row, const int col)
{
    if (row < 0 || row > m_lines.size()) {
        throw std::out_of_range{ std::format("ERROR Buffer::insertNewLine(): cursor row is out of range: {} out of {}", row, m_lines.size()) };
    }

    auto& line{ m_lines[row] };

    if (col < 0 || col > line.size()) {
        throw std::out_of_range{ std::format("ERROR Buffer::insertNewLine(): cursor column is out of range: {} out of {}", col, m_lines[row].length()) };
    }

    auto right{ line.substr(col, line.length() - 1) };
    line.erase(line.begin() + col, line.end());
    m_lines.insert(m_lines.begin() + row + 1, std::move(right));
}

void Buffer::insertCharacter(const int row, const int col, const char c)
{
    if (row < 0 || row > static_cast<int>(m_lines.size()) - 1) {
        throw std::out_of_range{ std::format("ERROR Buffer::insertCharacter(): cursor row is out of range: {} out of {}", row, m_lines.size()) };
    }

    auto& line{ m_lines[row] };

    if (col < 0 || col > line.size()) {
        throw std::out_of_range{ std::format("ERROR Buffer::insertCharacter(): cursor column is out of range: {} out of {}", col, m_lines[row].length()) };
    }

    line.insert(line.begin() + col, c);
}

void Buffer::deleteCharacter(const int row, const int col)
{
    if (row < 0 || row > m_lines.size() - 1) {
        throw std::out_of_range{ std::format("ERROR Buffer::deleteCharacter(): cursor row is out of range: {} out of {}", row, m_lines.size()) };
    }

    auto& line{ m_lines[row] };

    if (col < 0 || col > line.size() - 1) {
        throw std::out_of_range{ std::format("ERROR Buffer::deleteCharacter(): cursor column is out of range: {} out of {}", col, m_lines[row].length()) };
    }

    m_lines.erase(m_lines.begin() + col);
}

const std::string& Buffer::getText(const int row) const
{
    if (row < 0 || row >= m_lines.size()) {
        throw std::out_of_range{ std::format("ERROR Buffer::getText(): cursor row is out of range: {} out of {}", row, m_lines.size()) };
    }

    return m_lines[row];
}

std::size_t Buffer::lineCount() const
{
    return m_lines.size();
}

std::size_t Buffer::getRemainingLines(const int row) const
{
    return -1;
}
