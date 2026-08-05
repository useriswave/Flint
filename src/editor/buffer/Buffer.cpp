#include "editor/buffer/Buffer.hpp"

#include <stdexcept>
#include <format>

void Buffer::insertNewLine(const int row, const int col)
{
    if (row < 0 || row > m_lines.size()) {
        throw std::out_of_range{ std::format("ERROR Buffer::insertNewLine(): cursor row is out of range: {} out of {}", row, m_lines.size() - 1) };
    }

    auto& line{ m_lines[row] };

    if (col < 0 || col > line.size()) {
        throw std::out_of_range{ std::format("ERROR Buffer::insertNewLine(): cursor column is out of range: {} out of {}", col, m_lines[row].length()) };
    }

    auto right{ line.substr(col, line.length()) };
    line.erase(line.begin() + col, line.end());
    m_lines.insert(m_lines.begin() + row + 1, std::move(right));
}

void Buffer::insertCharacter(const int row, const int col, const int c)
{
    if (row < 0 || row > static_cast<int>(m_lines.size()) - 1) {
        throw std::out_of_range{ std::format("ERROR Buffer::insertCharacter(): cursor row is out of range: {} out of {}", row, m_lines.size() - 1) };
    }

    auto& line{ m_lines[row] };

    if (col < 0 || col > line.size()) {
        throw std::out_of_range{ std::format("ERROR Buffer::insertCharacter(): cursor column is out of range: {} out of {}", col, m_lines[row].length()) };
    }

    line.insert(line.begin() + col, c);
}

void Buffer::removeCharacter(const int row, const int col)
{
    if (row < 0 || row > m_lines.size() - 1) {
        throw std::out_of_range{ std::format("ERROR Buffer::removeCharacter(): cursor row is out of range: {} out of {}", row, m_lines.size() - 1) };
    }

    auto& line{ m_lines[row] };

    if (col < 0 || col > line.size()) {
        throw std::out_of_range{ std::format("ERROR Buffer::removeCharacter(): cursor column is out of range: {} out of {}", col, line.length()) };
    }

    line.erase(line.begin() + col);
}

void Buffer::removeLine(const int row)
{
    if (row < 0 || row > m_lines.size() - 1) {
        throw std::out_of_range{ std::format("ERROR Buffer::removeLine(): cursor row is out of range: {} out of {}", row, m_lines.size() - 1) };
    }

    m_lines.erase(m_lines.begin() + row);
}

void Buffer::mergeLines(const int row, const int col)
{
    if (row < 0 || row > m_lines.size() - 1) {
        throw std::out_of_range{ std::format("ERROR Buffer::mergeLines(): cursor row is out of range: {} out of {}", row, m_lines.size() - 1) };
    }

    auto& line{ m_lines[row] };

    if (col < 0 || col > line.length()) {
        throw std::out_of_range{ std::format("ERROR Buffer::mergeLines(): cursor column is out of range: {} out of {}", col, m_lines[row].length()) };
    }

    auto& prev{ m_lines[row-1] };
    const auto& current{ m_lines[row] };

    prev.append(current);
    m_lines.erase(m_lines.begin() + row);
}

std::optional<std::string> Buffer::previousLine(const int row)
{
    if (row < 0 || row > m_lines.size() - 1) {
        throw std::out_of_range{ std::format("ERROR Buffer::previousLine(): cursor row is out of range: {} out of {}", row, m_lines.size() - 1) };
    }

    return row == 0 ? std::nullopt : std::optional<std::string>(m_lines[row - 1]);
}

std::optional<std::string> Buffer::nextLine(int row)
{
    if (row < 0 || row > m_lines.size() - 1) {
        throw std::out_of_range{ std::format("ERROR Buffer::nextLine(): cursor row is out of range: {} out of {}", row, m_lines.size() - 1) };
    }

    return row == m_lines.size() - 1 ? std::nullopt : std::optional<std::string>(m_lines[row + 1]);
}

int Buffer::lineCols(const int row)
{
    if (row < 0 || row > m_lines.size() - 1) {
        throw std::out_of_range{ std::format("ERROR Buffer::lineCols(): cursor row is out of range: {} out of {}", row, m_lines.size() - 1) };
    }

    return static_cast<int>(m_lines[row].length()) - 1;
}

std::optional<int> Buffer::previousCols(const int row)
{
    const auto& line{ previousLine(row) };
    return line ? std::optional<int>(static_cast<int>(line->length()) - 1) : std::nullopt;
}

std::optional<int> Buffer::nextCols(const int row)
{
    const auto& line{ nextLine(row) };
    return line ? std::optional<int>(static_cast<int>(line->length()) - 1) : std::nullopt;
}

const std::vector<std::string>& Buffer::lines() const
{
    return m_lines;
}

const std::string& Buffer::getText(const int row) const
{
    if (row < 0 || row >= m_lines.size()) {
        throw std::out_of_range{ std::format("ERROR Buffer::getText(): cursor row is out of range: {} out of {}", row, m_lines.size() - 1) };
    }

    return m_lines[row];
}

std::size_t Buffer::lineCount() const
{
    return m_lines.size();
}
