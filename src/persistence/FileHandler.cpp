#include "persistence/FileHandler.hpp"

#include <fstream>
#include <string>

void FileHandler::openAndRead(const std::string& path, std::vector<std::string>& lines)
{
    m_path = path;
    std::ifstream inf{ path };

    if (!inf) {
        throw std::runtime_error{ "ERROR: Couldn't open file to read from" };
    }

    std::string line{};

    while (getline(inf, line)) {
        lines.emplace_back(std::move(line));
    }
}

void FileHandler::save(const std::vector<std::string>& lines)
{
    std::ofstream outf{ m_path, std::ios::trunc };

    if (!outf) {
        throw std::runtime_error{ "ERROR: Couldn't open file to write to" };
    }

    for (const auto& line : lines) {
        outf << line;
    }
}
