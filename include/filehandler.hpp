#ifndef FILEHANDER_HPP
#define FILEHANDER_HPP

#include <string_view>

class FileHandler
{
    FileHandler() = default;
public:
    void open(std::string_view path);
    void save();
};

#endif

