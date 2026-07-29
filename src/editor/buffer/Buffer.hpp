#ifndef BUFFER_HPP
#define BUFFER_HPP

#include <vector>
#include <string>

class Buffer
{
public:
    Buffer()
    {
        m_lines.emplace_back("");
    }

public:
    void insertNewLine(int row, int col);
    void insertCharacter(int row, int col, char c);
    void deleteCharacter(int row, int col);

public:
    const std::vector<std::string>& lines() const;
    const std::string& getText(int row) const;
    std::size_t lineCount() const;
    std::size_t getRemainingLines(int row) const;

private:
    std::vector<std::string> m_lines{};
};

#endif
