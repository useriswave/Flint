#ifndef BUFFER_HPP
#define BUFFER_HPP

#include <vector>
#include <string>
#include <optional>

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
    const std::vector<std::string>& lines() const;
    std::optional<std::string> previousLine(int row);
    std::optional<std::string> nextLine(int row);
    std::optional<int> previousCols(int row);
    std::optional<int> nextCols(int row);
    int lineCols(int row);
    bool lineEmpty(int row);
    const std::string& getText(int row) const;
    std::size_t lineCount() const;
    std::size_t firstCharacter(int row, int col) const;

private:
    std::vector<std::string> m_lines{};
};

#endif
