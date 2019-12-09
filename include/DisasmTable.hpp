#ifndef H_DISASM_TABLE
#define H_DISASM_TABLE
#include <vector>
#include <string>
#include <cstdint>
#include <utils.hpp>
#include <InstructionDescriptor.hpp>
#include <Instruction.hpp>


namespace SHD
{

    using instn_dsc_array = std::vector<InstructionDescriptor>;

    class DisasmTable
    {
    public:

        DisasmTable() = default;


        size_t getTableSize() const noexcept { return m_instns.size(); }
        void reset() noexcept { m_instns.clear(); }
        void addInstns(instn_dsc_array tmp_instns);

    private:

        instn_dsc_array m_instns;

    }; /// class DisasmTable

} /// namespace SHD


#endif /// #ifndef H_DISASM_TABLE