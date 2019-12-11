#ifndef H_INSTRUCTION
#define H_INSTRUCTION
#include <cstdint>
#include "InstructionDescriptor.hpp"
#include "DisasmTable.hpp"


namespace SHD
{
    
    class Instruction
    {
    public:

        Instruction() noexcept;
        Instruction(InstructionDescriptor const& tmp_instn_descriptor, uint16_t const& tmp_opcode);


        uint16_t getN() const;     // return n as number
        uint16_t getM() const;     // return m as number
        uint16_t getDisp() const;  // return disp as number
        uint16_t getImm() const;   // return imm as number
        bool isUseN() const;       // true if n_mask != 0
        bool isUseM() const;       // true if m_mask != 0
        bool isUseDisp() const;    // true if d_mask != 0
        bool isUseImm() const;     // true if i_mask != 0

        InstructionDescriptor getDescriptor() const { return m_descriptor; }
        uint16_t getOpcode() const { return m_opcode; }

        std::string toString();

    private:

        InstructionDescriptor m_descriptor; // definition of the instn
        uint16_t m_opcode; // opcode

    }; /// class Instruction

} /// namespace SHD


#endif /// #ifndef H_INSTRUCTION
