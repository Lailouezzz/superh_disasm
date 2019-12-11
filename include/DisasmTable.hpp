#ifndef H_DISASM_TABLE
#define H_DISASM_TABLE
#include <vector>
#include <string>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <spiritx3.hpp>
#include <utils.hpp>
#include "InstructionDescriptorParser.hpp"
#include "InstructionDescriptor.hpp"


namespace SHD
{

    using instn_dsc_array = std::vector<InstructionDescriptor>;

    class DisasmTable
    {
    public:

        DisasmTable() = default;


        size_t getTableSize() const noexcept { return m_instnsDesc.size(); }
        void reset() noexcept { m_instnsDesc.clear(); }
        void addInstns(instn_dsc_array tmp_instns);

        bool readFromFile(std::filesystem::path const& filePath);
        InstructionDescriptor matchInstn(uint16_t const& opcode) const;

    private:

        instn_dsc_array m_instnsDesc;

    }; /// class DisasmTable

} /// namespace SHD


#endif /// #ifndef H_DISASM_TABLE
