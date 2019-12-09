#ifndef H_UTILS
#define H_UTILS
#include <algorithm>


namespace SHD
{

    template <typename T>
    constexpr T bigToLittleEdian (T value) noexcept
    {
        char* ptr = reinterpret_cast<char*>(&value);
        std::reverse(ptr, ptr + sizeof(T));
        return value;
    }

} /// namespace SHD

#endif /// #ifndef H_UTILS
