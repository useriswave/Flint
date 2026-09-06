#include "editor/buffer/Buffer.hpp"

#include <stdexcept>
#include <format>
#include <utility>

void Buffer::setLines(std::vector<std::string> lines)
{
    if (!lines.empty()) {
        m_lines = std::move(lines);
    } else {
        m_lines.emplace_back("");
    }
}

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

int Buffer::lineCols(const int row)
{
    if (row < 0 || row > m_lines.size() - 1) {
        throw std::out_of_range{ std::format("ERROR Buffer::lineCols(): cursor row is out of range: {} out of {}", row, m_lines.size() - 1) };
    }

    return static_cast<int>(m_lines[row].length()) - 1;
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

std::size_t Buffer::firstCharacter(const int row, const int col) const
{
    const auto& line{ m_lines[row] };

    auto alphanumeric{ std::find_if(line.begin(), line.end(), [&](char c) {
        return std::isalnum(c);
    })};

    if (alphanumeric != line.end()) {
        auto index{ std::distance(line.begin(), alphanumeric) };
        return static_cast<std::size_t>(index);
    }

    return col;
}

Internal::CharacterType Buffer::characterType(int c) const noexcept
{
    using namespace Internal;

    if (std::isalpha(c)) {
        return CharacterType::ALPHA;
    }

    if (std::isdigit(c)) {
        return CharacterType::DIGIT;
    }

    if (std::isspace(c)) {
        return CharacterType::SPACE;
    }

    return CharacterType::SPECIAL;
}

bool Buffer::isSpace(int c) const
{
    return characterType(c) == Internal::CharacterType::SPACE;
}

bool Buffer::isAlpha(int c) const
{
    return characterType(c) == Internal::CharacterType::ALPHA;
}

bool Buffer::isDigit(int c) const
{
    return characterType(c) == Internal::CharacterType::DIGIT;
}

bool Buffer::isSpecial(int c) const
{
    return characterType(c) == Internal::CharacterType::SPECIAL;
}

bool Buffer::isSameType(int firstChar, int secondChar) const
{
    return characterType(firstChar) == characterType(secondChar);
}

std::pair<int, int> Buffer::nextWordPos(int row, int col) const noexcept
{
    const auto& line { m_lines[row] };

    for (auto i{ col }; i < line.size(); ++i) {
        if (isSpace(line[i])) {
            for (auto j{ i+1 }; j < line.size() - 1; ++j) {
                if (!isSpace(line[j])) {
                    return std::make_pair(row, j);
                }
            }
        }

        if (!isSameType(line[i], line[i+1]) && !isSpace(line[i+1])) {
            return std::make_pair(row, i+1);
        }
    }

    return std::make_pair(row, col);
}

