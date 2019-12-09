#ifndef H_INSTRUCTION
#define H_INSTRUCTION
#include <cstdint>
#include <InstructionDescriptor.hpp>
#include <DisasmTable.hpp>


namespace SHD
{
    
    class Instruction
    {
    public:

        Instruction() noexcept;
        Instruction(InstructionDescriptor const& tmp_instn_descriptor, uint16_t const& tmp_opcode);


        uint16_t getN();    // return n as number
        uint16_t getM();    // return m as number
        uint16_t getDisp(); // return disp as number
        uint16_t getImm();  // return imm as number
        bool isUseN();      // true if n_mask != 0
        bool isUseM();      // true if m_mask != 0
        bool isUseDisp();   // true if d_mask != 0
        bool isUseImm();    // true if i_mask != 0

    private:

        InstructionDescriptor m_descriptor; // definition of the instn
        uint16_t m_opcode; // opcode

    }; /// class Instruction

} /// namespace SHD


#endif /// #ifndef H_INSTRUCTION