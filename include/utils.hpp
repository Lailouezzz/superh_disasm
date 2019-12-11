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

    template<typename T>
    constexpr uint8_t posLeastBit(T const& n)
    {
        if(n == 0)
        {
            // TODO : handle exception when n == 0
        }

        T selector = 1; // pos = 0
        for(uint8_t ret = 0; true; ret++)
        {
            if((selector & n) != 0) // if have a bit at pos return pos
            {
                return ret;
            }
            selector <<= 1;
        }
    }

} /// namespace SHD

#endif /// #ifndef H_UTILS
