#include <InstructionDescriptor.hpp>


namespace SHD
{

    InstructionDescriptor::InstructionDescriptor() noexcept :
        opcode_def(0),
        opcode_mask(0),
        n_pos(0),
        m_pos(0),
        d_pos(0),
        i_pos(0),
        n_mask(0),
        m_mask(0),
        d_mask(0),
        i_mask(0),
        arg1_type(arg_type::NONE),
        arg2_type(arg_type::NONE)
    { }


    uint16_t InstructionDescriptor::getN(uint16_t const& opcode)
    {
        if(!isUseN())
            return 16;
        
        uint16_t ret = opcode & n_mask;
        ret >>= n_pos;
        return ret;
    }

    bool InstructionDescriptor::isUseN()
    {
        return n_mask != 0;
    }


    uint16_t InstructionDescriptor::getM(uint16_t const& opcode)
    {
        if(!isUseM())
            return 16;
        
        uint16_t ret = opcode & m_mask;
        ret >>= m_pos;
        return ret;
    }

    bool InstructionDescriptor::isUseM()
    {
        return m_mask != 0;
    }


    uint16_t InstructionDescriptor::getDisp(uint16_t const& opcode)
    {
        if(!isUseDisp())
            return 16;
        
        uint16_t ret = opcode & d_mask;
        ret >>= d_pos;
        return ret;
    }

    bool InstructionDescriptor::isUseDisp()
    {
        return d_mask != 0;
    }


    uint16_t InstructionDescriptor::getImm(uint16_t const& opcode)
    {
        if(!isUseImm())
            return 16;
        
        uint16_t ret = opcode & i_mask;
        ret >>= i_pos;
        return ret;
    }

    bool InstructionDescriptor::isUseImm()
    {
        return i_mask != 0;
    }

} /// namespace SHD
