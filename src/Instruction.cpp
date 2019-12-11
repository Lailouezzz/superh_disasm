#include <cstdint>
#include <memory>
#include <vector>
#include "InstructionDescriptor.hpp"
#include "Argument.hpp"
#include "DisasmTable.hpp"
#include "Instruction.hpp"


namespace SHD
{

    Instruction::Instruction(InstructionDescriptor const& tmp_instn_descriptor, uint16_t const& tmp_opcode) :
        m_descriptor(tmp_instn_descriptor),
        m_opcode(tmp_opcode)
    {
        // Check if opcode correspond to descriptor
        if((m_opcode & m_descriptor.opcode_mask) != m_descriptor.opcode_def)
        {
            // TODO : handle exception
        }

        for(uint8_t i = 0; i < m_descriptor.args.size(); i++)
        {
            m_args.push_back(Argument(std::make_shared<Instruction>(*this), m_descriptor.args[i]));
        }

    }


    std::string Instruction::toString()
    {
        std::string ret = m_descriptor.mnemonic_name;
        ret += '\t';
        if(m_args.size() >= 1)
            ret += m_args[0].toString();
        if(m_args.size() >= 2)
        {
            ret += ", ";
            ret += m_args[1].toString();
        }
        return ret;
    }


    uint16_t Instruction::getN() const
    {
        return m_descriptor.getN(m_opcode);
    }
    uint16_t Instruction::getM() const
    {
        return m_descriptor.getM(m_opcode);
    }
    uint16_t Instruction::getDisp() const
    {
        return m_descriptor.getDisp(m_opcode);
    }
    uint16_t Instruction::getImm() const
    {
        return m_descriptor.getImm(m_opcode);
    }

    bool Instruction::isUseN() const
    {
        return m_descriptor.isUseN();
    }
    bool Instruction::isUseM() const
    {
        return m_descriptor.isUseM();
    }
    bool Instruction::isUseDisp() const
    {
        return m_descriptor.isUseDisp();
    }
    bool Instruction::isUseImm() const
    {
        return m_descriptor.isUseImm();
    }

} /// namespace SHD
