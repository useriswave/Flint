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
    const std::string& getText(int row) const;
    std::size_t lineCount() const;

private:
    std::vector<std::string> m_lines{};
};
