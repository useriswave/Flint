#ifndef MODETYPE_HPP
#define MODETYPE_HPP

#include <string_view>
#include <utility>

namespace Mode {

enum class Type
{
    normal,
    insert,
    visual
};

constexpr std::string_view toStr(const Mode::Type type)
{
    switch (type) {
        case Type::normal: return "NORMAL";
        case Type::insert: return "INSERT";
        case Type::visual: return "VISUAL";
    }

    std::unreachable();
}

}

#endif
