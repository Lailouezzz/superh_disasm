#ifndef H_INSTRUCTION
#define H_INSTRUCTION
#include <cstdint>
#include <memory>
#include <vector>
#include "InstructionDescriptor.hpp"
#include "Argument.hpp"
#include "DisasmTable.hpp"


namespace SHD
{

    class Argument;
    
    class Instruction
    {
    public:

        Instruction() = delete;
        Instruction(InstructionDescriptor const& tmp_instn_descriptor, uint16_t const& tmp_opcode);


        InstructionDescriptor getDescriptor() const { return m_descriptor; }
        std::vector<Argument> getArgs() const { return m_args; }
        uint16_t getOpcode() const { return m_opcode; }
        std::string toString();

    private:

        InstructionDescriptor m_descriptor; // definition of the instn
        std::vector<Argument> m_args;
        uint16_t m_opcode; // opcode

        uint16_t getN() const;     // return n as number
        uint16_t getM() const;     // return m as number
        uint16_t getDisp() const;  // return disp as number
        uint16_t getImm() const;   // return imm as number
        bool isUseN() const;      // true if n_mask != 0
        bool isUseM() const;      // true if m_mask != 0
        bool isUseDisp() const;   // true if d_mask != 0
        bool isUseImm() const;    // true if i_mask != 0

        friend class Argument;

    }; /// class Instruction

} /// namespace SHD


#endif /// #ifndef H_INSTRUCTION
