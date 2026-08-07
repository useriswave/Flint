#ifndef MODETYPE_HPP
#define MODETYPE_HPP

#include <string_view>
#include <stdexcept>

namespace Mode
{
enum class Type
{
    normal,
    insert,
    visual
};

constexpr std::string_view toStr(const Mode::Type type)
{
    switch (type) {
        case Type::normal: return "NORMAL"; break;
        case Type::insert: return "INSERT"; break;
        case Type::visual: return "VISUAL"; break;
        default: throw std::runtime_error{ "Unknown mode type." };
    }
}



}

#endif
