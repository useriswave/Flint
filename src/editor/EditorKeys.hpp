#ifndef EDITORKEYS_HPP
#define EDITORKEYS_HPP

namespace EditorKeys
{
    constexpr int g_ESCAPE_KEY{ 27 };

    constexpr int ctrlKey(char key)
    {
        return key & 0x1f;
    }

#endif
}
