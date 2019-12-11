#include "Instruction.hpp"


namespace SHD
{

    Instruction::Instruction() noexcept :
        m_descriptor(),
        m_opcode(0)
    { }

    Instruction::Instruction(InstructionDescriptor const& tmp_instn_descriptor, uint16_t const& tmp_opcode) :
        m_descriptor(tmp_instn_descriptor),
        m_opcode(tmp_opcode)
    {
        // Check if opcode correspond to descriptor
        if((m_opcode & m_descriptor.opcode_mask) != m_descriptor.opcode_def)
        {
            // TODO : handle exception
        }
    }


    uint16_t Instruction::getN() const
    {
        return m_descriptor.getN(m_opcode);
    }

    bool Instruction::isUseN() const
    {
        return m_descriptor.isUseN();
    }


    uint16_t Instruction::getM() const
    {
        return m_descriptor.getM(m_opcode);
    }

    bool Instruction::isUseM() const
    {
        return m_descriptor.isUseM();
    }


    uint16_t Instruction::getDisp() const
    {
        return m_descriptor.getDisp(m_opcode);
    }

    bool Instruction::isUseDisp() const
    {
        return m_descriptor.isUseDisp();
    }


    uint16_t Instruction::getImm() const
    {
        return m_descriptor.getImm(m_opcode);
    }

    bool Instruction::isUseImm() const
    {
        return m_descriptor.isUseImm();
    }


    std::string Instruction::toString()
    {
        return m_descriptor.mnemonic_name;
    }

} /// namespace SHD
