#ifndef H_ARGUMENT
#define H_ARGUMENT
#include <cstdint>
#include <string>
#include <memory>
#include <vector>
#include <utils.hpp>
#include "Instruction.hpp"
#include "ArgumentDescriptor.hpp"


namespace SHD
{

    class Instruction;

    class Argument
    {
    public:

        Argument() = delete;
        Argument(std::shared_ptr<Instruction> instn, ArgumentDescriptor const& argDesc);

        ArgumentDescriptor getArgDesc() { return m_argDesc; }
        std::string toString();

    private:

        std::shared_ptr<Instruction> m_instn;
        ArgumentDescriptor m_argDesc;

    }; /// class Argument

} /// namespace SHD


#endif /// #ifndef H_ARGUMENT
