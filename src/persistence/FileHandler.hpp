#ifndef FILEHANDER_HPP
#define FILEHANDER_HPP

#include <string>
#include <vector>

class FileHandler
{
public:
    [[nodiscard]] std::vector<std::string> openAndRead(const std::string& path);
    void save(const std::vector<std::string>& lines);

private:
    std::string m_path{};
};

#endif

