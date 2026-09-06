#ifndef BUFFER_HPP
#define BUFFER_HPP

#include <utility>
#include <vector>
#include <string>

namespace Internal {

enum class CharacterType
{
    ALPHA,
    DIGIT,
    SPACE,
    SPECIAL
};

}

class Buffer
{
public:
    void setLines(std::vector<std::string> lines);

public:
    void insertNewLine(int row, int col);
    void insertCharacter(int row, int col, int c);
    void removeCharacter(int row, int col);
    void removeCharAt(int row, int col);
    void addCharAt(int row, int col, int c);
    void removeLine(int row);
    void mergeLines(int row, int col);

public:
    Internal::CharacterType characterType(int c) const noexcept;
    bool isSpace(int c) const noexcept;
    bool isAlpha(int c) const noexcept;
    bool isDigit(int c) const noexcept;
    bool isSpecial(int c) const noexcept;
    bool isSameType(int firstChar, int secondChar) const noexcept;

public:
    const std::vector<std::string>& lines() const;
    int lineCols(int row);
    const std::string& getText(int row) const;
    std::size_t lineCount() const;
    int firstCharacter(int row, int col) const;
    std::pair<int, int> nextWordPos(int row, int col) const noexcept;

private:
    std::vector<std::string> m_lines{};
};

#endif
