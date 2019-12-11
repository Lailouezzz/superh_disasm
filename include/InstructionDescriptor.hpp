#ifndef H_INSTRUCTIONDESCRIPTOR
#define H_INSTRUCTIONDESCRIPTOR
#include <cstdint>
#include <string>
#include <vector>
#include "ArgumentDescriptor.hpp"


namespace SHD
{

    struct InstructionDescriptor
    {

        uint16_t opcode_def; // opcode_def & opcode_mask = opcode_def
        uint16_t opcode_mask; // 1 = constant ; 0 = arg

        uint8_t n_pos, m_pos, d_pos, i_pos; // arg position starting from the right ex : 011011101101nnnn n_pos = 0
                                            //                                           01101110mmmm1101 m_pos = 4
                                            //                                           if n isn't use n_pos = 16
        uint16_t n_mask, m_mask, d_mask, i_mask; // arg mask ex : if n isn't use n_mask = 0


        std::string mnemonic_name; // string mnemonic
        std::vector<ArgumentDescriptor> args; // arguments


        InstructionDescriptor() noexcept;


        uint16_t getN(uint16_t const& opcode) const;     // return n as number
        uint16_t getM(uint16_t const& opcode) const;     // return m as number
        uint16_t getDisp(uint16_t const& opcode) const;  // return disp as number
        uint16_t getImm(uint16_t const& opcode) const;   // return imm as number
        bool isUseN() const;      // true if n_mask != 0
        bool isUseM() const;      // true if m_mask != 0
        bool isUseDisp() const;   // true if d_mask != 0
        bool isUseImm() const;    // true if i_mask != 0

    }; /// struct instn_def

} /// namespace SHD


#endif /// #ifndef H_INSTRUCTIONDESCRIPTOR
