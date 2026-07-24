#ifndef FILEHANDER_HPP
#define FILEHANDER_HPP

#include <string>
#include <vector>

class FileHandler
{
public:
    FileHandler() = default;

public:
    void openAndRead(const std::string& path, std::vector<std::string>& lines);
    void save(const std::vector<std::string>& lines);

private:
    std::string m_path{};
};

#endif

