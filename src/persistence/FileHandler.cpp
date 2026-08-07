#include "persistence/FileHandler.hpp"

#include <fstream>
#include <string>
#include <vector>
#include <iostream>

std::vector<std::string> FileHandler::openAndRead(const std::string& path)
{
    std::ifstream inf{ path };

    if (!inf) {
        throw std::runtime_error{ "ERROR: Couldn't open file to read from" };
    }

    m_path = std::move(path);
    std::string line{};
    std::vector<std::string> lines{};

    while (getline(inf, line)) {
        lines.emplace_back(std::move(line));
    }

    return lines;
}

void FileHandler::save(const std::vector<std::string>& lines)
{
    std::ofstream outf{ m_path, std::ios::trunc };

    if (!outf) {
        throw std::runtime_error{ "ERROR: Couldn't open file to write to" };
    }

    for (const auto& line : lines) {
        outf << line << '\n';
    }
}
