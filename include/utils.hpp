#ifndef H_UTILS
#define H_UTILS
#include <algorithm>
#include <string>
#include <iomanip>


namespace SHD
{

    template <typename T>
    constexpr T bigToLittleEdian (T value) noexcept
    {
        char* ptr = reinterpret_cast<char*>(&value);
        std::reverse(ptr, ptr + sizeof(T));
        return value;
    }

    template <typename T>
    constexpr T littleToBigEdian (T value) noexcept
    {
        return bigToLittleEdian(value);
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

    template<typename T>
    constexpr std::string toHexStr(T const& n)
    {
        std::stringstream ret;
        ret << std::hex << std::setfill('0');
        uint8_t const* data_ptr = reinterpret_cast<const uint8_t*>(&n);
        for(size_t i = 0; i < sizeof(T); i++)
        {
            ret << std::setw(2) << static_cast<int>(data_ptr[i]);
        }
        return ret.str();
    } /// constexpr std::string toHexStr(T const& n)

} /// namespace SHD


#endif /// #ifndef H_UTILS
